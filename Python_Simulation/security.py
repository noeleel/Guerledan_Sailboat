# vérifie que le voilier reste dans les bornes fixées, sinon force une autre mission.
import numpy as np
from constantes import *

def security(ax, x):
	distance_intersection = float("inf")
	intersection = array([0,0])
	ax.plot(zone[0], zone[1], '-', linewidth=3, color='firebrick')
	intersections = []
	for i in range(zone.shape[1]):
		A = array([[zone[0][i-1]],[zone[1][i-1]]])
		B = array([[zone[0][i]],[zone[1][i]]])
		if (A == B).all() :
			pass 
		else:
			if A[0] == B[0]:
				c = tan(x[2])
				d = x[1] - c*x[0]
				xi = A[0]
				yi = c*xi + d
				if yi < max(A[1],B[1]) and yi > min(A[1],B[1]):
					angle = arctan2((yi - x[1]),(xi-x[0]))
					if round(angle,2) == round(x[2],2) and distance_intersection > norm(array([xi,yi])-x[:2]):
						distance_intersection = norm(array([xi,yi])-x[:2])
						intersection = array([xi,yi])
			else:
				a = (A[1]-B[1])/(A[0]-B[0])
				b = B[1] -a*B[0]
				c = tan(x[2])
				d = x[1] - c*x[0]
				if round(a,5) != round(c,5):
					xi = (d - b)/(a - c)
					yi = c*xi + d
					if xi < max(A[0],B[0]) and xi > min(A[0],B[0]):
						angle = arctan2((yi - x[1]),(xi-x[0]))
						if (round(angle,2) == round(x[2],2))  and distance_intersection > norm(array([xi,yi])-x[:2]):
							distance_intersection = norm(array([xi,yi])-x[:2])
							intersection = array([xi,yi])

	if (intersection != array([0,0])).all():
		draw_disk(intersection,2,ax,"orange",α=0.8)
	if distance_intersection < distance_securite:
		pass
		# x[2] = x[2] + pi/4
		# x[2] = x[2] - pi/4


