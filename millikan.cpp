#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "millikan_funcs.h"
using namespace std;
using namespace millikan;

const string path="/home/giovanni/Documenti/Statistica/0Volt.dat";
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
	//string path;
	while(1){
		cerr << "////////////////////////////////////////////////////\nIn ";
		system("pwd");
		cerr << "-----------*.dat----------\n";
		system("ls *.dat ");
		cerr << "-----------*.txt----------\n";
		system(" ls *.txt");
		cerr << "////////////////////////////////////////////////////\n";
		cerr << "File da cui prendere i dati: ";
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
	cerr << endl << raggio_goccia(32.9E-6) << endl;
	
	
	
	
	
	
	delete [] t,v,r;
	return 0;
}

