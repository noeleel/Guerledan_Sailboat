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
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
<<<<<<< f18921b102f1927e95f9e63c7177a61528cb0fb5
        return 1;
    else
        return 0;
}

void compute_matrix(double List_of_buoys[4][2], int Matrix[4][4]){
=======
        return 1
=======
        return 1;
>>>>>>> MaJ Github
    else
        return 0;
}

<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
void compute_matrix(double[4][2] List_of_buoys,int[4][4] Matrix){
>>>>>>> WhichWay
=======
void compute_matrix(double List_of_buoys[4][2], int Matrix[4][4]){
>>>>>>> MaJ Github
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
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
<<<<<<< f18921b102f1927e95f9e63c7177a61528cb0fb5
                    distance = sqrt(pow(List_of_buoys[i][0] - List_of_buoys[j][0],2) + pow(List_of_buoys[i][1] - List_of_buoys[j][1],2));
=======
                    distance = sqrt(pow(List_of_buoys[i][0] - List_of_buoys[j][0],2) + pow(List_of_buoys[i][1] - List_of_buoys[j][1],2))
>>>>>>> WhichWay
=======
                    distance = sqrt(pow(List_of_buoys[i][0] - List_of_buoys[j][0],2) + pow(List_of_buoys[i][1] - List_of_buoys[j][1],2));
>>>>>>> MaJ Github
                    Matrix[i][j] = compute_adjacency(distance, alpha_max, r_vision);
                }
            }
        }
}

<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
<<<<<<< f18921b102f1927e95f9e63c7177a61528cb0fb5
void mission_Indices(int List_indices[4] , double List_of_buoys[4][2]){
    int i = 0;
    int j = 0;
    List_indices[0] = 1;
    int Adjacency_Matrix[4][4] ;
    compute_matrix(List_of_buoys, Adjacency_Matrix);
    for(i=0; i<4; i++){
        if (Adjacency_Matrix[i][(i+1)%4] == 1 && i!=j){
            List_indices[(i+1)%4]= i+1;
        }
    }
=======
int[4] mission_Indices(int[4][2]List_of_buoys){
    int[4] List_indices;
=======
void mission_Indices(int List_indices[4] , double List_of_buoys[4][2]){
>>>>>>> MaJ Github
    int i = 0;
    int j = 0;
    List_indices[0] = 1;
    int Adjacency_Matrix[4][4] ;
    compute_matrix(List_of_buoys, Adjacency_Matrix);
    for(i=0; i<4; i++){
        if (Adjacency_Matrix[i][(i+1)%4] == 1 && i!=j){
            List_indices[(i+1)%4]= i+1;
        }
    }
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
    return List_indices;

>>>>>>> WhichWay
=======
>>>>>>> MaJ Github
}
