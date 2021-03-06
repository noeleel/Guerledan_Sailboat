cmake_minimum_required(VERSION 3.2)
project(UxVCtrl)

if(NOT(PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR))
	message(WARNING "Please set the CMake build folder to the same as the source folder...")
endif()

if(WIN32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		# 64 bits
		message(WARNING "Only 32 bit version of CMake is supported on Windows 64 bit...")
	elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
		# 32 bits
	endif()
endif()

option(ENABLE_AUTO_DOWNLOAD "ENABLE_AUTO_DOWNLOAD" ON)
if(WIN32)
else()
#	option(ENABLE_AUTO_SUDO "ENABLE_AUTO_SUDO" ON)
endif()
option(ENABLE_STATIC "ENABLE_STATIC" OFF)

if(CMAKE_BUILD_TOOL MATCHES "(msdev|devenv|nmake)")
    add_definitions(/W2)
endif()

if(ENABLE_AUTO_DOWNLOAD)
	if(WIN32)
		message(STATUS "If behind a proxy, you might need to type e.g. \"set https_proxy=192.168.1.17:8080\" in the same terminal before running cmake-gui/cmake to configure the proxy settings...")
	else()
		message(STATUS "If behind a proxy, you might need to type e.g. \"export https_proxy=192.168.1.17:8080\" in the same terminal before running cmake-gui/cmake to configure the proxy settings...")
	endif()
	message(STATUS "If some prerequisites cannot be downloaded and installed automatically, try to install them manually and change ENABLE_AUTO_DOWNLOAD option in cmake-gui/cmake...")
endif()

if(ENABLE_AUTO_DOWNLOAD)
	if(NOT EXISTS "/usr/include/eigen3/")
		message(STATUS "Downloading Eigen3...")
		execute_process(COMMAND sh -c "sudo apt install libeigen3-dev")
		execute_process(COMMAND sh -c "sudo ln -sf /usr/include/eigen3/Eigen Eigen")
	endif()
	if(NOT EXISTS "${PROJECT_SOURCE_DIR}/../OSUtils")
		message(STATUS "Downloading OSUtils...")
		file(DOWNLOAD "https://github.com/ENSTABretagneRobotics/OSUtils/archive/master.zip" "${PROJECT_SOURCE_DIR}/../OSUtils.zip")
		execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/../OSUtils.zip")
		execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/OSUtils-master" "${PROJECT_SOURCE_DIR}/../OSUtils")
		execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/../OSUtils.zip")
	endif()
	if(NOT EXISTS "${PROJECT_SOURCE_DIR}/../Extensions")
		message(STATUS "Downloading Extensions...")
		file(DOWNLOAD "https://github.com/ENSTABretagneRobotics/Extensions/archive/master.zip" "${PROJECT_SOURCE_DIR}/../Extensions.zip")
		execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/../Extensions.zip")
		execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/Extensions-master" "${PROJECT_SOURCE_DIR}/../Extensions")
		execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/../Extensions.zip")
	endif()
	if(NOT EXISTS "${PROJECT_SOURCE_DIR}/../interval")
		message(STATUS "Downloading interval...")
		file(DOWNLOAD "https://github.com/ENSTABretagneRobotics/interval/archive/master.zip" "${PROJECT_SOURCE_DIR}/../interval.zip")
		execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/../interval.zip")
		execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/interval-master" "${PROJECT_SOURCE_DIR}/../interval")
		execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/../interval.zip")
	endif()
	if(NOT EXISTS "${PROJECT_SOURCE_DIR}/../matrix_lib")
		message(STATUS "Downloading matrix_lib...")
		file(DOWNLOAD "https://github.com/ENSTABretagneRobotics/matrix_lib/archive/master.zip" "${PROJECT_SOURCE_DIR}/../matrix_lib.zip")
		execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/../matrix_lib.zip")
		execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/matrix_lib-master" "${PROJECT_SOURCE_DIR}/../matrix_lib")
		execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/../matrix_lib.zip")
	endif()
endif()

if(WIN32)
	if(MSVC)
		if(MSVC_TOOLSET_VERSION EQUAL 80)
		set(VCX "vc8")
		elseif(MSVC_TOOLSET_VERSION EQUAL 90)
		set(VCX "vc9")
		elseif(MSVC_TOOLSET_VERSION EQUAL 100)
		set(VCX "vc10")
		elseif(MSVC_TOOLSET_VERSION EQUAL 110)
		set(VCX "vc11")
		elseif(MSVC_TOOLSET_VERSION EQUAL 120)
		set(VCX "vc12")
		elseif(MSVC_TOOLSET_VERSION EQUAL 140)
		set(VCX "vc14")
		elseif(MSVC_TOOLSET_VERSION EQUAL 141)
		set(VCX "vc15")
		else()
		set(VCX "vc15")
		endif()
	endif()
endif()

add_executable(UxVCtrl Observer.cpp NMEAInterface.cpp Main.cpp Variables.cpp WhichWay.cpp Security.cpp OurController.cpp PositionEstimator.cpp DetectBall.cpp Globals.cpp Navigation.cpp Controller.cpp Config.cpp Computations.cpp Commands.cpp Hardware/ublox.cpp Hardware/RS232Port.cpp Hardware/RazorAHRS.cpp Hardware/Pololu.cpp Hardware/NMEADevice.cpp Hardware/gpControl.cpp ../interval/imatrix.cpp ../interval/rmatrix.cpp ../interval/box.cpp ../interval/interval.cpp ../interval/iboolean.cpp ../OSUtils/OSTimer.c ../OSUtils/OSTime.c ../OSUtils/OSThread.c ../OSUtils/OSSem.c ../OSUtils/OSNet.c ../OSUtils/OSMisc.c ../OSUtils/OSEv.c ../OSUtils/OSCriticalSection.c ../OSUtils/OSCore.c ../OSUtils/OSComputerRS232Port.c)

if(WIN32)
	option(ENABLE_CVKINECT2SDKHOOK "ENABLE_CVKINECT2SDKHOOK" OFF)
	option(ENABLE_CVCLEYESDKHOOK "ENABLE_CVCLEYESDKHOOK" OFF)
endif()
option(ENABLE_BLUEVIEW_SUPPORT "ENABLE_BLUEVIEW_SUPPORT" OFF)
option(ENABLE_MAVLINK_SUPPORT "ENABLE_MAVLINK_SUPPORT" OFF) 
option(ENABLE_LABJACK_SUPPORT "ENABLE_LABJACK_SUPPORT" OFF) 
option(ENABLE_LIBMODBUS_SUPPORT "ENABLE_LIBMODBUS_SUPPORT" OFF) 
option(ENABLE_SBG_SUPPORT "ENABLE_SBG_SUPPORT" OFF) 
option(DISABLE_OPENCV_SUPPORT "DISABLE_OPENCV_SUPPORT" ON) 
option(DISABLE_OPENCV_SUPPORT "USE_FFMPEG_VIDEO" OFF) 

option(ENABLE_BUILD_OPTIMIZATION_SAILBOAT "ENABLE_BUILD_OPTIMIZATION_SAILBOAT" OFF)
option(OPENCV2413 "OPENCV2413" ON)
option(OPENCV320 "OPENCV320" OFF)
option(OPENCV342 "OPENCV342" OFF)
option(USE_OPENCV_HIGHGUI_CPP_API "USE_OPENCV_HIGHGUI_CPP_API" OFF)
option(USE_ALTERNATE_RECORDING "USE_ALTERNATE_RECORDING" OFF)
option(DISABLE_AIS_SUPPORT "DISABLE_AIS_SUPPORT" OFF)
option(USE_FFMPEG_VIDEO "USE_FFMPEG_VIDEO" OFF)

if(ENABLE_BUILD_OPTIMIZATION_SAILBOAT)
	add_definitions(-DENABLE_BUILD_OPTIMIZATION_SAILBOAT)
endif()

if(ENABLE_BLUEVIEW_SUPPORT)
	add_definitions(-DENABLE_BLUEVIEW_SUPPORT)
	target_sources(UxVCtrl PUBLIC Hardware/BlueView.cpp) 
	if(WIN32)
		add_definitions(-DBVTSDK_VERSION=4)
		set(BVTSDK_DIR "$ENV{ProgramFiles}/BlueView/bvtsdk")
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "${BVTSDK_DIR}/include/bvt_sdk.h")
				message(STATUS "Downloading BlueView...")
				file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/bv.zip" "${PROJECT_SOURCE_DIR}/bv.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/bv.zip")
				execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory "$ENV{ProgramFiles}/BlueView")
				execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/bv/bv_4.2.0.9526_win32/bvtsdk" "${BVTSDK_DIR}")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_SOURCE_DIR}/bv")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/bv.zip")
				file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/cmake_extra_tools.zip" "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/cmake_extra_tools" COMMAND cmd /c pathman /as "$ENV{ProgramFiles}\\BlueView\\bvtsdk\\x86\\vc15\\bin")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_SOURCE_DIR}/cmake_extra_tools")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
			endif()
		endif()
		include_directories("${BVTSDK_DIR}/include")
		if(MSVC)
			set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"${BVTSDK_DIR}/x86/vc15/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl bvtsdk4.lib)
		else()
			set(CMAKE_EXE_LINKER_FLAGS "-L:\"${BVTSDK_DIR}/x86/vc15/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl bvtsdk4)
		endif()
	else()
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "/usr/local/include/bvt_sdk.h")
				message(STATUS "Downloading BlueView...")
				file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/bv.zip" "${PROJECT_SOURCE_DIR}/bv.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/bv.zip")
				if("${CMAKE_SIZEOF_VOID_P}" EQUAL "4")
					execute_process(COMMAND sh -c "sudo cp -R \"${PROJECT_SOURCE_DIR}/bv/bv_3.5.0.5861_Ubuntu32_16.04.2/bvtsdk/include/*\" /usr/local/include/")
					execute_process(COMMAND sh -c "sudo cp -R \"${PROJECT_SOURCE_DIR}/bv/bv_3.5.0.5861_Ubuntu32_16.04.2/bvtsdk/lib/*\" /usr/local/lib/")
				else()
					execute_process(COMMAND sh -c "sudo cp -R \"${PROJECT_SOURCE_DIR}/bv/bv_3.5.0.6257_Ubuntu64_16.04.2/bvtsdk/include/*\" /usr/local/include/")
					execute_process(COMMAND sh -c "sudo cp -R \"${PROJECT_SOURCE_DIR}/bv/bv_3.5.0.6257_Ubuntu64_16.04.2/bvtsdk/lib/*\" /usr/local/lib/")
				endif()
				execute_process(COMMAND sh -c "sudo rm -f /usr/local/lib/libbvtsdk.so /usr/local/lib/libbvtsdk.so.3 /usr/local/lib/libbvtsdk.so.3.5")
				execute_process(COMMAND sh -c "sudo ln -s /usr/local/lib/libbvtsdk.so.3.5.0 /usr/local/lib/libbvtsdk.so")
				execute_process(COMMAND sh -c "sudo ln -s /usr/local/lib/libbvtsdk.so.3.5.0 /usr/local/lib/libbvtsdk.so.3")
				execute_process(COMMAND sh -c "sudo ln -s /usr/local/lib/libbvtsdk.so.3.5.0 /usr/local/lib/libbvtsdk.so.3.5")
				execute_process(COMMAND sh -c "sudo ln -s /usr/local/lib/libbv* /usr/lib/")
				execute_process(COMMAND sh -c "sudo chmod -R 777 /usr/local/include/bv*")
				execute_process(COMMAND sh -c "sudo chmod -R 777 /usr/local/lib/libbv*")
				execute_process(COMMAND sh -c "sudo chmod -R 777 /usr/lib/libbv*")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_SOURCE_DIR}/bv")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/bv.zip")
			endif()
		endif()
		if(ENABLE_STATIC)
			target_link_libraries(UxVCtrl -static bvtsdk)
		else()
			target_link_libraries(UxVCtrl bvtsdk)
		endif()
	endif()
else()
	if(WIN32)
		if(EXISTS "$ENV{ProgramFiles}/BlueView/bvtsdk/include/bvt_sdk.h")
			message(STATUS "BlueView has been detected, check ENABLE_BLUEVIEW_SUPPORT option to try to use it...")
		endif()
	else()
		if(EXISTS "/usr/local/include/bvt_sdk.h")
			message(STATUS "BlueView has been detected, check ENABLE_BLUEVIEW_SUPPORT option to try to use it...")
		endif()
	endif()
endif()

if(ENABLE_CVKINECT2SDKHOOK)
	add_definitions(-DENABLE_CVKINECT2SDKHOOK)
	include_directories("$ENV{KINECTSDK20_DIR}/inc")
	if(MSVC)
		set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{KINECTSDK20_DIR}/Lib/x86\" ${CMAKE_EXE_LINKER_FLAGS}")
		target_link_libraries(UxVCtrl Kinect20.lib)
	else()
		set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{KINECTSDK20_DIR}/Lib/x86\" ${CMAKE_EXE_LINKER_FLAGS}")
		target_link_libraries(UxVCtrl Kinect20)
	endif()
endif()

if(ENABLE_CVCLEYESDKHOOK)
	add_definitions(-DENABLE_CVCLEYESDKHOOK)
	include_directories("$ENV{CLEYESDK_DIR}/Include")
	if(MSVC)
		set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{CLEYESDK_DIR}/Lib\" ${CMAKE_EXE_LINKER_FLAGS}")
		target_link_libraries(UxVCtrl CLEyeMulticam.lib)
	else()
		set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{CLEYESDK_DIR}/Lib\" ${CMAKE_EXE_LINKER_FLAGS}")
		target_link_libraries(UxVCtrl CLEyeMulticam)
	endif()
endif()

if(ENABLE_MAVLINK_SUPPORT)
	add_definitions(-DENABLE_MAVLINK_SUPPORT)
	target_sources(UxVCtrl PUBLIC MAVLinkInterface.cpp Hardware/MAVLinkDevice.cpp) 
	if(WIN32)
		set(MAVLINK_SDK_DIR "$ENV{ProgramFiles}/MAVLinkSDK")
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "$ENV{ProgramFiles}/MAVLinkSDK/mavlink/common/mavlink.h")
				message(STATUS "Downloading mavlink...")
				file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/MAVLinkSDK.zip" "${PROJECT_SOURCE_DIR}/MAVLinkSDK.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/MAVLinkSDK.zip")
				execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/MAVLinkSDK" "${MAVLINK_SDK_DIR}")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/MAVLinkSDK.zip")
			endif()
		endif()
		include_directories("${MAVLINK_SDK_DIR}")
	else()
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "/usr/local/include/mavlink/common/mavlink.h")
				message(STATUS "Downloading mavlink...")
				file(DOWNLOAD "https://github.com/mavlink/c_library_v2/archive/master.zip" "${PROJECT_SOURCE_DIR}/master.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/master.zip")
				execute_process(COMMAND sh -c "sudo mv -f \"${PROJECT_SOURCE_DIR}/c_library_v2-master\" /usr/local/include/mavlink")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/master.zip")
			endif()
		endif()
	endif()
else()
	if(WIN32)
		if(EXISTS "$ENV{ProgramFiles}/MAVLinkSDK/mavlink/common/mavlink.h")
			message(STATUS "mavlink has been detected, check ENABLE_MAVLINK_SUPPORT option to try to use it...")
		endif()
	else()
		if(EXISTS "/usr/local/include/mavlink/common/mavlink.h")
			message(STATUS "mavlink has been detected, check ENABLE_MAVLINK_SUPPORT option to try to use it...")
		endif()
	endif()
endif()

if(ENABLE_LABJACK_SUPPORT)
	add_definitions(-DENABLE_LABJACK_SUPPORT)
	include_directories("${PROJECT_SOURCE_DIR}/../Extensions/Devices/LabjackUtils/liblabjackusb")
	include_directories("${PROJECT_SOURCE_DIR}/../Extensions/Devices/LabjackUtils/UE9Utils")
	include_directories("$ENV{ProgramFiles}/LabJack/Drivers")
	if(WIN32)
		target_sources(UxVCtrl PUBLIC Hardware/UE9A.cpp ../Extensions/Devices/LabjackUtils/UE9Utils/UE9Cfg.c ../Extensions/Devices/LabjackUtils/UE9Utils/UE9Core.c)
		set_source_files_properties( ../Extensions/Devices/LabjackUtils/UE9Utils/UE9Cfg.c ../Extensions/Devices/LabjackUtils/UE9Utils/UE9Core.c PROPERTIES LANGUAGE CXX)
		if(MSVC)
			set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{ProgramFiles}/LabJack/Drivers\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl labjackud.lib)
		else()
			set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{ProgramFiles}/LabJack/Drivers\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl labjackud)
		endif()
	else()
		target_sources(UxVCtrl PUBLIC Hardware/UE9A.cpp ../Extensions/Devices/LabjackUtils/UE9Utils/UE9Cfg.c ../Extensions/Devices/LabjackUtils/UE9Utils/UE9Core.c ../Extensions/Devices/LabjackUtils/UE9Utils/ue9.c ../Extensions/Devices/LabjackUtils/liblabjackusb/labjackusb.c)
	endif()
endif()

if(ENABLE_LIBMODBUS_SUPPORT)
	add_definitions(-DENABLE_LIBMODBUS_SUPPORT)
	target_sources(UxVCtrl PUBLIC Hardware/CISCREA.cpp) 
	if(WIN32)
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "$ENV{ProgramFiles}/libmodbus-3.0.6-msvc/include/modbus/modbus.h")
				message(STATUS "Downloading libmodbus...")
				file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/libmodbus-3.0.6-msvc.zip" "${PROJECT_SOURCE_DIR}/libmodbus-3.0.6-msvc.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/libmodbus-3.0.6-msvc.zip")
				execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/libmodbus-3.0.6-msvc" "$ENV{ProgramFiles}/libmodbus-3.0.6-msvc")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/libmodbus-3.0.6-msvc.zip")
			endif()
		endif()
		include_directories("$ENV{ProgramFiles}/libmodbus-3.0.6-msvc/include")
		if(MSVC)
			set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{ProgramFiles}/libmodbus-3.0.6-msvc/x86/${VCX}/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl debug libmodbus-3.0.6-msvcd.lib)
			target_link_libraries(UxVCtrl optimized libmodbus-3.0.6-msvc.lib)
		else()
			set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{ProgramFiles}/libmodbus-3.0.6-msvc/x86/vc9/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl libmodbus-3.0.6-msvc)
		endif()
	else()
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "/usr/include/modbus/modbus.h")
				message(STATUS "Trying to download libmodbus, run \"sudo apt-get update\" before if needed...")
				execute_process(COMMAND sh -c "sudo apt-get -y install libmodbus-dev")
			endif()
		endif()
		if(ENABLE_STATIC)
			target_link_libraries(UxVCtrl -static modbus)
		else()
			target_link_libraries(UxVCtrl modbus)
		endif()
	endif()
else()
	if(WIN32)
		if(EXISTS "$ENV{ProgramFiles}/libmodbus-3.0.6-msvc/include/modbus/modbus.h")
			message(STATUS "modbus has been detected, check ENABLE_LIBMODBUS_SUPPORT option to try to use it...")
		endif()
	else()
		if(EXISTS "/usr/include/modbus/modbus.h")
			message(STATUS "modbus has been detected, check ENABLE_LIBMODBUS_SUPPORT option to try to use it...")
		endif()
	endif()
endif()

if(ENABLE_SBG_SUPPORT)
	add_definitions(-DENABLE_SBG_SUPPORT)
	target_sources(UxVCtrl PUBLIC Hardware/SBG.cpp) 
	if(WIN32)
		set(SBG_SDK_DIR "$ENV{ProgramFiles}/SBG Systems/Inertial SDK/Software Development/sbgECom")
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "${SBG_SDK_DIR}/common/sbgCommon.h")
				message(STATUS "Downloading SBG...")
				file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/SBG%20Systems.zip" "${PROJECT_SOURCE_DIR}/SBG Systems.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/SBG Systems.zip")
				execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/SBG Systems" "$ENV{ProgramFiles}/SBG Systems")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/SBG Systems.zip")
			endif()
		endif()
		include_directories("${SBG_SDK_DIR}/common")
		include_directories("${SBG_SDK_DIR}/src")
		if(MSVC)
			set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"${SBG_SDK_DIR}/x86/${VCX}/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl debug sbgEComd.lib)
			target_link_libraries(UxVCtrl optimized sbgECom.lib)
		else()
			set(CMAKE_EXE_LINKER_FLAGS "-L:\"${SBG_SDK_DIR}/x86/vc9/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl sbgECom)
		endif()
	else()
		if(ENABLE_AUTO_DOWNLOAD)
			if(NOT EXISTS "/usr/local/include/sbgECom/common/sbgCommon.h")
				message(STATUS "Downloading SBG...")
				file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/SBG%20Systems.zip" "${PROJECT_SOURCE_DIR}/SBG Systems.zip")
				execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/SBG Systems.zip")
				execute_process(COMMAND sh -c "cd \"${PROJECT_SOURCE_DIR}/SBG Systems/Inertial SDK/Software Development/sbgECom/projects/unix\" && cmake . && make")
				execute_process(COMMAND sh -c "sudo mkdir -p /usr/local/include/sbgECom")
				execute_process(COMMAND sh -c "sudo mv -f \"${PROJECT_SOURCE_DIR}/SBG Systems/Inertial SDK/Software Development/sbgECom/src/\" /usr/local/include/sbgECom/src")
				execute_process(COMMAND sh -c "sudo mv -f \"${PROJECT_SOURCE_DIR}/SBG Systems/Inertial SDK/Software Development/sbgECom/common/\" /usr/local/include/sbgECom/common")
				execute_process(COMMAND sh -c "sudo mv -f \"${PROJECT_SOURCE_DIR}/SBG Systems/Inertial SDK/Software Development/sbgECom/bin/libsbgECom.a\" /usr/local/lib/libsbgECom.a")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/SBG Systems")
				execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/SBG Systems.zip")
			endif()
		endif()
		include_directories("/usr/local/include/sbgECom/common")
		include_directories("/usr/local/include/sbgECom/src")
		if(ENABLE_STATIC)
			target_link_libraries(UxVCtrl -static sbgECom)
		else()
			target_link_libraries(UxVCtrl sbgECom)
		endif()
	endif()
else()
	if(WIN32)
		if(EXISTS "$ENV{ProgramFiles}/SBG Systems/Inertial SDK/Software Development/sbgECom/common/sbgCommon.h")
			message(STATUS "SBG has been detected, check ENABLE_SBG_SUPPORT option to try to use it...")
		endif()
	else()
		if(EXISTS "/usr/local/include/sbgECom/common/sbgCommon.h")
			message(STATUS "SBG has been detected, check ENABLE_SBG_SUPPORT option to try to use it...")
		endif()
	endif()
endif()

if(DISABLE_OPENCV_SUPPORT)
	add_definitions(-DDISABLE_OPENCV_SUPPORT)
	if(WIN32)
		if(MSVC)
			if(EXISTS "$ENV{SystemDrive}/OpenCV2.4.13/x86/${VCX}/lib/opencv_core2413.lib")
				message(STATUS "OpenCV2.4.13 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV2413 options to try to use it...")
			elseif(EXISTS "$ENV{SystemDrive}/OpenCV3.2.0/x86/${VCX}/lib/opencv_world320.lib")
				message(STATUS "OpenCV3.2.0 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV320 options to try to use it...")
			elseif(EXISTS "$ENV{SystemDrive}/OpenCV3.4.2/x86/${VCX}/lib/opencv_world342.lib")
				message(STATUS "OpenCV3.4.2 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV342 options to try to use it...")
			endif()
		else()
			if(EXISTS "$ENV{SystemDrive}/OpenCV2.4.13/x86/mingw/lib/opencv_core2413.lib")
				message(STATUS "OpenCV2.4.13 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV2413 options to try to use it...")
			elseif(EXISTS "$ENV{SystemDrive}/OpenCV3.2.0/x86/mingw/lib/opencv_world320.lib")
				message(STATUS "OpenCV3.2.0 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV320 options to try to use it...")
			elseif(EXISTS "$ENV{SystemDrive}/OpenCV3.4.2/x86/mingw/lib/opencv_world342.lib")
				message(STATUS "OpenCV3.4.2 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV342 options to try to use it...")
			endif()
		endif()
	else()
		if(EXISTS "/usr/include/opencv/cv.h")
			if("${CMAKE_SIZEOF_VOID_P}" EQUAL "4")
				if(EXISTS "/usr/lib/i386-linux-gnu/libopencv_core.so.2.4")
					message(STATUS "OpenCV2.4 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV2413 to try to use it...")
				elseif(EXISTS "/usr/lib/i386-linux-gnu/libopencv_core.so.3.2")
					message(STATUS "OpenCV3.2 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV320 options to try to use it...")
				elseif(EXISTS "/usr/lib/i386-linux-gnu/libopencv_core.so.3.4")
					message(STATUS "OpenCV3.4 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV342 options to try to use it...")
				endif()
			else()
				if(EXISTS "/usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4")
					message(STATUS "OpenCV2.4 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV2413 to try to use it...")
				elseif(EXISTS "/usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2")
					message(STATUS "OpenCV3.2 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV320 options to try to use it...")
				elseif(EXISTS "/usr/lib/x86_64-linux-gnu/libopencv_core.so.3.4")
					message(STATUS "OpenCV3.4 has been detected, check DISABLE_OPENCV_SUPPORT and OPENCV342 options to try to use it...")
				endif()
			endif()
		endif()
	endif()
else()
	if(ENABLE_BUILD_OPTIMIZATION_SAILBOAT)
		target_sources(UxVCtrl PUBLIC Variables.cpp Ball.cpp OpenCVGUI.cpp VideoRecord.cpp Hardware/Video.cpp)
	else()
		target_sources(UxVCtrl PUBLIC Variables.cpp Ball.cpp ExternalVisualLocalization.cpp MissingWorker.cpp OpenCVGUI.cpp Pinger.cpp Pipeline.cpp SurfaceVisualObstacle.cpp VisualObstacle.cpp VideoRecord.cpp Wall.cpp Hardware/Video.cpp)
	endif()
	if(WIN32)
	else()
		# On Ubuntu, we need to know which version of OpenCV is available...
		if("${CMAKE_SIZEOF_VOID_P}" EQUAL "4")
			if(ENABLE_AUTO_DOWNLOAD)
				if(NOT EXISTS "/usr/include/opencv/cv.h")
					message(STATUS "Trying to download OpenCV, run \"sudo apt-get update\" before if needed...")
					execute_process(COMMAND sh -c "sudo apt-get -y install libopencv-dev")
				endif()
			endif()
			if(OPENCV2413)
				if(NOT EXISTS "/usr/lib/i386-linux-gnu/libopencv_core.so.2.4")			
					message(WARNING "In case of problems, check if OPENCV320 or OPENCV342 option should be enabled instead of OPENCV2413...")
				endif()
			elseif(OPENCV320)
				if(NOT EXISTS "/usr/lib/i386-linux-gnu/libopencv_core.so.3.2")			
					message(WARNING "In case of problems, check if OPENCV2413 or OPENCV342 option should be enabled instead of OPENCV320...")
				endif()
			elseif(OPENCV342)
				if(NOT EXISTS "/usr/lib/i386-linux-gnu/libopencv_core.so.3.4")			
					message(WARNING "In case of problems, check if OPENCV2413 or OPENCV320 option should be enabled instead of OPENCV342...")
				endif()
			endif()
		else()
			if(ENABLE_AUTO_DOWNLOAD)
				if(NOT EXISTS "/usr/include/opencv/cv.h")
					message(STATUS "Trying to download OpenCV, run \"sudo apt-get update\" before if needed...")
					execute_process(COMMAND sh -c "sudo apt-get -y install libopencv-dev")
				endif()
			endif()
			if(OPENCV2413)
				if(NOT EXISTS "/usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4")			
					message(WARNING "In case of problems, check if OPENCV320 or OPENCV342 option should be enabled instead of OPENCV2413...")
				endif()
			elseif(OPENCV320)
				if(NOT EXISTS "/usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2")			
					message(WARNING "In case of problems, check if OPENCV2413 or OPENCV342 option should be enabled instead of OPENCV320...")
				endif()
			elseif(OPENCV342)
				if(NOT EXISTS "/usr/lib/x86_64-linux-gnu/libopencv_core.so.3.4")			
					message(WARNING "In case of problems, check if OPENCV2413 or OPENCV320 option should be enabled instead of OPENCV342...")
				endif()
			endif()
		endif()
	endif()
	if(OPENCV2413)
		add_definitions(-DOPENCV2413)
		if(WIN32)
			if(ENABLE_AUTO_DOWNLOAD)
				if(NOT EXISTS "$ENV{SystemDrive}/OpenCV2.4.13/x86/${VCX}/lib/opencv_core2413.lib")
					message(STATUS "Downloading OpenCV2.4.13...")
					file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/OpenCV2.4.13.zip" "${PROJECT_SOURCE_DIR}/OpenCV2.4.13.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/OpenCV2.4.13.zip")
					execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/OpenCV2.4.13" "$ENV{SystemDrive}/OpenCV2.4.13")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/OpenCV2.4.13.zip")
					file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/cmake_extra_tools.zip" "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/cmake_extra_tools" COMMAND cmd /c pathman /as "$ENV{SystemDrive}\\OpenCV2.4.13\\x86\\${VCX}\\bin")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_SOURCE_DIR}/cmake_extra_tools")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
				endif()
			endif()
			include_directories("$ENV{SystemDrive}/OpenCV2.4.13/include")
			if(MSVC)
				set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{SystemDrive}/OpenCV2.4.13/x86/${VCX}/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
				target_link_libraries(UxVCtrl debug opencv_core2413d.lib opencv_imgproc2413d.lib opencv_highgui2413d.lib)
				target_link_libraries(UxVCtrl optimized opencv_core2413.lib opencv_imgproc2413.lib opencv_highgui2413.lib)
			else()
				set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{SystemDrive}/OpenCV2.4.13/x86/mingw/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
				target_link_libraries(UxVCtrl opencv_core2413 opencv_imgproc2413 opencv_highgui2413)
			endif()
		else()
			if(ENABLE_STATIC)
				target_link_libraries(UxVCtrl -static opencv_core opencv_imgproc opencv_highgui)
			else()
				target_link_libraries(UxVCtrl opencv_core opencv_imgproc opencv_highgui)
			endif()
		endif()
	elseif(OPENCV320)
		add_definitions(-DOPENCV320)
		if(WIN32)
			if(ENABLE_AUTO_DOWNLOAD)
				if(NOT EXISTS "$ENV{SystemDrive}/OpenCV3.2.0/x86/${VCX}/lib/opencv_world320.lib")
					message(STATUS "Downloading OpenCV3.2.0...")
					file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/OpenCV3.2.0.zip" "${PROJECT_SOURCE_DIR}/OpenCV3.2.0.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/OpenCV3.2.0.zip")
					execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/OpenCV3.2.0" "$ENV{SystemDrive}/OpenCV3.2.0")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/OpenCV3.2.0.zip")
					file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/cmake_extra_tools.zip" "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/cmake_extra_tools" COMMAND cmd /c pathman /as "$ENV{SystemDrive}\\OpenCV3.2.0\\x86\\${VCX}\\bin")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_SOURCE_DIR}/cmake_extra_tools")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
				endif()
			endif()
			include_directories("$ENV{SystemDrive}/OpenCV3.2.0/include")
			if(MSVC)
				set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{SystemDrive}/OpenCV3.2.0/x86/${VCX}/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
				target_link_libraries(UxVCtrl debug opencv_world320d.lib)
				target_link_libraries(UxVCtrl optimized opencv_world320.lib)
			else()
				set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{SystemDrive}/OpenCV3.2.0/x86/mingw/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
				target_link_libraries(UxVCtrl opencv_world320)
			endif()
		else()
			if(ENABLE_STATIC)
				target_link_libraries(UxVCtrl -static opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_videoio)
			else()
				target_link_libraries(UxVCtrl opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_videoio)
			endif()
		endif()
	elseif(OPENCV342)
		add_definitions(-DOPENCV342)
		if(WIN32)
			if(ENABLE_AUTO_DOWNLOAD)
				if(NOT EXISTS "$ENV{SystemDrive}/OpenCV3.4.2/x86/${VCX}/lib/opencv_world342.lib")
					message(STATUS "Downloading OpenCV3.4.2...")
					file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/OpenCV3.4.2.zip" "${PROJECT_SOURCE_DIR}/OpenCV3.4.2.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/OpenCV3.4.2.zip")
					execute_process(COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/OpenCV3.4.2" "$ENV{SystemDrive}/OpenCV3.4.2")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/OpenCV3.4.2.zip")
					file(DOWNLOAD "http://www.ensta-bretagne.fr/lebars/Share/cmake_extra_tools.zip" "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" COMMAND ${CMAKE_COMMAND} -E tar xfz "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
					execute_process(WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/cmake_extra_tools" COMMAND cmd /c pathman /as "$ENV{SystemDrive}\\OpenCV3.4.2\\x86\\${VCX}\\bin")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_SOURCE_DIR}/cmake_extra_tools")
					execute_process(COMMAND ${CMAKE_COMMAND} -E remove "${PROJECT_SOURCE_DIR}/cmake_extra_tools.zip")
				endif()
			endif()
			include_directories("$ENV{SystemDrive}/OpenCV3.4.2/include")
			if(MSVC)
				set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{SystemDrive}/OpenCV3.4.2/x86/${VCX}/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
				target_link_libraries(UxVCtrl debug opencv_world342d.lib)
				target_link_libraries(UxVCtrl optimized opencv_world342.lib)
			else()
				set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{SystemDrive}/OpenCV3.4.2/x86/mingw5/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
				target_link_libraries(UxVCtrl opencv_world342)
			endif()
		else()
			if(ENABLE_STATIC)
				target_link_libraries(UxVCtrl -static opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_videoio)
			else()
				target_link_libraries(UxVCtrl opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_videoio)
			endif()
		endif()
	endif()
endif()

if(USE_FFMPEG_VIDEO)
	add_definitions(-DUSE_FFMPEG_VIDEO)
	if(WIN32)
		if(MSVC)
			include_directories("$ENV{ProgramFiles}/ffmpeg-msvc/include")
			set(CMAKE_EXE_LINKER_FLAGS "/LIBPATH:\"$ENV{ProgramFiles}/ffmpeg-msvc/x86/vc15/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl avcodec.lib avdevice.lib avfilter.lib avformat.lib avutil.lib postproc.lib swresample.lib swscale.lib)
		else()
			include_directories("$ENV{ProgramFiles}/ffmpeg-msvc/include")
			set(CMAKE_EXE_LINKER_FLAGS "-L:\"$ENV{ProgramFiles}/ffmpeg-msvc/x86/vc15/lib\" ${CMAKE_EXE_LINKER_FLAGS}")
			target_link_libraries(UxVCtrl avcodec avdevice avfilter avformat avutil postproc swresample swscale)
		endif()
	else()
		if(ENABLE_STATIC)
			target_link_libraries(UxVCtrl -static avcodec avformat avutil swresample swscale)
		else()
			target_link_libraries(UxVCtrl avcodec avformat avutil swresample swscale)
		endif()
	endif()
endif()

if(ENABLE_BUILD_OPTIMIZATION_SAILBOAT)
else()
 target_sources(UxVCtrl PUBLIC SSC32Interface.cpp SonarLocalization.cpp SonarAltitudeEstimation.cpp Simulator.cpp SeanetProcessing.cpp RazorAHRSInterface.cpp FollowMe.cpp Hardware/SwarmonDevice.cpp Hardware/SSC32.cpp Hardware/Seanet.cpp Hardware/RPLIDAR.cpp Hardware/PathfinderDVL.cpp Hardware/P33x.cpp Hardware/NortekDVL.cpp Hardware/MT.cpp Hardware/MS583730BA.cpp Hardware/MS580314BA.cpp Hardware/MiniSSC.cpp Hardware/MES.cpp Hardware/MDM.cpp Hardware/LIRMIA3.cpp Hardware/Hokuyo.cpp Hardware/IM483I.cpp)
endif()

if(USE_OPENCV_HIGHGUI_CPP_API)
	add_definitions(-DUSE_OPENCV_HIGHGUI_CPP_API)
endif()

if(USE_ALTERNATE_RECORDING)
	add_definitions(-DUSE_ALTERNATE_RECORDING)
endif()

if(DISABLE_AIS_SUPPORT)
	add_definitions(-DDISABLE_AIS_SUPPORT)
endif()

if(WIN32)
	add_definitions(-DENABLE_GETTIMEOFDAY_WIN32 -DDISABLE_TIMEZONE_STRUCT_REDEFINITION)
	add_definitions(-DENABLE_CANCEL_THREAD -DENABLE_KILL_THREAD)
else()
	add_definitions(-DENABLE_OPENCV_HIGHGUI_THREADS_WORKAROUND)
endif()
add_definitions(-DSIMULATED_INTERNET_SWARMONDEVICE)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/../OSUtils")
include_directories("${PROJECT_SOURCE_DIR}/../Extensions/Img")
include_directories("${PROJECT_SOURCE_DIR}/../interval")
include_directories("${PROJECT_SOURCE_DIR}/../matrix_lib")
include_directories("${PROJECT_SOURCE_DIR}/Hardware")
include_directories("${PROJECT_SOURCE_DIR}/..")

if(WIN32)
	if(MSVC)
		target_link_libraries(UxVCtrl WinMM.lib WS2_32.lib)
	else()
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall -Wno-unknown-pragmas -Wno-unused-parameter")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
		target_link_libraries(UxVCtrl WinMM WS2_32)
	endif()
else()
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unused-parameter -Wextra")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
	if(ENABLE_STATIC)
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
		target_link_libraries(UxVCtrl -static pthread rt m)
	else()
		target_link_libraries(UxVCtrl pthread rt m)
	endif()
endif()

if(WIN32)
	message(STATUS "You might need to update your PATH and reboot depending on the prerequisites installed so that UxVCtrl can always find the necessary binaries and libraries at runtime...")
else()
	message(STATUS "You might need to update your PATH/LD_LIBRARY_PATH and reboot depending on the prerequisites installed so that UxVCtrl can always find the necessary binaries and libraries at runtime...")
endif()
