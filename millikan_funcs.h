//#ifndef _MILLIKAN_H_
//#define _MILLIKAN_H_
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <string>
//namespace millikan{



//-------------------------------------------------------------------------------------------------------------------------------------------------
	const long double Dz = 0.5;		   // passo di presa dati
	const long double G = 9.80875;		   // costante gravitazionale a MILANO
	const long double uAria = 1225.21;	   // Densità aria (a 15° Gradi)
//	const long double nAria = 1.83E-5;	   // Vicosità Aria
	const long double K = 1.293E-5;		   // Costante per correzione vicosità Aria
	const long double carica_e = 1.6021766E-19; // carica reale dell'elettrone.
	const long double uOlio=870;		   // densità goccia d'olio
	const long double P=101325;		   // Pressione atmosferica (in pascal) sennò 1.0 ATM
	const long double Elettrodi=7.6E-3;	   // Grandezza elettrodi (######################################### NON SONO SICURO)
//-------------------------------------------------------------------------------------------------------------------------------------------------
//	long double velocita_regime(long double);
//	long double forza_viscosa(long double,long double);
//	long double forza_peso(long double,long double);
//	long double raggio_goccia(long double[],unsigned int);
//	long double carica_q(long double, long double[], long double[], long double[], unsigned int);

class Millikan{

public:
//----------------------------------------------------------------------
Millikan(long double DV, long double Spazio_Ret, double Temperatura, long double T0[], long double T1[], long double T2[], unsigned int N, std::string nome);
~Millikan();
//----------------------------------------------------------------------
	const long double get_viscosita_aria()const {return k_nAria;}
	std::string get_nome()const {return k_nome;}
	long double viscosita_aria()const ;
	long double velocita_goccia(long double)const;
	long double campo_elettrico()const;
	int carica_goccia(long double carica)const;
	long double singola_carica_goccia(long double carica)const ;
	long double velocita_regime(long double r)const;
	long double forza_viscosa(long double r,long double v)const;
	long double forza_peso(long double r,long double v)const;
	long double raggio_goccia(long double v)const;
	long double carica_q(long double v, long double v0, long double r)const;
	void Print_carica()const ;
	void Print_velocita0()const ;
	void Print_velocita_salita()const ;
	void Print_velocita_discesa()const ;
	void Print_raggio_0()const ;
	void Print_raggio_1()const ;
	void Print_raggio_2()const ;
	void Print_all()const ;
	void Print_carica_singola()const;

private:

	double k_DV, k_Temp, k_E;
	unsigned int k_N;
	long double *k_T0, *k_T1, *k_T2; //T1=dicesa | T2=salita | T0 discesa senza E
	long double k_Spaz, k_nAria;
	std::string k_nome;
};



	long double Sq(long double [], int);
	long double Sq(long double [], int, double);
	long double carica_q1(long double, long double[], long double[], long double[], unsigned int);
//}

//#endif

