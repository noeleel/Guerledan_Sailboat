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

// Define the macros for the maximum angle of vision MAX_ANGLE



#include "WhichWay.h"

int compute_adjacency(float distance, float alpha, float r_vision){
    if (distance*tan(alpha) <= r_vision)
        return 1
    else
        return 0
}

void compute_matrix(double[4][2] List_of_buoys,int[4][4] Matrix){
        int i = 0;
        int j = 0;
        float distance = 0;
        float alpha_max = 0;
        float r_vision = 0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if (i==j)
                    Matrix[i][j] = 1;
                else{
                    distance = sqrt(pow(List_of_buoys[i][0] - List_of_buoys[j][0],2) + pow(List_of_buoys[i][1] - List_of_buoys[j][1],2))
                    Matrix[i][j] = compute_adjacency(distance, alpha_max, r_vision);
                }
            }
        }
}

int[4] mission_Indices(int[4][2]List_of_buoys){
    int[4] List_indices;
    int i = 0;
    int j = 0;
    List_indices[0] = 1;
    int[4][4]Adjacency_Matrix;
    compute_matrix(List_of_buoys, Adjacency_Matrix)
    for(i=0; i<4; i++){
        if (Adjacency_Matrix[i][(i+1)%4] == 1 and i!=j){
            List_indices[(i+1)%4]= i+1;
        }
    }
    return List_indices;

}
