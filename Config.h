// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef CONFIG_H
#define CONFIG_H

#include "Globals.h"

inline int LoadConfig(void)
{
	FILE* file = NULL;
	char line[MAX_BUF_LEN];
	double d0 = 0, d1 = 0;

	// Missing error checking...

	memset(line, 0, sizeof(line));

	// Default values.
#pragma region General parameters
	robid = SUBMARINE_SIMULATOR_ROBID;
	roblength = 1;
	robwidth = 1;
	robheight = 1;
	nbopencvgui = 1;
	videoimgwidth = 320; 
	videoimgheight = 240; 
	captureperiod = 100;
	HorizontalBeam = 70;
	VerticalBeam = 50;
	bCropOnResize = FALSE;
	memset(szVideoRecordCodec, 0, sizeof(szVideoRecordCodec));
	sprintf(szVideoRecordCodec, "WMV2");
	bEnableOpenCVGUIs[0] = TRUE;
	bEnableOpenCVGUIs[1] = FALSE;
	bEnableOpenCVGUIs[2] = FALSE;
	bEnableOpenCVGUIs[3] = FALSE;
	bEnableOpenCVGUIs[4] = FALSE;
	bShowVideoOpenCVGUIs[0] = TRUE;
	bShowVideoOpenCVGUIs[1] = TRUE;
	bShowVideoOpenCVGUIs[2] = TRUE;
	bShowVideoOpenCVGUIs[3] = TRUE;
	bShowVideoOpenCVGUIs[4] = TRUE;
	opencvguiimgwidth[0] = 320;
	opencvguiimgwidth[1] = 320;
	opencvguiimgwidth[2] = 320;
	opencvguiimgwidth[3] = 320;
	opencvguiimgwidth[4] = 320;
	opencvguiimgheight[0] = 240;
	opencvguiimgheight[1] = 240;
	opencvguiimgheight[2] = 240;
	opencvguiimgheight[3] = 240;
	opencvguiimgheight[4] = 240;
	opencvguiperiod = 100;
	bMAVLinkInterface = TRUE;
	memset(szMAVLinkInterfacePath, 0, sizeof(szMAVLinkInterfacePath));
	sprintf(szMAVLinkInterfacePath, ":5760");
	MAVLinkInterfaceBaudRate = 115200;
	MAVLinkInterfaceTimeout = 1500;
	MAVLinkInterface_mavlink_comm = 4;
	MAVLinkInterface_system_id = 1;
	MAVLinkInterface_component_id = 1;
	MAVLinkInterface_target_system = 0;
	MAVLinkInterface_target_component = 0;
	bForceDefaultMAVLink1MAVLinkInterface = TRUE;
	bDisableMAVLinkInterfaceIN = FALSE;
	bNMEAInterface = TRUE;
	memset(szNMEAInterfacePath, 0, sizeof(szNMEAInterfacePath));
	sprintf(szNMEAInterfacePath, ":5001");
	NMEAInterfaceBaudRate = 4800;
	NMEAInterfaceTimeout = 1500;
	NMEAInterfacePeriod = 500;
	bEnable_NMEAInterface_GPGGA = FALSE;
	bEnable_NMEAInterface_GPRMC = TRUE;
	bEnable_NMEAInterface_GPGLL = FALSE;
	bEnable_NMEAInterface_GPVTG = FALSE;
	bEnable_NMEAInterface_HCHDG = FALSE;
	bEnable_NMEAInterface_HEHDT = FALSE;
	bEnable_NMEAInterface_HEROT = FALSE;
	bEnable_NMEAInterface_WIMWV = FALSE;
	bEnable_NMEAInterface_WIMWD = FALSE;
	bEnable_NMEAInterface_WIMDA = FALSE;
	bEnable_NMEAInterface_PRDID = FALSE;
	bEnable_NMEAInterface_IIRSA = FALSE;
	bEnable_NMEAInterface_SDDBT = FALSE;
	NMEAInterfaceSendPeriod = 500;
	bDisableNMEAInterfaceIN = FALSE;
	bRazorAHRSInterface = TRUE;
	memset(szRazorAHRSInterfacePath, 0, sizeof(szRazorAHRSInterfacePath));
	sprintf(szRazorAHRSInterfacePath, ":5007");
	RazorAHRSInterfaceBaudRate = 57600;
	RazorAHRSInterfaceTimeout = 2000;
	bROSMode_RazorAHRSInterface = FALSE;
	bSSC32Interface = TRUE;
	memset(szSSC32InterfacePath, 0, sizeof(szSSC32InterfacePath));
	sprintf(szSSC32InterfacePath, ":5004");
	SSC32InterfaceBaudRate = 9600;
	SSC32InterfaceTimeout = 1000;
	bVideoInterface = FALSE;
	memset(VideoInterfacePort, 0, sizeof(szSSC32InterfacePath));
	sprintf(VideoInterfacePort, ":4014");
	videoimgwidth_VideoInterface = 320;
	videoimgheight_VideoInterface = 240;
	captureperiod_VideoInterface = 100;
	VideoInterfaceTimeout = 0;
	bUDP_VideoInterface = FALSE;
	guiid_VideoInterface = -1;
	videoid_VideoInterface = -1;
	encodequality_VideoInterface = 0;
	bDisablelognav = FALSE;
	bCommandPrompt = TRUE;
	bEcho = TRUE;
#pragma endregion
#pragma region Devices parameters
	bDisableVideo[0] = TRUE;
	bDisableVideo[1] = TRUE;
	bDisableVideo[2] = TRUE;
	bDisableVideo[3] = TRUE;
	bDisableVideo[4] = TRUE;
	bDisablegpControl = TRUE;
	bDisablePathfinderDVL = TRUE;
	bDisableNortekDVL = TRUE;
	bDisableMES = TRUE;
	bDisableMDM = TRUE;
	bDisableSeanet = TRUE;
	bDisableBlueView[0] = TRUE;
	bDisableBlueView[1] = TRUE;
	bDisableHokuyo = TRUE;
	bDisableRPLIDAR = TRUE;
	bDisableMS580314BA = TRUE;
	bDisableMS583730BA = TRUE;
	bDisableP33x = TRUE;
	bDisableRazorAHRS = TRUE;
	bDisableMT = TRUE;
	bDisableSBG = TRUE;
	bDisableNMEADevice[0] = TRUE;
	bDisableNMEADevice[1] = TRUE;
	bDisableublox[0] = TRUE;
	bDisableublox[1] = TRUE;
	bDisableublox[2] = TRUE;
	bDisableMAVLinkDevice[0] = TRUE;
	bDisableMAVLinkDevice[1] = TRUE;
	bDisableSwarmonDevice = TRUE;
	bDisableUE9A = TRUE;
	bDisableSSC32 = TRUE;
	bDisablePololu[0] = TRUE;
	bDisablePololu[1] = TRUE;
	bDisablePololu[2] = TRUE;
	bDisableMiniSSC = TRUE;
	bDisableIM483I = TRUE;
#pragma endregion
#pragma region Controller parameters
	u_max = 1;
	uw_max = 1;
	u_coef = 0.5;
	uw_coef = 0.5;
	Kp = 1.0;
	Kd1 = 0.5;
	Kd2 = 0.1;
	Ki = 0.1;
	uw_derivative_max = 0.08;
	uw_integral_max = 0.1;
	cosdelta_angle_threshold = 0.5;
	wdradius = 0.25;
	vrxmax = 0.4;
	omegazmax = 0.8;
	Kp_z = 0;
	Kd_z = 0;
	Ki_z = 0;
	up_max_z = 0;
	ud_max_z = 0;
	ui_max_z = 0;
	u_min_z = -1;
	u_max_z = 1;
	error_min_z = -0.05;
	error_max_z = 0.05;
	dz_max_z = 0.25;
	Kp_wy = 1.0;
	Kd_wy = 0;
	Ki_wy = 0;
	up_max_wy = 1;
	ud_max_wy = 0.5;
	ui_max_wy = 0.1;
	u_min_wy = -1;
	u_max_wy = 1;
	error_min_wy = -0.5;
	error_max_wy = 0.5;
	omega_max_wy = 0.8;
	Kp_wx = 1.0;
	Kd_wx = 0;
	Ki_wx = 0;
	up_max_wx = 1;
	ud_max_wx = 0.5;
	ui_max_wx = 0.1;
	u_min_wx = -1;
	u_max_wx = 1;
	error_min_wx = -0.5;
	error_max_wx = 0.5;
	omega_max_wx = 0.8;
	gamma_infinite = 0.78;
	radius = 5;
	betaside = 0.5;
	betarear = 1.5;
	zeta = 0.87;
	check_strategy_period = 60;
	sail_update_period = 20;
	sailboattacktype = 0;
	sailformulatype = 0;
	controllerperiod = 25;
#pragma endregion
#pragma region Observer parameters
	psi_source = 0;
	theta_phi_source = 0;
	x_y_source = 0;
	z_source = 0;
	z_pressure_acc = 0.1;
	dvl_acc = 0.1;
	of_acc = 0.1;
	acousticmodem_acc = 5;
	phi_ahrs_acc = 0.1;
	theta_ahrs_acc = 0.1;
	psi_ahrs_acc = 0.1;
	accrx_ahrs_acc = 0.1;
	accry_ahrs_acc = 0.1;
	accrz_ahrs_acc = 0.1;
	omegax_ahrs_acc = 0.1;
	omegay_ahrs_acc = 0.1;
	omegaz_ahrs_acc = 0.1;
	alpha_max_err = 0.01;
	d_max_err = 0.1;
	alphavrxhat = interval(0.09,0.10);
	alphaomegazhat = interval(0.7,0.8);
	alphafvrxhat = interval(0.20,0.25);
	alphafomegazhat = interval(0.20,0.25);
	alphazhat = interval(0.10,0.12);
	vzuphat = interval(0.005,0.015);
	alphashat = interval(0-0.1,0+0.1);
	omegashat = interval(2.3562-0.05,2.3562+0.05);
	xdotnoise = interval(-0.001,+0.001);
	ydotnoise = interval(-0.001,+0.001);
	zdotnoise = interval(-0.001,+0.001);
	phidotnoise = interval(-0.001,+0.001);
	thetadotnoise = interval(-0.001,+0.001);
	psidotnoise = interval(-0.001,+0.001);
	vrxdotnoise = interval(-0.001,+0.001);
	vrydotnoise = interval(-0.001,+0.001);
	vrzdotnoise = interval(-0.001,+0.001);
	omegaxdotnoise = interval(-0.001,+0.001);
	omegaydotnoise = interval(-0.001,+0.001);
	omegazdotnoise = interval(-0.001,+0.001);
	RTK_fixed_acc = 0.025;
	RTK_float_acc = 0.5;
	GPS_high_acc = 2.5;
	GPS_high_acc_HDOP = 0.8;
	GPS_high_acc_nbsat = 8;
	GPS_med_acc = 5;
	GPS_med_acc_HDOP = 1;
	GPS_med_acc_nbsat = 6;
	GPS_low_acc = 10;
	GPS_low_acc_HDOP = 2;
	GPS_low_acc_nbsat = 4;
	GPS_min_sat_signal = 20;
	GPS_submarine_depth_limit = -0.5;
	GPS_SOG_for_valid_COG = 0.2;
	rangescale = 10;
	sdir = 1;
	nb_outliers = 25;
	dynamicsonarlocalization_period = 0.2;
	observerperiod = 25;
#pragma endregion
#pragma region Wind, current and waves
	vtwind_med = 0.01;
	vtwind_var = 0.01;
	psitwind_med = 0.0*M_PI/2.0;
	psitwind_var = 1.0*M_PI/8.0;
	wind_filter_coef = 0.999;
	vc_med = 0.01;
	vc_var = 0.01;
	psic_med = 0.0*M_PI/2.0;
	psic_var = 1.0*M_PI/8.0;
	hw_var = 0.1;
#pragma endregion
#pragma region Power consumption
	P_electronics_1 = 0; P_electronics_2 = 0; P_electronics_3 = 0; P_electronics_4 = 0;
	P_actuators_1 = 0; P_actuators_2 = 0; P_actuators_3 = 0; P_actuators_4 = 0;
	bat_filter_coef = 0.9;
#pragma endregion
#pragma region Simulator initial state
	x_0 = 0; y_0 = 0; z_0 = 0; phi_0 = 0; theta_0 = 0; psi_0 = 0; vrx_0 = 0; vry_0 = 0; vrz_0 = 0; omegax_0 = 0; omegay_0 = 0; omegaz_0 = 0;
	alpha_0 = 0; d_0 = 0;
#pragma endregion
#pragma region Simulator physical parameters
	x_max_rand_err = 5; x_bias_err = 2;
	y_max_rand_err = 5; y_bias_err = -1;
	z_max_rand_err = 0.05; z_bias_err = 0.02;
	phi_max_rand_err = 0.05; phi_bias_err = 0.02;
	theta_max_rand_err = 0.05; theta_bias_err = 0.02;
	psi_max_rand_err = 0.05; psi_bias_err = 0.02;
	vrx_max_rand_err = 0.05; vrx_bias_err = 0.02;
	vry_max_rand_err = 0.05; vry_bias_err = 0.02;
	vrz_max_rand_err = 0.05; vrz_bias_err = 0.02;
	omegaz_max_rand_err = 0.05; omegaz_bias_err = 0.02;
	alpha_max_rand_err = 0.005; alpha_bias_err = 0.002;
	d_max_rand_err = 0.25; d_bias_err = -0.1;
	alphavrx = 0.1;
	alphaomegaz = 0.7;
	alphafvrx = 0.21;
	alphafomegaz = 0.21;
	alphaz = 0.1;
	vzup = 0.01;
	alphas = 0;
	omegas = 2.3562;
	outliers_ratio = 0.5;
	bNoSimGNSSInsideObstacles = FALSE;
	bRawSimStateInMAVLinkInterface = FALSE;
	simulatorperiod = 70;
#pragma endregion

	file = fopen("UxVCtrl.txt", "r");
	if (file != NULL)
	{
#pragma region General parameters
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%i", &robid) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &roblength) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &robwidth) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &robheight) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &nbopencvgui) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &videoimgwidth) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &videoimgheight) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &captureperiod) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &HorizontalBeam) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &VerticalBeam) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bCropOnResize) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%[^\r\n]4s", szVideoRecordCodec) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnableOpenCVGUIs[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnableOpenCVGUIs[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnableOpenCVGUIs[2]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnableOpenCVGUIs[3]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnableOpenCVGUIs[4]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bShowVideoOpenCVGUIs[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bShowVideoOpenCVGUIs[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bShowVideoOpenCVGUIs[2]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bShowVideoOpenCVGUIs[3]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bShowVideoOpenCVGUIs[4]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgwidth[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgwidth[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgwidth[2]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgwidth[3]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgwidth[4]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgheight[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgheight[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgheight[2]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgheight[3]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiimgheight[4]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &opencvguiperiod) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bMAVLinkInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%[^\r\n]255s", szMAVLinkInterfacePath) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &MAVLinkInterfaceBaudRate) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &MAVLinkInterfaceTimeout) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &MAVLinkInterface_mavlink_comm) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &MAVLinkInterface_system_id) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &MAVLinkInterface_component_id) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &MAVLinkInterface_target_system) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &MAVLinkInterface_target_component) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bForceDefaultMAVLink1MAVLinkInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMAVLinkInterfaceIN) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bNMEAInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%[^\r\n]255s", szNMEAInterfacePath) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &NMEAInterfaceBaudRate) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &NMEAInterfaceTimeout) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &NMEAInterfacePeriod) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_GPGGA) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_GPRMC) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_GPGLL) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_GPVTG) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_HCHDG) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_HEHDT) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_HEROT) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_WIMWV) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_WIMWD) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_WIMDA) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_PRDID) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_IIRSA) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEnable_NMEAInterface_SDDBT) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &NMEAInterfaceSendPeriod) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableNMEAInterfaceIN) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bRazorAHRSInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%[^\r\n]255s", szRazorAHRSInterfacePath) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &RazorAHRSInterfaceBaudRate) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &RazorAHRSInterfaceTimeout) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bROSMode_RazorAHRSInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bSSC32Interface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%[^\r\n]255s", szSSC32InterfacePath) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &SSC32InterfaceBaudRate) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &SSC32InterfaceTimeout) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bVideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%[^\r\n]255s", VideoInterfacePort) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &videoimgwidth_VideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &videoimgheight_VideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &captureperiod_VideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &VideoInterfaceTimeout) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bUDP_VideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &guiid_VideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &videoid_VideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &encodequality_VideoInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisablelognav) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bCommandPrompt) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bEcho) != 1) printf("Invalid configuration file.\n");
#pragma endregion
#pragma region Devices parameters
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableVideo[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableVideo[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableVideo[2]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableVideo[3]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableVideo[4]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisablegpControl) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisablePathfinderDVL) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableNortekDVL) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMES) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMDM) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableSeanet) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableBlueView[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableBlueView[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableHokuyo) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableRPLIDAR) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMS580314BA) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMS583730BA) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableP33x) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableRazorAHRS) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMT) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableSBG) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableNMEADevice[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableNMEADevice[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableublox[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableublox[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableublox[2]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMAVLinkDevice[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMAVLinkDevice[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableSwarmonDevice) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableUE9A) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableSSC32) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisablePololu[0]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisablePololu[1]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisablePololu[2]) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableMiniSSC) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bDisableIM483I) != 1) printf("Invalid configuration file.\n");
#pragma endregion
#pragma region Controller parameters
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_max) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &uw_max) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_coef) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &uw_coef) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kp) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kd1) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kd2) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Ki) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &uw_derivative_max) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &uw_integral_max) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &cosdelta_angle_threshold) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &wdradius) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vrxmax) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegazmax) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kp_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kd_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Ki_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &up_max_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &ud_max_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &ui_max_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_min_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_max_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &error_min_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &error_max_z) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &dz_max_z) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kp_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kd_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Ki_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &up_max_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &ud_max_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &ui_max_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_min_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_max_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &error_min_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &error_max_wy) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omega_max_wy) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kp_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Kd_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &Ki_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &up_max_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &ud_max_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &ui_max_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_min_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &u_max_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &error_min_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &error_max_wx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omega_max_wx) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &gamma_infinite) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &radius) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &betaside) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &betarear) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &zeta) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &check_strategy_period) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &sail_update_period) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &sailboattacktype) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &sailformulatype) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &controllerperiod) != 1) printf("Invalid configuration file.\n");
#pragma endregion
#pragma region Observer parameters
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &psi_source) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &theta_phi_source) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &x_y_source) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &z_source) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &z_pressure_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &dvl_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &of_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &acousticmodem_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &phi_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &theta_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psi_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &accrx_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &accry_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &accrz_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegax_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegay_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegaz_ahrs_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alpha_max_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d_max_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		alphavrxhat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		alphaomegazhat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		alphafvrxhat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		alphafomegazhat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		alphazhat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		vzuphat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		alphashat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		omegashat = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		xdotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		ydotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		zdotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		phidotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		thetadotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		psidotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		vrxdotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		vrydotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		vrzdotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		omegaxdotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		omegaydotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		omegazdotnoise = interval(d0,d1);

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &RTK_fixed_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &RTK_float_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_high_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_high_acc_HDOP) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &GPS_high_acc_nbsat) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_med_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_med_acc_HDOP) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &GPS_med_acc_nbsat) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_low_acc) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_low_acc_HDOP) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &GPS_low_acc_nbsat) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &GPS_min_sat_signal) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_submarine_depth_limit) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &GPS_SOG_for_valid_COG) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &rangescale) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &sdir) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &nb_outliers) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &dynamicsonarlocalization_period) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &observerperiod) != 1) printf("Invalid configuration file.\n");
#pragma endregion
#pragma region Current and waves
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vtwind_med) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vtwind_var) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psitwind_med) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psitwind_var) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &wind_filter_coef) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vc_med) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vc_var) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psic_med) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psic_var) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &hw_var) != 1) printf("Invalid configuration file.\n");
#pragma endregion
#pragma region Power consumption
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_electronics_1) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_electronics_2) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_electronics_3) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_electronics_4) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_actuators_1) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_actuators_2) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_actuators_3) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &P_actuators_4) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &bat_filter_coef) != 1) printf("Invalid configuration file.\n");
#pragma endregion
#pragma region Simulated submarine initial state
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &x_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &y_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &z_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &phi_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &theta_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psi_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vrx_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vry_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vrz_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegax_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegay_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegaz_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alpha_0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d_0) != 1) printf("Invalid configuration file.\n");
#pragma endregion
#pragma region Simulated submarine physical parameters
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &x_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &x_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &y_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &y_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &z_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &z_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &phi_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &phi_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &theta_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &theta_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psi_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &psi_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vrx_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vrx_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vry_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vry_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vrz_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vrz_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegaz_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegaz_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alpha_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alpha_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d_max_rand_err) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d_bias_err) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alphavrx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alphaomegaz) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alphafvrx) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alphafomegaz) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alphaz) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &vzup) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alphas) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &omegas) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &outliers_ratio) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bNoSimGNSSInsideObstacles) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &bRawSimStateInMAVLinkInterface) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &simulatorperiod) != 1) printf("Invalid configuration file.\n");
#pragma endregion

		if (fclose(file) != EXIT_SUCCESS) printf("fclose() failed.\n");
	}
	else
	{
		printf("Configuration file not found.\n");
		return EXIT_FAILURE;
	}
#pragma region Parameters check
	switch (robid)
	{
	case SUBMARINE_SIMULATOR_ROBID:
	case SAUCISSE_ROBID:
	case SARDINE_ROBID:
	case CISCREA_ROBID:
	case BLUEROV_ROBID:
	case LIRMIA3_ROBID:
	case BUBBLE_ROBID:
	case MOTORBOAT_SIMULATOR_ROBID:
	case MOTORBOAT_ROBID:
	case SAILBOAT_SIMULATOR_ROBID:
	case VAIMOS_ROBID:
	case SAILBOAT_ROBID:
	case SAILBOAT2_ROBID:
	case TANK_SIMULATOR_ROBID:
	case ETAS_WHEEL_ROBID:
	case BUGGY_SIMULATOR_ROBID:
	case BUGGY_ROBID:
	case QUADRO_SIMULATOR_ROBID:
	case COPTER_ROBID:
	case ARDUCOPTER_ROBID:
		break;
	default:
		printf("Invalid parameter : robid.\n");
		robid = SUBMARINE_SIMULATOR_ROBID;
		break;
	}
	if ((nbopencvgui < 0)||(nbopencvgui > MAX_NB_OPENCVGUI))
	{
		printf("Invalid parameter : nbopencvgui.\n");
		nbopencvgui = 1;
	}
	if (videoimgwidth <= 0)
	{
		printf("Invalid parameter : videoimgwidth.\n");
		videoimgwidth = 320;
	}
	if (videoimgheight <= 0)
	{
		printf("Invalid parameter : videoimgheight.\n");
		videoimgheight = 240;
	}
	if (captureperiod <= 0)
	{
		printf("Invalid parameter : captureperiod.\n");
		captureperiod = 100;
	}
	if ((HorizontalBeam <= 0)||(HorizontalBeam > 360))
	{
		printf("Invalid parameter : HorizontalBeam.\n");
		HorizontalBeam = 70;
	}
	if ((VerticalBeam <= 0)||(VerticalBeam > 360))
	{
		printf("Invalid parameter : VerticalBeam.\n");
		VerticalBeam = 50;
	}
	if (bEnableOpenCVGUIs[0]&&(nbopencvgui <= 0))
	{
		printf("Invalid parameter : bEnableOpenCVGUIs[0].\n");
		bEnableOpenCVGUIs[0] = FALSE;
	}
	if (bEnableOpenCVGUIs[1]&&(nbopencvgui <= 1))
	{
		printf("Invalid parameter : bEnableOpenCVGUIs[1].\n");
		bEnableOpenCVGUIs[1] = FALSE;
	}
	if (bEnableOpenCVGUIs[2]&&(nbopencvgui <= 2))
	{
		printf("Invalid parameter : bEnableOpenCVGUIs[2].\n");
		bEnableOpenCVGUIs[2] = FALSE;
	}
	if (bEnableOpenCVGUIs[3]&&(nbopencvgui <= 3))
	{
		printf("Invalid parameter : bEnableOpenCVGUIs[3].\n");
		bEnableOpenCVGUIs[3] = FALSE;
	}
	if (bEnableOpenCVGUIs[4]&&(nbopencvgui <= 4))
	{
		printf("Invalid parameter : bEnableOpenCVGUIs[4].\n");
		bEnableOpenCVGUIs[4] = FALSE;
	}
	if ((MAVLinkInterface_system_id < 0)||(MAVLinkInterface_system_id >= 256))
	{
		printf("Invalid parameter : MAVLinkInterface_system_id.\n");
		MAVLinkInterface_system_id = 1;
	}
	if ((MAVLinkInterface_component_id < 0)||(MAVLinkInterface_component_id >= 256))
	{
		printf("Invalid parameter : MAVLinkInterface_component_id.\n");
		MAVLinkInterface_component_id = 1;
	}
	if ((MAVLinkInterface_target_system < 0)||(MAVLinkInterface_target_system >= 256))
	{
		printf("Invalid parameter : MAVLinkInterface_target_system.\n");
		MAVLinkInterface_target_system = 0;
	}
	if ((MAVLinkInterface_target_component < 0)||(MAVLinkInterface_target_component >= 256))
	{
		printf("Invalid parameter : MAVLinkInterface_target_component.\n");
		MAVLinkInterface_target_component = 0;
	}
	if ((u_max <= 0)||(u_max > 1))
	{
		printf("Invalid parameter : u_max.\n");
		u_max = 1;
	}
	if ((uw_max <= 0)||(uw_max > 1))
	{
		printf("Invalid parameter : uw_max.\n");
		uw_max = 1;
	}
	if ((u_coef <= 0)||(u_coef > 1))
	{
		printf("Invalid parameter : u_coef.\n");
		u_coef = 0.5;
	}
	if ((uw_coef <= 0)||(uw_coef > 1))
	{
		printf("Invalid parameter : uw_coef.\n");
		uw_coef = 0.5;
	}
	if (Kd2 <= 0)
	{
		printf("Invalid parameter : Kd2.\n");
		Kd2 = 0.1;
	}
	if ((uw_derivative_max <= 0)||(uw_derivative_max > 1))
	{
		printf("Invalid parameter : uw_derivative_max.\n");
		uw_derivative_max = 0.08;
	}
	if ((uw_integral_max <= 0)||(uw_integral_max > 1))
	{
		printf("Invalid parameter : uw_integral_max.\n");
		uw_integral_max = 0.1;
	}
	if ((gamma_infinite < -M_PI)||(gamma_infinite > M_PI))
	{
		printf("Invalid parameter : gamma_infinite.\n");
		gamma_infinite = 0.78;
	}
	if ((betaside < -M_PI)||(betaside > M_PI))
	{
		printf("Invalid parameter : betaside.\n");
		betaside = 0.5;
	}
	if ((betarear < -M_PI)||(betarear > M_PI))
	{
		printf("Invalid parameter : betarear.\n");
		betarear = 1.5;
	}
	if ((zeta < -M_PI)||(zeta > M_PI))
	{
		printf("Invalid parameter : zeta.\n");
		zeta = 0.87;
	}
	if (controllerperiod < 0)
	{
		printf("Invalid parameter : controllerperiod.\n");
		controllerperiod = 25;
	}
	if ((psi_source < 0)||(psi_source > 5))
	{
		printf("Invalid parameter : psi_source.\n");
		psi_source = 0;
	}
	if ((theta_phi_source < 0)||(theta_phi_source > 5))
	{
		printf("Invalid parameter : theta_phi_source.\n");
		theta_phi_source = 0;
	}
	if ((x_y_source < 0)||(x_y_source > 5))
	{
		printf("Invalid parameter : x_y_source.\n");
		x_y_source = 0;
	}
	if ((z_source < 0)||(z_source > 5))
	{
		printf("Invalid parameter : z_source.\n");
		z_source = 0;
	}
	if (GPS_high_acc_nbsat < 0)
	{
		printf("Invalid parameter : GPS_high_acc_nbsat.\n");
		GPS_high_acc_nbsat = 8;
	}
	if (GPS_med_acc_nbsat < 0)
	{
		printf("Invalid parameter : GPS_med_acc_nbsat.\n");
		GPS_med_acc_nbsat = 6;
	}
	if (GPS_low_acc_nbsat < 0)
	{
		printf("Invalid parameter : GPS_low_acc_nbsat.\n");
		GPS_low_acc_nbsat = 4;
	}
	if ((GPS_min_sat_signal < 0)||(GPS_min_sat_signal > 99))
	{
		printf("Invalid parameter : GPS_min_sat_signal.\n");
		GPS_min_sat_signal = 20;
	}
	if (rangescale < 0)
	{
		printf("Invalid parameter : rangescale.\n");
		rangescale = 10;
	}
	if (nb_outliers < 0)
	{
		printf("Invalid parameter : nb_outliers.\n");
		nb_outliers = 25;
	}
	if (observerperiod < 0)
	{
		printf("Invalid parameter : observerperiod.\n");
		observerperiod = 25;
	}
	if ((psitwind_med < -M_PI)||(psitwind_med > M_PI))
	{
		printf("Invalid parameter : psitwind_med.\n");
		psitwind_med = 0.0*M_PI/2.0;
	}
	if ((psitwind_var < -M_PI)||(psitwind_var > M_PI))
	{
		printf("Invalid parameter : psitwind_var.\n");
		psitwind_var = 1.0*M_PI/8.0;
	}
	if ((wind_filter_coef < 0)||(wind_filter_coef > 1))
	{
		printf("Invalid parameter : wind_filter_coef.\n");
		wind_filter_coef = 0.999;
	}
	if ((psic_med < -M_PI)||(psic_med > M_PI))
	{
		printf("Invalid parameter : psic_med.\n");
		psic_med = 0.0*M_PI/2.0;
	}
	if ((psic_var < -M_PI)||(psic_var > M_PI))
	{
		printf("Invalid parameter : psic_var.\n");
		psic_var = 1.0*M_PI/8.0;
	}
	if ((bat_filter_coef < 0)||(bat_filter_coef > 1))
	{
		printf("Invalid parameter : bat_filter_coef.\n");
		bat_filter_coef = 0.9;
	}
	if (outliers_ratio < 0)
	{
		printf("Invalid parameter : outliers_ratio.\n");
		outliers_ratio = 0.5;
	}
	if (simulatorperiod < 0)
	{
		printf("Invalid parameter : simulatorperiod.\n");
		simulatorperiod = 70;
	}
#pragma endregion
	return EXIT_SUCCESS;
}

inline int SaveConfig(void)
{
	FILE* filein = NULL;
	FILE* fileout = NULL;
	char line[MAX_BUF_LEN];

	// Missing error checking...

	memset(line, 0, sizeof(line));

	filein = fopen("UxVCtrl.txt", "r");
	if (filein == NULL)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}
	fileout = fopen("~UxVCtrl.txt", "w");
	if (fileout == NULL)
	{
		printf("Error saving configuration file.\n");
		fclose(filein);
		return EXIT_FAILURE;
	}

#pragma region General parameters
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%#.8x\n", robid) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", roblength) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", robwidth) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", robheight) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", nbopencvgui) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", videoimgwidth) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", videoimgheight) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", captureperiod) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", HorizontalBeam) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", VerticalBeam) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bCropOnResize) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.4s\n", szVideoRecordCodec) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnableOpenCVGUIs[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnableOpenCVGUIs[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnableOpenCVGUIs[2]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnableOpenCVGUIs[3]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnableOpenCVGUIs[4]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bShowVideoOpenCVGUIs[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bShowVideoOpenCVGUIs[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bShowVideoOpenCVGUIs[2]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bShowVideoOpenCVGUIs[3]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bShowVideoOpenCVGUIs[4]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgwidth[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgwidth[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgwidth[2]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgwidth[3]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgwidth[4]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgheight[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgheight[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgheight[2]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgheight[3]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiimgheight[4]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", opencvguiperiod) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bMAVLinkInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.255s\n", szMAVLinkInterfacePath) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", MAVLinkInterfaceBaudRate) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", MAVLinkInterfaceTimeout) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", MAVLinkInterface_mavlink_comm) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", MAVLinkInterface_system_id) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", MAVLinkInterface_component_id) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", MAVLinkInterface_target_system) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", MAVLinkInterface_target_component) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bForceDefaultMAVLink1MAVLinkInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMAVLinkInterfaceIN) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bNMEAInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.255s\n", szNMEAInterfacePath) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", NMEAInterfaceBaudRate) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", NMEAInterfaceTimeout) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", NMEAInterfacePeriod) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_GPGGA) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_GPRMC) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_GPGLL) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_GPVTG) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_HCHDG) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_HEHDT) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_HEROT) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_WIMWV) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_WIMWD) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_WIMDA) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_PRDID) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_IIRSA) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEnable_NMEAInterface_SDDBT) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", NMEAInterfaceSendPeriod) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableNMEAInterfaceIN) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bRazorAHRSInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.255s\n", szRazorAHRSInterfacePath) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", RazorAHRSInterfaceBaudRate) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", RazorAHRSInterfaceTimeout) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bROSMode_RazorAHRSInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bSSC32Interface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.255s\n", szSSC32InterfacePath) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", SSC32InterfaceBaudRate) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", SSC32InterfaceTimeout) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bVideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.255s\n", VideoInterfacePort) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", videoimgwidth_VideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", videoimgheight_VideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", captureperiod_VideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", VideoInterfaceTimeout) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bUDP_VideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", guiid_VideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", videoid_VideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", encodequality_VideoInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisablelognav) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bCommandPrompt) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bEcho) < 0) printf("Error writing configuration file.\n");
#pragma endregion
#pragma region Devices parameters
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableVideo[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableVideo[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableVideo[2]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableVideo[3]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableVideo[4]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisablegpControl) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisablePathfinderDVL) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableNortekDVL) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMES) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMDM) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableSeanet) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableBlueView[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableBlueView[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableHokuyo) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableRPLIDAR) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMS580314BA) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMS583730BA) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableP33x) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableRazorAHRS) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMT) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableSBG) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableNMEADevice[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableNMEADevice[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableublox[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableublox[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableublox[2]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMAVLinkDevice[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMAVLinkDevice[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableSwarmonDevice) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableUE9A) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableSSC32) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisablePololu[0]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisablePololu[1]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisablePololu[2]) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableMiniSSC) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bDisableIM483I) < 0) printf("Error writing configuration file.\n");
#pragma endregion
#pragma region Controller parameters
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_max) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", uw_max) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_coef) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", uw_coef) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kp) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kd1) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kd2) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Ki) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", uw_derivative_max) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", uw_integral_max) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", cosdelta_angle_threshold) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", wdradius) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrxmax) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegazmax) < 0) printf("Error writing configuration file.\n");
	
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kp_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kd_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Ki_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", up_max_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ud_max_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ui_max_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_min_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_max_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", error_min_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", error_max_z) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", dz_max_z) < 0) printf("Error writing configuration file.\n");
	
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kp_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kd_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Ki_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", up_max_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ud_max_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ui_max_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_min_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_max_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", error_min_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", error_max_wy) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omega_max_wy) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kp_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Kd_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", Ki_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", up_max_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ud_max_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ui_max_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_min_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", u_max_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", error_min_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", error_max_wx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omega_max_wx) < 0) printf("Error writing configuration file.\n");
	
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", gamma_infinite) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", radius) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", betaside) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", betarear) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", zeta) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", check_strategy_period) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", sail_update_period) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", sailboattacktype) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", sailformulatype) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", controllerperiod) < 0) printf("Error writing configuration file.\n");
#pragma endregion
#pragma region Observer parameters
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", psi_source) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", theta_phi_source) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", x_y_source) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", z_source) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", z_pressure_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", dvl_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", of_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", acousticmodem_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", phi_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", theta_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psi_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", accrx_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", accry_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", accrz_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegax_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegay_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaz_ahrs_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alpha_max_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", d_max_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphavrxhat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphavrxhat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphaomegazhat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphaomegazhat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphafvrxhat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphafvrxhat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphafomegazhat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphafomegazhat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphazhat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphazhat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vzuphat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vzuphat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphashat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphashat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegashat.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegashat.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", xdotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", xdotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ydotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", ydotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", zdotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", zdotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", phidotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", phidotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", thetadotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", thetadotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psidotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psidotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrxdotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrxdotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrydotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrydotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrzdotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrzdotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaxdotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaxdotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaydotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaydotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegazdotnoise.inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegazdotnoise.sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", RTK_fixed_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", RTK_float_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_high_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_high_acc_HDOP) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", GPS_high_acc_nbsat) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_med_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_med_acc_HDOP) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", GPS_med_acc_nbsat) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_low_acc) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_low_acc_HDOP) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", GPS_low_acc_nbsat) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", GPS_min_sat_signal) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_submarine_depth_limit) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", GPS_SOG_for_valid_COG) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", rangescale) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", sdir) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", nb_outliers) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", dynamicsonarlocalization_period) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", observerperiod) < 0) printf("Error writing configuration file.\n");
#pragma endregion
#pragma region Current and waves
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vtwind_med) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vtwind_var) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psitwind_med) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psitwind_var) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", wind_filter_coef) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vc_med) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vc_var) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psic_med) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psic_var) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", hw_var) < 0) printf("Error writing configuration file.\n");
#pragma endregion
#pragma region Power consumption
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_electronics_1) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_electronics_2) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_electronics_3) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_electronics_4) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_actuators_1) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_actuators_2) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_actuators_3) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", P_actuators_4) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", bat_filter_coef) < 0) printf("Error writing configuration file.\n");
#pragma endregion
#pragma region Simulated submarine initial state
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", x_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", y_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", z_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", phi_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", theta_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psi_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrx_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vry_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrz_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegax_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegay_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaz_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alpha_0) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", d_0) < 0) printf("Error writing configuration file.\n");
#pragma endregion
#pragma region Simulated submarine physical parameters
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", x_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", x_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", y_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", y_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", z_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", z_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", phi_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", phi_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", theta_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", theta_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psi_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", psi_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrx_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrx_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vry_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vry_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrz_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vrz_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaz_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegaz_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alpha_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alpha_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", d_max_rand_err) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", d_bias_err) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphavrx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphaomegaz) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphafvrx) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphafomegaz) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphaz) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", vzup) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alphas) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", omegas) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", outliers_ratio) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bNoSimGNSSInsideObstacles) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", bRawSimStateInMAVLinkInterface) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", simulatorperiod) < 0) printf("Error writing configuration file.\n");
#pragma endregion

	if (fclose(fileout) != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		fclose(filein);
		return EXIT_FAILURE;
	}
	if (fclose(filein) != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}

	if (remove("UxVCtrl.txt") != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}
	if (rename("~UxVCtrl.txt", "UxVCtrl.txt") != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

inline int LoadEnv(void)
{
	FILE* file = NULL;
	char line[MAX_BUF_LEN];
	int i = 0;
	double d0 = 0, d1 = 0, d2 = 0, d3 = 0;

	// Missing error checking...

	memset(line, 0, sizeof(line));

	// Default values.
	angle_env = M_PI/2.0-90.0*M_PI/180.0;
	lat_env = 0;
	long_env = 0;
	alt_env = 0;
	nb_circles = 0;
	circles_x.clear();
	circles_y.clear();
	circles_r.clear();
	nb_walls = 0;
	walls_xa.clear();
	walls_ya.clear();
	walls_xb.clear();
	walls_yb.clear();
	box_env = box(interval(-10,10),interval(-10,10));
	csMap.xMin = -10; csMap.xMax = 10; csMap.yMin = -10; csMap.yMax = 10; 

	file = fopen("env.txt", "r");
	if (file != NULL)
	{
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		angle_env = M_PI/2.0-d0*M_PI/180.0;

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &lat_env) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &long_env) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &alt_env) != 1) printf("Invalid configuration file.\n");

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &nb_circles) != 1) printf("Invalid configuration file.\n");
		for (i = 0; i < nb_circles; i++)
		{
			if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
			if (sscanf(line, "%lf %lf %lf", &d0, &d1, &d2) != 3) printf("Invalid configuration file.\n");
			circles_x.push_back(d0);
			circles_y.push_back(d1);
			circles_r.push_back(d2);
		}

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%d", &nb_walls) != 1) printf("Invalid configuration file.\n");
		for (i = 0; i < nb_walls; i++)
		{
			if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
			if (sscanf(line, "%lf %lf %lf %lf", &d0, &d1, &d2, &d3) != 4) printf("Invalid configuration file.\n");
			walls_xa.push_back(d0);
			walls_ya.push_back(d1);
			walls_xb.push_back(d2);
			walls_yb.push_back(d3);
		}

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d0) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d1) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d2) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &d3) != 1) printf("Invalid configuration file.\n");
		box_env = box(interval(d0,d1),interval(d2,d3));

		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &csMap.xMin) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &csMap.xMax) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &csMap.yMin) != 1) printf("Invalid configuration file.\n");
		if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (sscanf(line, "%lf", &csMap.yMax) != 1) printf("Invalid configuration file.\n");

		if (fclose(file) != EXIT_SUCCESS) printf("fclose() failed.\n");
	}
	else
	{
		printf("Configuration file not found.\n");
		return EXIT_FAILURE;
	}
#pragma region Parameters check
	if ((nb_circles < 0)||((int)circles_x.size() != nb_circles)||((int)circles_y.size() != nb_circles)||((int)circles_r.size() != nb_circles))
	{
		printf("Invalid parameter : nb_circles.\n");
		nb_circles = 0;
		circles_x.clear(); circles_y.clear(); circles_r.clear();
	}
	if ((nb_walls < 0)||((int)walls_xa.size() != nb_walls)||((int)walls_ya.size() != nb_walls)||((int)walls_xb.size() != nb_walls)||((int)walls_yb.size() != nb_walls))
	{
		printf("Invalid parameter : nb_walls.\n");
		nb_walls = 0;
		walls_xa.clear(); walls_ya.clear(); walls_xb.clear(); walls_yb.clear();
	}
	if ((box_env.IsEmpty())||(box_env[1].inf >= box_env[1].sup)||(box_env[2].inf >= box_env[2].sup))
	{
		printf("Invalid parameter : box_env.\n");
		box_env = box(interval(-10,10),interval(-10,10));
	}
	if ((csMap.xMin == csMap.xMax)||(csMap.yMin == csMap.yMax))
	{
		printf("Invalid parameter : csMap.\n");
		csMap.xMin = -10; csMap.xMax = 10; csMap.yMin = -10; csMap.yMax = 10; 
	}
#pragma endregion
	lat_home = lat_env; long_home = long_env; alt_home = alt_env;

	return EXIT_SUCCESS;
}

inline int SaveEnv(void)
{
	FILE* filein = NULL;
	FILE* fileout = NULL;
	char line[MAX_BUF_LEN];
	int i = 0;

	// Missing error checking...

	memset(line, 0, sizeof(line));

	filein = fopen("env.txt", "r");
	if (filein == NULL)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}
	fileout = fopen("~env.txt", "w");
	if (fileout == NULL)
	{
		printf("Error saving configuration file.\n");
		fclose(filein);
		return EXIT_FAILURE;
	}

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", (M_PI/2.0-angle_env)*180.0/M_PI) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", lat_env) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", long_env) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", alt_env) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", (int)circles_r.size()) < 0) printf("Error writing configuration file.\n");
	for (i = 0; i < (int)circles_r.size(); i++)
	{
		if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (fprintf(fileout, "%.10g %.10g %.10g\n", circles_x[i], circles_y[i], circles_r[i]) < 0) printf("Error writing configuration file.\n");
	}

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%d\n", (int)walls_xa.size()) < 0) printf("Error writing configuration file.\n");
	for (i = 0; i < (int)walls_xa.size(); i++)
	{
		if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
		if (fprintf(fileout, "%.10g %.10g %.10g %.10g\n", walls_xa[i], walls_ya[i], walls_xb[i], walls_yb[i]) < 0) printf("Error writing configuration file.\n");
	}

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", box_env[0].inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", box_env[0].sup) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", box_env[1].inf) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", box_env[1].sup) < 0) printf("Error writing configuration file.\n");

	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", csMap.xMin) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", csMap.xMax) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", csMap.xMin) < 0) printf("Error writing configuration file.\n");
	if (fgetscopy3(filein, fileout, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
	if (fprintf(fileout, "%.10g\n", csMap.xMax) < 0) printf("Error writing configuration file.\n");

	if (fclose(fileout) != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		fclose(filein);
		return EXIT_FAILURE;
	}
	if (fclose(filein) != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}

	if (remove("env.txt") != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}
	if (rename("~env.txt", "env.txt") != EXIT_SUCCESS)
	{
		printf("Error saving configuration file.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

inline int UnloadEnv(void)
{
	// Default values.
	angle_env = M_PI/2.0-90.0*M_PI/180.0;
	lat_env = 0;
	long_env = 0;
	alt_env = 0;
	nb_circles = 0;
	circles_x.clear();
	circles_y.clear();
	circles_r.clear();
	nb_walls = 0;
	walls_xa.clear();
	walls_ya.clear();
	walls_xb.clear();
	walls_yb.clear();
	box_env = box(interval(-10,10),interval(-10,10));
	csMap.xMin = -10; csMap.xMax = 10; csMap.yMin = -10; csMap.yMax = 10; 

	return EXIT_SUCCESS;
}

inline int LoadKeys(void)
{
	FILE* file = NULL;
	char line[MAX_BUF_LEN];
	int i = 0, j = 0;

	// Missing error checking...

	memset(line, 0, sizeof(line));

	// Default values.
	memset(keys, 0, sizeof(keys));
	keys[FWD_KEY] = 'z';
	keys[BWD_KEY] = 's';
	keys[LEFT_KEY] = 'q';
	keys[RIGHT_KEY] = 'd';
	keys[LAT_LEFT_KEY] = 'a';
	keys[LAT_RIGHT_KEY] = 'e';
	keys[BRAKE_KEY] = 'w';
	keys[DEPTHCONTROL_KEY] = 'y';
	keys[ALTITUDEAGLCONTROL_KEY] = 'Y';

	file = fopen("keys.txt", "r");
	if (file != NULL)
	{
		for (i = 0; i < NB_CONFIGURABLE_KEYS; i++)
		{
			if (fgets3(file, line, sizeof(line)) == NULL) printf("Invalid configuration file.\n");
			if (sscanf(line, "%c", &keys[i]) != 1) printf("Invalid configuration file.\n");
		}
		if (fclose(file) != EXIT_SUCCESS) printf("fclose() failed.\n");
	}
	else
	{
		printf("Configuration file not found.\n");
		return EXIT_FAILURE;
	}

	for (i = 0; i < NB_CONFIGURABLE_KEYS; i++)
	{
		for (j = 0; j < NB_CONFIGURABLE_KEYS; j++)
		{
			if ((i != j)&&(keys[i] == keys[j]))
			{
				printf("Invalid parameter : keys[%d] == keys[%d] == '%c' (ASCII code %d).\n", (int)i, (int)j, keys[i], (int)keys[i]);
			}
		}
	}

	return EXIT_SUCCESS;
}

inline int TranslateKeys(int c)
{
	if (c == keys[FWD_KEY]) c = 'z';
	if (c == keys[BWD_KEY]) c = 's';
	if (c == keys[LEFT_KEY]) c = 'q';
	if (c == keys[RIGHT_KEY]) c = 'd';
	if (c == keys[LAT_LEFT_KEY]) c = 'a';
	if (c == keys[LAT_RIGHT_KEY]) c = 'e';
	if (c == keys[BRAKE_KEY]) c = 'w';
	if (c == keys[DEPTHCONTROL_KEY]) c = 'y';
	if (c == keys[ALTITUDEAGLCONTROL_KEY]) c = 'Y';

	return c;
}

inline int DisplayKeys(void)
{
	printf("On OpenCVGUI : \n");
	printf("%c%c%c%c(horizontal control),fvB(vertical control or thrust limit),%c%c(lateral),%c(brake),space(stop),g(generalstop),t%c%cUH(heading, depth, alt_agl, pitch, roll control),"
		"o(toggle OSD),c(toggle North and control),"
		"m(toggle map),M(toggle Map),*(rotate map),i(toggle image),$(toggle sonar),;(other overlays),X(disableopencvgui),+-(coordspace zoom),"
		"O(gpssetenvcoordposition),G(gpslocalization),J(enable/disableautogpslocalization),V(enable/disableautodvllocalization),"
		"Z(resetstateestimation),S(staticsonarlocalization),D(enable/disabledynamicsonarlocalization),"
		"P(snapshot),r(record),p(mission),x(abort),h(help),!(alarms),?(battery),"
		"bn(lights),uNj(camera tilt),F(alt RC mode),.(rearm),0(disarm),"
		"ENTER(extended menu),ESC(exit)\n", 
		keys[FWD_KEY], keys[BWD_KEY], keys[LEFT_KEY], keys[RIGHT_KEY], keys[LAT_LEFT_KEY], keys[LAT_RIGHT_KEY], 
		keys[BRAKE_KEY], keys[DEPTHCONTROL_KEY], keys[ALTITUDEAGLCONTROL_KEY]);

	return EXIT_SUCCESS;
}

inline int DisplayHelp(void)
{
	printf("On the command prompt : \nCheck mission_spec.txt for available commands.\n");
	DisplayKeys();
	return EXIT_SUCCESS;
}

#endif // !CONFIG_H
