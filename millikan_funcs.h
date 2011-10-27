#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

namespace millikan{
//-------------------------------------------------------------------------------------------------------------------------------------------------
	const long double Dz = 0.5;		   // passo di presa dati
	const long double G = 9.80875;		   // costante gravitazionale a MILANO
	const long double uAria = 1.22521;	   // Densità aria (a 15° Gradi)
	const long double nAria = 1.293E-5;	   // Vicosità Aria
	const long double K = 1.9E-5;		   // Costante per correzione vicosità Aria
	const long double eReale = 1.6021766E19;   // carica reale dell'elettrone.
	const long double uOlio=860;		   // densità goccia d'olio
	const long double P=101325;		   // Pressione atmosferica (in pascal) sennò 1.0 ATM
	const long double Omega=500;		   // Resistenza elettrica (1 MOhm = 10E6 Ohm)
	const long double Elettrodi=7.6E-3;	   // Grandezza elettrodi (######################################### NON SONO SICURO)
//-------------------------------------------------------------------------------------------------------------------------------------------------
	int get_ohm();
	long double velocita_regime(long double);
	long double forza_viscosa(long double,long double);
	long double forza_peso(long double,long double);
	long double raggio_goccia(long double);
}
