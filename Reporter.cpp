// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include "Reporter.h"

/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

void createLogFile(){
    // current date/time based on current system
   time_t now_time = time(0);
   
   // convert now to string form
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
   char* current_time = ctime(&now_time);
=======
   char* current_time = ctime(&now);
>>>>>>> MaJ Github

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now_time);
   current_time = asctime(gmtm);

   // create an ofstream for the file output
   ofstream outputFile;
   ofstream fs
   std::string filename = "LogReporter_" + current_time;
   // create and open the .csv file
   fs.open(outputFile,filename);
   outputFile << "Column A" << "," << "Column B" << "Column C" << std::endl;
   outputFile.close();
   printf("Log file for Guerledan Sailboat successfully created under the name %s\n", &filename);
    
}