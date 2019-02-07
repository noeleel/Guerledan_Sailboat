# from roblib import init_figure
from numpy import array, arange
from constantes import *
from security import *

from mission import mission
from controller import controller
from fonction_etat import f
from SLAM import get_position

def init_figure(background,size):
    fig = figure(0, figsize = (20,10))
    ax = fig.add_subplot(111, aspect='equal')
    ax.background = plt.imread(background)
    ax.size = size 
    ax.imshow(ax.background,extent=ax.size)
    ax.xmin=ax.size[0]
    ax.xmax=ax.size[1]
    ax.ymin=ax.size[2]
    ax.ymax=ax.size[3]
    clear(ax)
    return ax

def clear(ax):
    pause(0.001)
    cla()
    ax.imshow(ax.background,extent=ax.size)  
    ax.set_xlim(ax.xmin,ax.xmax)
    ax.set_ylim(ax.ymin,ax.ymax)

def draw_sailboat(x,δs,δr,ψ,awind,title='titre',color='red',color_chassis="white"):
    x=x.flatten()
    θ=x[2]
    hull=array([[-1,5,7,7,5,-1,-1,-1],[-2,-2,-1,1,2,2,-2,-2],[1,1,1,1,1,1,1,1]])
    sail=array([[-7,0],[0,0],[1,1]])
    rudder=array([[-1,1],[0,0],[1,1]])
    R=array([[cos(θ),-sin(θ),x[0]],[sin(θ),cos(θ),x[1]],[0,0,1]])
    Rs=array([[cos(δs),-sin(δs),3],[sin(δs),cos(δs),0],[0,0,1]])
    Rr=array([[cos(δr),-sin(δr),-1],[sin(δr),cos(δr),0],[0,0,1]])
    # draw_arrow(x[0]+5,x[1],ψ,5*awind,color)
    plot2D(R@hull,color_chassis);       
    plot2D(R@Rs@sail,color);       
    plot2D(R@Rr@rudder,color);
    plt.title(title)

def main(x=initial_x,ax=init_figure("guerledan.png",[-200,200,-100,100])):
	""" boucle principale """
	x_hat = x.copy() # position estimée
	# cap = 0
	for t in arange(0,150,dt):
		clear(ax)
		point = mission(x)
		x_hat[2,0],x_hat[3,0],x_hat[4,0] = x[2,0],x[3,0],x[4,0]

		get_position(x_hat,point) # màj position avec slam
		u = controller(x,point)

		xdot,δs=f(x,u)
		x = x + dt*xdot
		security(ax,x_hat)
		
		for centre_bouee in liste_centre_bouee:
			draw_disk(centre_bouee,2,ax,"orange",α=0.8)
		for centre_bouee in liste_centre_bouee:
			draw_disk(centre_bouee,rayon_gps_bouee,ax,"cyan",α=0.2)
		draw_arrow(-175,50,ψ,2*awind,'white')
		draw_sailboat(x,δs,u[0,0],ψ,awind,str(t))
		draw_sailboat(x_hat,δs,u[0,0],ψ,awind,str(round(t,2)),color='green', color_chassis= "yellow")
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