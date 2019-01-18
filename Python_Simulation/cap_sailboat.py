from roblib import *
from numpy.linalg import det,norm
import numpy as np 
    
def f(x,u):
    # f simule le comportement du bateau (calcul force vent etc)
    x,u=x.flatten(),u.flatten()
    # x = vecteur état, θ = angle du navire, v = vitesse, w = vitesse angulaire
    # δr = angle gouvernail (rudder en anglais), δsmax = limite de tension de la voile (relachement de la cordelette du voilier avec cerveau moteur)
    θ=x[2]; v=x[3]; w=x[4]; δr=u[0]; δsmax=u[1];
    w_ap = array([[awind*cos(ψ-θ) - v],[awind*sin(ψ-θ)]])
    ψ_ap = angle(w_ap)
    a_ap=norm(w_ap)
    sigma = cos(ψ_ap) + cos(δsmax)
    if sigma < 0 :
        δs = pi + ψ_ap
    else :
        δs = -sign(sin(ψ_ap))*δsmax
    fr = p4*v*sin(δr)
    fs = p3*a_ap* sin(δs - ψ_ap)
    dx=v*cos(θ) + p0*awind*cos(ψ)
    dy=v*sin(θ) + p0*awind*sin(ψ)
    dv=(fs*sin(δs)-fr*sin(δr)-p1*v**2)/p8
    dw=(fs*(p5-p6*cos(δs)) - p7*fr*cos(δr) - p2*w*v)/p9
    xdot=array([ [dx],[dy],[w],[dv],[dw]])
    return xdot,δs    

ζ = pi/3
δrmax = pi/4
q = 1
θw = 0
def controler(x):
    global q,ψ
    x=x.flatten()
    m=pos
    θ=x[2]
    plot([a[0,0],b[0,0]],[a[1,0],b[1,0]],'red')
    e = det(np.concatenate(((b-a)/norm(b-a),m-a),axis = 1))
    if np.abs(e)>r/2:
        q = sign(e)
    droite = b-a
    # print(droite)
    ϕ = np.arctan2(droite[1,0],droite[0,0])
    # print(ϕ)
    θstar = ϕ - 1/2*np.arctan(e/r)

    if cos(ψ - θstar) + cos(ζ) < 0 or (np.abs(e) < r and (cos(ψ-ϕ)+cos(ζ) < 0)):
        θbar = pi + ψ - q*ζ
    else:
        θbar = θstar


    if cos(θ-θbar)>=0:
        δr = δrmax*sin(θ- θbar)
    else:
        δr = δrmax*sign(sin(θ- θbar))

    δsmax = pi/4 *(cos(ψ - θ)+1)

    # print(δr,δsmax)
    u=array([[δr, δsmax]])
    return u
def navigation_cap_favorable(x,cap):
    global ψ
    x=x.flatten()
    θ=x[2]
    θbar = cap
    if cos(θ-θbar)>=0:
        δr = δrmax*sin(θ- θbar)
    else:
        δr = δrmax*sign(sin(θ- θbar))

    δsmax = pi/4 *(cos(ψ - θ)+1)

    # print(δr,δsmax)
    u=array([[δr, δsmax]])
    return u

def vent_favorable(cap):
    """
    renvoie vrai si le bateau peut aller plein cap
    renvoie faux si vent de face -> zigzag nécessaire
    """
    global ψ
    # print(abs((ψ-pi-cap)%(2*pi))) # pour vérifier la plage d'angles favorables à la main
    if abs((ψ-pi-cap)%(2*pi)) <= δrmax:
        return False
    else:
        return True

def navigation_cap(x,cap,half_time=50):
    global ψ
    # print(navigation_cap.counter) # pour vérifier le counter statique
    if vent_favorable(cap):
        return navigation_cap_favorable(x,cap)
    else:

        θ = x[2,0]
        print( half_time*(1+((ψ-pi-cap)%(2*pi))/pi*4))
        # 1+(ψ-pi-θ)/pi*4: pour adapter le temps de chaque demi parcours
        if navigation_cap.counter <= half_time*(1+((ψ-pi-cap)%(2*pi))/pi*4) or navigation_cap.counter > 2*half_time:
            if navigation_cap.counter > 2*half_time:
                navigation_cap.counter = 0
            cap1 = θbar = pi + ψ - ζ # le vent attaque la droite du navire
            if not cap_correct(x,cap1): # tant que le bateau est mal orienté...
                print("O1")
                return navigation_cap_favorable(x,cap1) # on oriente le bateau vers son cap
            else:
                navigation_cap.counter += 1 # sinon on avance d'un pas dans la direction donnée par le cap
                print("1")
                return navigation_cap_favorable(x,cap1)
        else:
            cap2 = θbar = pi + ψ + ζ # le vent attaque la gauche du navire
            if not cap_correct(x,cap2): # tant que le bateau est mal orienté...
                print("O2")
                return navigation_cap_favorable(x,cap2) # on oriente le bateau vers son cap
            else:
                print("2")
                navigation_cap.counter += 1
                return navigation_cap_favorable(x,cap2)
navigation_cap.counter = 0

def cap_correct(x,cap,tolerance_angulaire = pi/12):
    """
    renvoie true si le cap est celui demandé, false sinon
    """
    θ = x[2,0]
    if abs(cap-θ) <= tolerance_angulaire:
        return True
    else:
        return False

def setup(x,θw):
    # crée le vecteur [a,b] que le bateau va suivre
    global a,b
    a = - 1000*array([[cos(θw)],
                       [sin(θw)]])
    b = + 1000*array([[cos(θw)],
                       [sin(θw)]])
    return None

pos = array([[0.],
             [0.]])
def update_pos(x,dt,pos):
    # print(x[3,0])
    pos += dt * array([[x[3,0]*cos(x[2,0])],
                  [x[3,0]*sin(x[2,0])]])
    return pos

r = 50 # distance à la ligne tolérée
    
p0,p1,p2,p3,p4,p5,p6,p7,p8,p9 = 0.1,1,6000,1000,2000,1,1,2,300,10000
x = array([[0,0,2,0,0]]).T   #x=(x,y,θ,v,w)

dt = 0.1
awind,ψ = 5,-pi # vitesse et angle du vent   
# a = array([[-50],[-100]])   
# b = array([[50],[100]])
                  
ax=init_figure(-20,180,-60,60)

for t in arange(0,40,dt):
    #print('one\n')
    clear(ax)
    # setup(x,0)
    # u = controler(x)
    cap = 0
    # print(vent_favorable(cap))
    u = navigation_cap(x,cap)
    # print('angle voile %0.2f π'%(u[0,1]/pi))
    xdot,δs=f(x,u)
    x = x + dt*xdot
    pos = update_pos(x,dt,pos)
    # print("x ",pos[0,0],"y ",pos[1,0])
    # print(x)
    #print(x,δs,u[0,0],ψ,awind)
    draw_sailboat(x,δs,u[0,0],ψ,awind,int(t))
    x2 = x.copy()

    ######### bateau fantome ############
    # x2[0,0], x2[1,0] = pos[0,0], pos[1,0]
    # draw_sailboat(x2,δs,u[0,0],ψ,awind)




# if vent & cap compatibles:
#     while navire non orienté:
#         action gouvernail pour tourner à droite ou a gauche
#         (possible jeu sur la tension de la voile)
#         pass

#     while navire orienté:
#         if voile ok:
#             sleep(1) # on ne doit sleep que ce thread, pas les autres, python gère pas ca comme il faut
#             -> le bateau avance comme il faut
#         else:
#             tension voile
#             sleep(1) #pour laisser le temps à l'action de se faire


# else:
#     dent de scie :# on evite la trajectoire impossible en alternant entre 2 trajectoires limite
#         choix de trajectoire
#         suivi de cap compatible 1 pour t1 secondes
#         suivi de cap compatible 2 pour t2 secondes



# 3 fonctions de vérif qui renvoient true ou false:
#     verif gouvernail orienté,
#     verif voile tendue,
#     verif cap correct

# 2 fonctions de correction qui influencent les cerveaux - vecteur commande U:
#     orientation navire/gouvernail
#     tension voile

# 1 fonction qui gère le fonctionnement en conditions normales:
#     pilotage_conditions_nominales
# 1 fonction qui gère la dent de scie, qui repose sur la fonction ci dessus
#     pilotage_dent_scie
