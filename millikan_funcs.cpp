#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "millikan_funcs.h"

using namespace std;
//using namespace millikan;

//namespace millikan {

//--------------------------------------------------CLASSE------------------------------------------------------
	Millikan::Millikan(long double DV, long double Spazio_Ret, double Temperatura, long double T0[], long double T1[], long double T2[], unsigned int N, std::string nome){
		k_nome=nome;
		k_Temp=Temperatura;
		k_Spaz=Spazio_Ret;
		k_DV=DV;
		k_N=N;
		k_E=campo_elettrico();
		k_nAria=viscosita_aria();
		k_T0 = new long double [N];
		k_T1 = new long double [N];
		k_T2 = new long double [N];
		for(int i =0; i<N;i++){
			k_T0[i]=T0[i];
			k_T1[i]=T1[i];
			k_T2[i]=T2[i];
		}
	}

	Millikan::~Millikan(){
		delete [] k_T0;
		delete [] k_T1;
		delete [] k_T2;
	}

	long double Millikan::viscosita_aria()const {
		return (1.800+((k_Temp-15)*4.765E-3))*1E-5;
	}
	long double Millikan::velocita_goccia(long double t)const {
		return k_Spaz/t;
	}
	long double Millikan::campo_elettrico()const {
		return k_DV/k_Spaz;
	}
	int Millikan::carica_goccia(long double carica)const {
		return ((int)((1)*(carica)/carica_e));
	}
	long double Millikan::singola_carica_goccia(long double carica)const {
		int i=carica_goccia(carica);
		if(i==0)i=1;
		return carica/i;
	}
	long double Millikan::velocita_regime(long double r)const {
		return 2*G*pow(r,2)*(uOlio-uAria)/(9*get_viscosita_aria());
	}
	long double Millikan::forza_viscosa(long double r,long double v)const {
		return 6*M_PI*r*get_viscosita_aria()*v;
	}
	long double Millikan::forza_peso(long double r,long double v)const {
		return 4*M_PI*pow(r,3)*G*uOlio;
	}
	long double Millikan::raggio_goccia(long double v)const {
		return sqrt((9*get_viscosita_aria()*v)/(2*G*uOlio));
	}
	long double Millikan::carica_q(long double v, long double v0, long double r)const { //V0 no E, V con E
		if(v<0) return (-1)*((4*M_PI/3)*pow(r,3)*(uOlio-uAria)*(G/k_E)*(1+(abs(v)/v0)));
		else return (-1)*((4*M_PI/3)*pow(r,3)*(uOlio-uAria)*(G/k_E)*(1-(v/v0)));
	}
	void Millikan::Print_carica()const {
		long double c;
	//	cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<2*k_N;i++){
			if(i<3) c=carica_q(velocita_goccia(k_T1[i]),velocita_goccia(k_T0[i]),raggio_goccia(velocita_goccia(k_T1[i])));
			else c=carica_q(velocita_goccia(k_T2[i-k_N]),velocita_goccia(k_T0[i-k_N]),raggio_goccia(velocita_goccia(k_T2[i-k_N])));
			cout <</* "Carica: " <<*/ c << "\n";//	" << carica_goccia(c) << "	volte e- | singolo e : " << singola_carica_goccia(c) << endl;
		}
	}
	void Millikan::Print_velocita0()const {
		long double c;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<k_N;i++){
			c=velocita_goccia(k_T0[i]);
			cout << "Velocita Discesa Senza E " << i << "): " << c << endl;
		}
		
	}
	void Millikan::Print_velocita_salita()const {
		long double c;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<k_N;i++){
			c=velocita_goccia(k_T2[i]);
			cout << "Velocita Salita " << i << "): " << c << endl;
		}
		
	}
	void Millikan::Print_velocita_discesa()const {
		long double c;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<k_N;i++){
			c=velocita_goccia(k_T1[i]);
			cout << "Velocita Discesa " << i << "): " << c << endl;
		}
		
	}
	void Millikan::Print_raggio_0()const {
		long double c;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<k_N;i++){
			c=raggio_goccia(velocita_goccia(k_T0[i]));
			cout << "Raggio_0 " << i << "): " << c << endl;
		}
		
	}
	void Millikan::Print_raggio_1()const {
		long double c;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<k_N;i++){
			c=raggio_goccia(velocita_goccia(k_T1[i]));
			cout << "Raggio_1 " << i << "): " << c << endl;
		}
		
	}
	void Millikan::Print_raggio_2()const {
		long double c;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<k_N;i++){
			c=raggio_goccia(velocita_goccia(k_T2[i]));
			cout << "Raggio_2 " << i << "): " << c << endl;
		}
		
	}
	void Millikan::Print_all()const {
		long double c=0;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<k_N;i++){
			c=raggio_goccia(velocita_goccia(k_T0[i]));
			cout << "Raggio_0 " << i << "): " << c << endl;
		}
		for(int i=0;i<k_N;i++){
			c=raggio_goccia(velocita_goccia(k_T1[i]));
			cout << "Raggio_1 " << i << "): " << c << endl;
		}
		for(int i=0;i<k_N;i++){
			c=raggio_goccia(velocita_goccia(k_T2[i]));
			cout << "Raggio_2 " << i << "): " << c << endl;
		}
		for(int i=0;i<k_N;i++){
			c=velocita_goccia(k_T0[i]);
			cout << "Velocita Discesa Senza E " << i << "): " << c << endl;
		}
		for(int i=0;i<k_N;i++){
			c=velocita_goccia(k_T2[i]);
			cout << "Velocita Salita  " << i << "): " << c << endl;
		}
		for(int i=0;i<k_N;i++){
			c=velocita_goccia(k_T1[i]);
			cout << "Velocita Discesa " << i << "): " << c << endl;
		}
		for(int i=0;i<2*k_N;i++){
			if(i<3) c=carica_q(velocita_goccia(k_T1[i]),velocita_goccia(k_T0[i]),raggio_goccia(velocita_goccia(k_T1[i])));
			else c=carica_q(velocita_goccia(k_T2[i-k_N]),velocita_goccia(k_T0[i-k_N]),raggio_goccia(velocita_goccia(k_T2[i-k_N])));
			cout << "Carica: " << c << "	" << 0-carica_goccia(c) << "	volte e- | singolo e : " << singola_carica_goccia(c) << endl;
		}
		
	}
	void Millikan::Print_carica_singola()const {
		long double c;
		cout << "Nome Goccia: " << get_nome() << endl << scientific;
		for(int i=0;i<2*k_N;i++){
			if(i<3) c=carica_q(velocita_goccia(k_T1[i]),velocita_goccia(k_T0[i]),raggio_goccia(velocita_goccia(k_T1[i])));
			else c=carica_q(velocita_goccia(k_T2[i-k_N]),velocita_goccia(k_T0[i-k_N]),raggio_goccia(velocita_goccia(k_T2[i-k_N])));
			cout << "Carica: " << singola_carica_goccia(c) << endl;
		}
	}
//--------------------------------------------------CLASSE------------------------------------------------------


	long double Sq(long double q[], int N){
		long double S=0;
		int k=0;
		for(int i=0;i<N;i++){
			k=(int)((1)*((q[i]/carica_e)+0.5));
			S+=pow((k*carica_e)-q[i],2);
		}
		return S;
	}
	long double Sq(long double q[], int N, double x){
		long double S=0;
		int k=0;
		for(int i=0;i<N;i++){
			k=(((q[i]/x)+0.5));
			S+=pow(((k*(x))-q[i]),2);
		}
		return S;
	}
	long double carica_q1(long double E, long double v[], long double v0[], long double r[], unsigned int n){ // v0 velocità senza campo, v con il campo
		if(v[n]<0) return (-1)*((4*M_PI/3)*pow(r[n],3)*(uOlio-uAria)*(G/E)*(1+(abs(v[n])/v0[n-3])));
		else return (-1)*((4*M_PI/3)*pow(r[n],3)*(uOlio-uAria)*(G/E)*(1-(v[n]/v0[n-3])));


	}
//}
