from roblib import init_figure
from numpy import array, arange
from constantes import *

from mission import mission
from controller import controller
from fonction_etat import f
from SLAM import get_position

def main(x=initial_x,ax=init_figure(-50,150,-100,100)):
    """ boucle principale """
    x_hat = x.copy() # position estimée
    # print(x)
    # print(x_hat)
    cap = 0
    for t in arange(0,50,dt):
        #print('one\n')
        clear(ax)
        # cap = calcul_cap([x[0,0],x[1,0]],liste_centre_bouee[0])
        
        point = mission(x)
        # print(point)
        x_hat[2,0],x_hat[3,0],x_hat[4,0] = x[2,0],x[3,0],x[4,0]

        # print(x[3,0],x_hat[3,0])
        get_position(x_hat,point) # màj position avec slam
        u = controller(x,point)

        xdot,δs=f(x,u)
        # print(x[0,0],x[1,0])
        # print(x[0,0],x[1,0])

        x = x + dt*xdot
        for centre_bouee in liste_centre_bouee:
            draw_disk(centre_bouee,2,ax,"orange",α=0.8)
        for centre_bouee in liste_centre_bouee:
            draw_disk(centre_bouee,rayon_gps_bouee,ax,"cyan",α=0.2)
        # draw_polygon(polygone_test,ax,"blue")
        draw_sailboat(x,δs,u[0,0],ψ,awind,int(t))
        draw_sailboat(x_hat,δs,u[0,0],ψ,awind,color='green')

    return None


if __name__ == "__main__":
    main(initial_x)


    from threading import Thread

    def func1():
        print('Working')

    def func2():
        print('Working')

    if __name__ == '__main__':
        Thread(target = func1).start()
        Thread(target = func2).start()