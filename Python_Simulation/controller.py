from roblib import *
import math
from chemins import *
from matrice_adjacence import adjacency_matrix
from constantes import *

rayon_gps_bouee = 20 # rayon autour de la bouée dans lequel on a le gps


def calcul_cap(gps_bateau,gps_bouee):
    """
    renvoie le cap que doit prendre le navire pour atteindre la bouée
    """
    return math.atan2(gps_bouee[1]-gps_bateau[1],gps_bouee[0]-gps_bateau[0])


def navigation_cap_favorable(θ,cap):
    """
    fonction qui fait suivre un cap au navire
    ne fonctionne que si le cap est favorable
    """
    if not vent_favorable(cap):
        print('erreur navigation_cap_favorable')
        return None

    θbar = cap
    if cos(θ-θbar)>=0:
        δr = δrmax*sin(θ - θbar)
    else:
        δr = δrmax*sign(sin(θ - θbar))

    δsmax = pi/4 *(cos(ψ - θ)+1)

    # print(δr,δsmax)
    u=array([[δr, δsmax]])
    return u

def vent_favorable(cap):
    """
    renvoie vrai si le bateau peut aller plein cap
    renvoie faux si vent de face -> zigzag nécessaire
    """
    # print(abs((ψ-pi-cap)%(2*pi))) # pour vérifier la plage d'angles favorables à la main
    if abs((ψ-pi-cap)%(2*pi)) <= δrmax:
        return False
    else:
        return True

def navigation_cap(θ,cap,temps_sequence=100):
    """
    fonction qui gère la nav
    pseudo-code:

    si le vent est favorable:
        on suit le cap normalement
    si le vent n'est pas favorable:
        on fait des zigzags en naviguant au près
    """
    global ψ
    α = 2.5 # terme correctif pour que la ligne soit bien suivie
    temps_gauche = temps_sequence*(1+((ψ-pi-cap)%(2*pi))/pi*4 / α)/2 # temps de la sequence ou le navire à le vent à sa gauche
    if not vent_favorable(cap) and navigation_cap.counter == -1:
        navigation_cap.counter += 1
        print('conduite au près a gauche pour ', temps_gauche, '% du temps')
    # print(navigation_cap.counter) # pour vérifier le counter statique
    if vent_favorable(cap):
        return navigation_cap_favorable(θ,cap)
    else:
        # 1+( (ψ-pi-θ)%(2*pi) )/pi*4: pour adapter le temps de chaque demi parcours
        if navigation_cap.counter <= temps_gauche or navigation_cap.counter > temps_sequence:
            if navigation_cap.counter > temps_sequence:
                navigation_cap.counter = 0
            cap1 = pi + ψ - ζ # le vent attaque la droite du navire
            if not cap_correct(θ,cap1): # tant que le bateau est mal orienté...
                # print("O1")
                return navigation_cap_favorable(θ,cap1) # on oriente le bateau vers son cap
            else:
                navigation_cap.counter += 1 # sinon on avance d'un pas dans la direction donnée par le cap
                # print("1")
                return navigation_cap_favorable(θ,cap1)
        else:
            cap2 = pi + ψ + ζ # le vent attaque la gauche du navire
            if not cap_correct(θ,cap2): # tant que le bateau est mal orienté...
                # print("O2")
                return navigation_cap_favorable(θ,cap2) # on oriente le bateau vers son cap
            else:
                # print("2")
                navigation_cap.counter += 1
                return navigation_cap_favorable(θ,cap2)
navigation_cap.counter = -1

def cap_correct(θ,cap,tolerance_angulaire = pi/12):
    """
    renvoie true si le cap est celui demandé, false sinon
    """
    if abs(cap-θ) <= tolerance_angulaire:
        return True
    else:
        return False

def controller(x,point):
    """
    inputs:
        x: vecteur d'état
        point: coordonnées x,y du point a atteindre
    outputs:
        U: commande a effectuer pour aller au point en ligne droite
    """
    θ = x[2,0]
    cap = calcul_cap(x,point)
    U = navigation_cap(θ,cap)
    return U