#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "millikan_funcs.h"
#include "stat_funcs.h"

using namespace std;
using namespace millikan;
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
	system("clear");
	cerr << "Millikan" << endl;
	long double* t;
	long double* v;
	long double* r;
	long double rGoccia=0;	//raggio goccia d'olio
	long double DV=0;	//Differenza di potenziale
	long double E=0;	//campo elettrico
	long double OHM=0;	//Resistenza
//	long double Vreg = 0;   // velocità di regime
	fstream FILE;
	string path="/home/giovanni/Documenti/Statistica/0Volt.dat";
	while(1){
		cerr << "////////////////////////////////////////////////////\nIn ";
		system("pwd");
		cerr << "-----------*.dat----------\n";
		system("ls *.dat ");
		cerr << "-----------*.txt----------\n";
		system(" ls *.txt");
		cerr << "\n////////////////////////////////////////////////////\n";
//		cerr << "File da cui prendere i dati: ";
//		cin >> path;
		FILE.open(path.c_str(),ios::in);
		if(FILE.fail()){
			FILE.close();
			cerr << "File non trovato." << endl << endl;
		}else{
			break;
		}
	}
	unsigned int N;
	FILE >> N; // Primo valore numero totale dati.
	FILE >> DV; // Primo valore numero totale dati.
	t = new long double [N];
	v = new long double [N];
	r = new long double [N];
	
	for(int i=0;i<N;i++){
		FILE >> t[i];
		FILE >> v[i];
		FILE >> r[i];
	}
	long double Raggio_goccia[N];
	for(int i=0;i<N;i++){
		Raggio_goccia[i]=raggio_goccia(v[i]);
//		cerr << "raggio_goccia " << raggio_goccia(v[i]) << " 	" << r[i] << "	" << chiR(chiQ(v,N,r),N) << endl;
		
	}
	for(int i=0;i<N;i++){
//		A[i]=raggio_goccia(v[i]);
		cerr << "raggio_goccia " << Raggio_goccia[i] << " 	" << r[i] << "	" << chiR(chiQ(Raggio_goccia,N,r),N) << endl;
		
	}
	delete [] t,v,r;
	return 0;
}

