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


bool IsItSafe(double x_boat, double y_boat){
    double real_x_boat = getPosition_x();
    double real_y_boat = getPosition_y();
    if (x_boat == real_x_boat && y_boat == real_y_boat)
        return true;
    else
        return false;
};

bool AssertVariablesClose(void){

    bool InSafety = true;
    double real_x_boat = getPosition_x();
    double real_y_boat = getPosition_y();
    if (abs(guer_boat_x - real_x_boat) < 1 and abs(guer_boat_y == real_y_boat) < 1)
        InSafety = true;
    else
        InSafety = false;
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
