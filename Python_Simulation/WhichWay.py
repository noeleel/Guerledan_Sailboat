from roblib import *
from fonction_etat import f # Physical model of the sailboat
import numpy as np
from random import shuffle

# parse a file for having the graph of buoys

X_MAX_LIM = 60
Y_MAX_LIM = 60
X_MIN_LIM = -60
Y_MIN_LIM = -60
MAX_DISTANCE = 70

alpha_max = 40 #Used to define the angle of vision, depend of the camera
# Default configuration 5 buoy 
# 4 orange
# 1 red
r_vision_buoy = 3 # In we are in this area, we will be able to see the buoy, otherwise not possible.

#Black Buoy
black_buoy = np.array([[-45],[0]]).reshape((2,1))

# Oranges buoy
buoy_1 = np.array([[-40],[-10]]).reshape((2,1))
buoy_2 = np.array([[-10],[10]]).reshape((2,1))
buoy_3 = np.array([[30],[15]]).reshape((2,1))
buoy_4 = np.array([[45],[-0]]).reshape((2,1))
List_buoy = [buoy_1, buoy_2, buoy_3, buoy_4]

def draw_buoy():
    draw_disk(black_buoy, r_vision_buoy, ax, 'blue')
    draw_disk(black_buoy, 0.5, ax, 'black')
    plt.text(black_buoy[0], black_buoy[1], "Black buoy [?,?]", fontsize=12)
    i = 1
    for buoy in List_buoy:
        draw_disk(buoy, r_vision_buoy, ax, 'blue')
        draw_disk(buoy, 0.5, ax, 'orange')
        plt.text(buoy[0], buoy[1], "Buoy " + str(i) + " " + str([buoy[0], buoy[1]]), fontsize=12)
        i+=1

List_of_buoy = [buoy_1.flatten(), buoy_2.flatten(), buoy_3.flatten(), buoy_4.flatten(),black_buoy.flatten()]
# Used for showing the graph of buoy

def compute_adjacency(x, r = r_vision_buoy, alpha = alpha_max):
    distance = np.linalg.norm(x)
    if distance*np.tan(alpha) <= r and distance < MAX_DISTANCE:
        return distance
    return 0

def compute_matrix(A = List_of_buoy):
    Matrice = np.zeros((len(A), len(A))) # Matrice d'adjacence
    for i in range(Matrice.shape[0]):
        for j in range(Matrice.shape[1]):
            if i == j:
                Matrice[i,j] = 1
            else:
                Matrice[i,j] = compute_adjacency(A[i] - A[j])
    return Matrice


def draw_graph(M):
    for i in range(M.shape[0]):
        for j in range(M.shape[1]):
            if M[i,j] ==  M[j,i] and M[i,j] > 0:
                col = 'green'
            elif M[i,j] > 0: 
                col = 'blue'
            elif M[j,i] > 0: 
                col = 'orange'
            else:
                col = 'red'
            x = [List_of_buoy[i][0], List_of_buoy[j][0]]
            y = [List_of_buoy[i][1], List_of_buoy[j][1]]
            plt.plot(x, y, color = col)

# Mission in case we want to follow a precise path of buoy
List_indices_precise_path = shuffle([1,2,3,4])

# Mission in case we want to follow a path of buoy with the Djikistra algorithm
# Utilisez les matrices de chemins ici
def array_to_list(arr):
    arr = arr.flatten().flatten()
    L = []
    for x in arr:
        if x == 0:
            L+=[max(arr)]
        else:
            L+=[x]
    return L

# Retourne une liste d'indices
def mission_djikistra(M):
    List_indices = []
    for i in range(M.shape[0]):
        # Get the distance from others buoys
        L = array_to_list(M[i,:].flatten())
        # Remove the distance from the buoy to itself
        print(L[i])
        L[i] = max(L)
        # Remove any other buoy that have already been seen
        print(L)
        for j in range(len(List_indices)):
            print(L[j])
            L[j] = max(L)

        # See shortest buoy for each buoy
        value = min(L)
        print(L)
        ind = np.where(L == value)[0]
        print(ind)
        List_indices+=[ind]
    return List_indices


# Mission in case we want to go to the black_buoy and go back on the right path 
# Default mission : we want to follow n buoy in numerical order
List_indices_default = [1,2,3,4]

# Add a check to assert we want see the buoy

# Return the wanted path 
def path(L = List_indices_default):
    print(L)

if __name__=="__main__":
    #fig = plt.figure(0)
    #ax = fig.add_subplot(111, aspect='equal')
    #ax.set_xlim(X_MIN_LIM,X_MAX_LIM)
    #ax.set_ylim(Y_MIN_LIM,Y_MAX_LIM)
    #draw_buoy()
    M = compute_matrix(List_of_buoy)
    #draw_graph(M)
    Matrix = compute_matrix(List_of_buoy[:-1])
    print(Matrix)
    List = mission_djikistra(Matrix)
    path(List)
    plt.show()
