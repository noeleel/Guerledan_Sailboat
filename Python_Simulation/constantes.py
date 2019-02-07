# contient toutes les constantes liées au problèmes
# les variables partagées dynamiques ne doivent pas être mises ici
# pourrait etre traité par un parser si on le souhaite
from roblib import *

p0,p1,p2,p3,p4,p5,p6,p7,p8,p9 = 0.1,1,6000,1000,2000,1,1,2,300,10000
ζ = pi/3
δrmax = pi/4
q = 1
θw = 0

dt = 0.1 # vitesse simulation
awind,ψ = 5,0.01 # vitesse et angle du vent

# Coordonnées des bouées:
#liste_centre_bouee = [array([[50],[-75]]),array([[100],[-25]]),array([[100],[25]]),array([[50],[75]])]
liste_centre_bouee = [np.array([[-75],[-25]]),np.array([[-25],[25]]),np.array([[50],[0]]),np.array([[125],[25]]),np.array([[175],[-50]])]
rayon_gps_bouee = 10 # rayon autour de la bouée dans lequel on a le gps

target = 5 # bouée visée

initial_x = array([[-150,0.,0.,0.,0.]]).T

# zone de securite 
zone = np.array([[-175.0,-160.0,-60.0,120.0,150.0,195.0,195.0,185.0,160.0,120.0,-90.0,-120.0,-140.0,-195.0,-195.0,-175.0],
				[-95.0,-50.0,-60.0,-15.0,-90.0,-85.0,95.0,95.0,65.0,70.0,20.0,20.0,95.0,95.0,-95.0,-95.0]])
distance_securite = 30 # distance evitee entre le robot et les cotes