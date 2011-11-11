#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "millikan_funcs.h"
#include "stat_funcs.h"

using namespace std;
//using namespace millikan;
using namespace statistica;

////////////////////////////////////////////////////////////////
//STRUTTURA FILE:
//	NUM_TOT_DATI (conta solo dopo diff di potenziale) 
//	DIFFERENZA_DI_POTENZIALE(VOLTS)
//1	TEMPO_CADUTA(s) VELOCITà_GOCCIA(um/s) RAGGIO_GOCCIA(um)
//..	...
//n	TEMPO_CADUTA(s) VELOCITà_GOCCIA(um/s) RAGGIO_GOCCIA(um)
////////////////////////////////////////////////////////////////


//const long double DV=500;		   // DV differenza potenziale

//const 


int main (){
	//system("clear");
	cout << "Millikan" << endl;
	long double Spaz;	//Grandezza reticolo.
	fstream FILE; //time0.dat  time1.dat  time2.dat  valori_millikan.dat
	string vals="./dati/valori_millikan.dat";
	string path="./dati/time0.dat";
	string path1="./dati/time1.dat"; //discesa
	string path2="./dati/time2.dat"; //salita
	while(1){
		FILE.open(vals.c_str(),ios::in);
		if(FILE.fail()){
			FILE.close();
			cout << "File non trovato." << endl << endl;
		}else{
			break;
		}
	}
	unsigned int N, K;
	FILE >> N; // Primo valore numero totale dati Tempo.
	FILE >> K; // Primo valore numero totale dati DV e temperatuta.
	FILE >> Spaz;
	//---1----
	long double tempo0[N];	//discesa NO E
	long double tempo1[N];	//discesa
	long double tempo2[N];	//salita

	//---2----
	long double tempo3[N];	//discesa NO E
	long double tempo4[N];	//discesa
	long double tempo5[N];	//salita

	//---3----
	long double tempo6[N];	//discesa NO E
	long double tempo7[N];	//discesa
	long double tempo8[N];	//salita

	//---4----
	long double tempo9[N];	//discesa NO E
	long double tempo10[N];	//discesa
	long double tempo11[N];	//salita

	//---5----
	long double tempo12[N];	//discesa NO E
	long double tempo13[N];	//discesa
	long double tempo14[N];	//salita

	//---6----
	long double tempo15[N];	//discesa NO E
	long double tempo16[N];	//discesa
	long double tempo17[N];	//salita

	//---7----
	long double tempo18[N];	//discesa NO E
	long double tempo19[N];	//discesa
	long double tempo20[N];	//salita

	//---8----
	long double tempo21[N];	//discesa NO E
	long double tempo22[N];	//discesa
	long double tempo23[N];	//salita

	//---9----
	long double tempo24[N];	//discesa NO E
	long double tempo25[N];	//discesa
	long double tempo26[N];	//salita

	long double temperatura[K];//temp
	long double DV[K];	//Diff pot
	for(int i=0;i<K;i++){
		FILE >> temperatura[i]; //tempo
	}
	for(int i=0;i<K;i++){
		FILE >> DV[i]; //tempo
	}
	FILE.close();
	while(1){
		FILE.open(path.c_str(),ios::in);
		if(FILE.fail()){
			FILE.close();
			cout << "File non trovato." << endl << endl;
		}else{
			break;
		}
	}
	for(int i=0;i<N;i++){
		FILE >> tempo0[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo3[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo6[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo9[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo12[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo15[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo18[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo21[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo24[i]; //tempo
	}
	FILE.close();
	while(1){
		FILE.open(path1.c_str(),ios::in);
		if(FILE.fail()){
			FILE.close();
			cout << "File non trovato." << endl << endl;
		}else{
			break;
		}
	}
	for(int i=0;i<N;i++){
		FILE >> tempo1[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo4[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo7[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo10[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo13[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo16[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo19[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo22[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo25[i]; //tempo
	}
	FILE.close();
	while(1){
		FILE.open(path2.c_str(),ios::in);
		if(FILE.fail()){
			FILE.close();
			cout << "File non trovato." << endl << endl;
		}else{
			break;
		}
	}
	for(int i=0;i<N;i++){
		FILE >> tempo2[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo5[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo8[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo11[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo14[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo17[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo20[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo23[i]; //tempo
	}
	for(int i=0;i<N;i++){
		FILE >> tempo26[i]; //tempo
	}
	FILE.close();
//Millikan( DV, Spazio_Ret, Temperatura, T0[], T1[],T2[],N,nome);
	
	Millikan G0(DV[0],Spaz,temperatura[0],tempo0 ,tempo1 ,tempo2 ,N,"G0");
	Millikan G1(DV[1],Spaz,temperatura[1],tempo3 ,tempo4 ,tempo5 ,N,"G1");
	Millikan G2(DV[2],Spaz,temperatura[2],tempo6 ,tempo7 ,tempo8 ,N,"G2");
	Millikan G3(DV[3],Spaz,temperatura[3],tempo9 ,tempo10,tempo11,N,"G3");
	Millikan G4(DV[4],Spaz,temperatura[4],tempo12,tempo13,tempo14,N,"G4");
	Millikan G5(DV[5],Spaz,temperatura[5],tempo15,tempo16,tempo15,N,"G5");
	Millikan G6(DV[6],Spaz,temperatura[6],tempo18,tempo19,tempo20,N,"G6");
	Millikan G7(DV[7],Spaz,temperatura[7],tempo21,tempo22,tempo23,N,"G7");
	Millikan G8(DV[8],Spaz,temperatura[8],tempo24,tempo25,tempo26,N,"G8");


	G0.Print_carica();
	cout << "\n\n";
	G1.Print_carica();
	cout << "\n\n";
	G2.Print_carica();
	cout << "\n\n";
	G3.Print_carica();
	cout << "\n\n";
	G4.Print_carica();
	cout << "\n\n";
	G5.Print_carica();
	cout << "\n\n";
	G6.Print_carica();
	cout << "\n\n";
	G7.Print_carica();
	cout << "\n\n";
	G8.Print_carica();
	cout << "\n\n";
	
	unsigned int N1;
	fstream F,FF;
	F.open("/home/giovanni/Documenti/Statistica/dati/carica.dat",ios::in);
	FF.open("/home/giovanni/Documenti/Statistica/dati/R.dat",ios::in);
	F >> N1;
	long double q[N1],x[N1];

	for(int i=0;i<N1;i++){
		F >> q[i];
		FF >> x[i];
	}
	double tmp;
	for(int i=0;i<N1-1;i++){
		for(int j=i+1;j<N1;j++){
			if(q[i]>q[j]){
				tmp=q[i];
				q[i]=q[j];
				q[j]=tmp;
			}
		}
	}
	for(int i=0;i<N1;i++){
		cerr << q[i]<< endl;
	}
	for(int i=0;i<N1;i++){
		cerr << Sq(q,N1,x[i]) << endl;
	}
	return 0;
}

