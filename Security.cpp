// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

#include "Security.h"

bool IsItSafe(){
    double latitude = getLatitude();
    double longitude = getLongitude();
    if ((abs(latitude) > MIN_LATITUDE )&& (abs(latitude) < MAX_LATITUDE) && (abs(longitude) > MIN_LONGITUDE) && (abs(longitude) < MAX_LONGITUDE) )
        return true;
    else
        return false;
};

bool AssertVariablesClose(void){
    bool InSafety = true;
    // Check for the safety of x and y 
    double real_x_boat = getPosition_x();
    double real_y_boat = getPosition_y();
    if ((abs(guer_boat_x - real_x_boat) < 10) || (abs(guer_boat_y - real_y_boat) < 10))
        InSafety = true;
    else
        InSafety = false;
    // Check for the safety of the speed

    // Check for the safety of the wind 
    return InSafety;
}

bool SelectController(bool safe){
    bool UseOurController = true;
    switch(safe){
        case true:
            UseOurController = true;
        case false:
            UseOurController = false;

        default:
            UseOurController = false;

    }
    return UseOurController;
};
