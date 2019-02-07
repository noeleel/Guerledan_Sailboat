# mission.py
# fonctions qui permettent de calculer quel point est notre cible actuelle
from constantes import *
from chemins import *
from matrice_adjacence import *


# def calcul_cap(gps_bateau,gps_bouee):
#     """
#     renvoie le cap que doit prendre le navire pour atteindre la bouée
#     """
#     return math.atan2(gps_bouee[1]-gps_bateau[1],gps_bouee[0]-gps_bateau[0])


def gps_disponible(x,y,liste_centre_bouee,rayon_gps_bouee):
    for centre_bouee in liste_centre_bouee:
        xb, yb = centre_bouee[0],centre_bouee[1]
        if (x-xb)**2 + (y-yb)**2 <= rayon_gps_bouee**2:
            return True
    return False

def nav_bouee(x):
    if gps_disponible(x[0,0],x[1,0],liste_centre_bouee,rayon_gps_bouee):
        # cap = calcul_cap([x[0,0],x[1,0]],liste_centre_bouee[liste_bouees_nav[nav_bouee.bouee_suivante]])
        if nav_bouee.go_next:
            nav_bouee.go_next = False
            nav_bouee.bouee_suivante += 1
        else:
            pass
    else:
        nav_bouee.go_next = True
    nav_bouee.bouee_suivante = min(nav_bouee.bouee_suivante,len(liste_bouees_nav)-1)
    pass
nav_bouee.go_next = True # variable qui permet de savoir si on a perdu le gps ou si on l'avait à l'état précédent - permet de savoir que l'on quitte une bouée


def name_to_id(x):
    """
    transcrit le nom de la bouée en son indice dans la liste python 'liste_centre_bouees'
    """
    if x == 'B1':
        return 0
    if x == 'B2':
        return 1
    if x == 'B3':
        return 2
    if x == 'B4':
        return 3
    if x == 'B5':
        return 4

def mission(x):
    nav_bouee(x)
    return liste_centre_bouee[liste_bouees_nav[nav_bouee.bouee_suivante]]

    
m_a = adjacency_matrix(initial_x[:2,:],liste_centre_bouee)
p = path_matrix(l=['N','B1','B2','B3','B4','B5'], m = m_a)
    
best_path = get_best_path(target,liste_centre_bouee,p).l[1:]
liste_bouees_nav = [name_to_id(x) for x in best_path]
nav_bouee.bouee_suivante = liste_bouees_nav[0] # définition d'une variable statique pour la fonction nav_bouee
# print(liste_bouees_nav,nav_bouee.bouee_suivante)

