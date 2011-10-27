#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "stat_funcs.h"
using namespace std;
using namespace statistica;

int main (){
	system("clear");
	cerr << "Deviazione STD" << endl;
	unsigned int N;
	long double *v;
	long double *a;
	fstream file;
	file.open ("/home/giovanni/Documenti/Statistica/em.dat",ios::in);
	if(file.fail()) return -1;
	else{
		file >> N;
		v=new long double[N];
		a=new long double[N];

		for(int i=0;i<N;i++){
			file >> v[i];
			a[i]=1.76E11;
			cerr << v[i] << "	\r";
		}
	}
	long double dv=dev(v,N);
	cerr << "Media= " << Media(v,N) << "\nDev=   " << dv << "\nDevMedia= " << deverr(dv,N) << "\nChi^2=  " << chiQ(v,N,a) << "\nChi^2 rid= " << chiR(chiQ(v,N,a),N) << endl;	
	delete [] v,a;
	return 1;
}
