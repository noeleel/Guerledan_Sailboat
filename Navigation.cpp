
// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include "Navigation.h"

bool vent_favorable(double cap) {
	double psiw = Center(psitwindhat); // variable psi dans le code python
	if (abs(fmod((psiw - M_PI - cap), (2 * M_PI))) <= M_PI / 4.0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void navigation_cap_favorable(double theta, double cap) {
	double deltar = 0.0;
	if (!vent_favorable(cap))
	{
		fprintf(stderr, "erreur nav cap favorable #########################");
		return;
	}
	double psiw = Center(psitwindhat); // variable psi dans le code python
	if (cos(theta - cap)>=0)
	{
		deltar = sin(theta - cap);
	}
	else
	{
		deltar = sign(sin(theta - cap),0.0);
	}

	double deltasmax = M_PI / 4.0 * (cos(psiw - theta) + 1);
	commande_gouvernail = -deltar;
	commande_voile = deltasmax;
	// fprintf(stderr, "%f commande voile\n", );
	// fprintf(stderr, "%f commande gouvernail\n", commande_gouvernail);
	return;
}


bool cap_correct(double theta, double cap, double tolerance) {
	double psiw = Center(psitwindhat); // variable psi dans le code python
	if (abs(cap - theta) <= tolerance)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


void navigation_cap(double theta, double cap, double temps_sequence) {
	static int counter = -1;
	//fprintf(stderr, "temps seq: %i\n", counter);
	double psiw = Center(psitwindhat); // variable psi dans le code python
	double alpha = 2.5;
	double temps_gauche = temps_sequence*(1.0+(fmod(psiw-M_PI-cap,2.0*M_PI)/M_PI*4.0/alpha))/2.0;
	if (vent_favorable(cap))
	{
		navigation_cap_favorable(theta, cap);
	}
	else
	{
		if ((counter <= temps_gauche) || (counter >= temps_sequence))
		{
			if (counter > temps_sequence)
			{
				counter = 0;
			}
			double cap1 = M_PI + psiw - angle_critique;
			if (!cap_correct(theta,cap1))
			{
				navigation_cap_favorable(theta,cap1);
			}
			else
			{
				counter++;
				navigation_cap_favorable(theta, cap1);
			}
		}
		else
		{
			double cap2 = M_PI + psiw + angle_critique;
			if (!cap_correct(theta,cap2))
			{
				navigation_cap_favorable(theta, cap2);
			}
			else
			{
				counter++;
				navigation_cap_favorable(theta, cap2);
			}
		}
	}
}
