from numpy import array,cos,sin,sign
from roblib import angle
from numpy.linalg import norm
from constantes import *

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