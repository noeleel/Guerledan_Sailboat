from roblib import *
from constantes import *

def get_position(X,destination):
	"""
	SLAM améliore la precision de l'estimation de position sur la trajectoire
	Input :
		- X : vecteur d'état du robot
		- destination: position a atteindre
	"""
	print(destination)
	v = X[3,0] # vitesse
	x = np.array([[X[0,0]],[X[1,0]]]) # position

	# paramètres kalman
	eta = 0.9
	y      = np.eye(0,1)
	Galpha = 0.01*np.eye(2)
	Gbeta  = np.eye(0,0)
	A      = np.eye(2)
	C      = np.eye(0,2)

	# calcule le cap où le robot doit avancer vers la bouee 
	cap = X[2,0]
	# cap = np.arctan2(destination[1] - x[1,0],destination[0] - x[0,0])
	print(cap)
	# estimation de position
	uk = dt* np.array([[np.cos(cap)],[np.sin(cap)]])*v
	x,get_position.Gx = kalman(x,get_position.Gx,uk,y,Galpha,Gbeta,A,C)
	print(x)
	X[0,0], X[1,0] = x[0,0,0], x[0,1,0]
	pass
get_position.Gx = np.zeros((2,2))

# centres_bouee = [np.array([[50],[-50]]),np.array([[100],[-25]]),np.array([[100],[25]]),np.array([[50],[50]])]
# rayon_bouee = 20
# num_bouee = 0 # numero de bouee

# x = np.array([[0],[0]]) # position (x,y)
# vr = np.array([[10],[10]]) # vitesse (vx,xy)
# # Gx = np.zeros((2,2)) # matrice de covariance

# dt = 0.1
# ax=init_figure(-20,200,-100,100)

# for t in arange(0,150,dt):
# 	clear(ax)

# 	if (x[0,0]-centres_bouee[num_bouee][0,0])**2 + (x[1,0]-centres_bouee[num_bouee][1,0])**2 <= rayon_bouee**2:
# 		print("bouée suivant")
# 		num_bouee+=1
# 		if num_bouee > len(centres_bouee)-1:
# 			break

# 	x,Gx = get_position(centres_bouee[num_bouee],x,vr,Gx,dt)
	
# 	plt.plot([x[0][0]],[x[1][0]],'ro')

# 	# s = np.arange(0,2.3*np.pi,0.05)
# 	# u = np.array([np.cos(s),np.sin(s)]) #Cercle_unite

# 	# joker = x
# 	# w = joker*np.ones((2,len(s))) + sqrtm(-2*np.log(1-eta)*Gx[0:2][:,0:2])@u
# 	# plt.plot(w[0],w[1],'blue')

# 	for centre in centres_bouee:
# 	    draw_disk(centre,2,ax,"orange",α=0.8)
# 	for centre in centres_bouee:
# 		draw_disk(centre,rayon_bouee,ax,"cyan",α=0.2)

# 	pause(0.01) 
