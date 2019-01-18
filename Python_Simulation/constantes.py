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
liste_centre_bouee = [np.array([[75],[-75]]),np.array([[100],[-25]]),np.array([[100],[25]]),np.array([[75],[75]])]
rayon_gps_bouee = 20 # rayon autour de la bouée dans lequel on a le gps

target = 4 # bouée visée

initial_x = array([[25.,-75.,0.,0.,0.]]).T
