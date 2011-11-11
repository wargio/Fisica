#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "stat_funcs.h"
using namespace std;

namespace statistica{
	long double Media(long double v[],unsigned int N){
		long double media=0;
		for(int i=0;i<N;i++){
			media+=v[i];
		}
		return media/(N-1);
	}
	long double dev(long double v[],unsigned int N){
		const long double media=Media(v,N);
		long double dv=0;
		for(int i=0;i<N;i++){
			dv+=pow(v[i]-media,2);
		}
		return sqrt(dv/(N-1));
	}

	long double deverr(long double dev,unsigned int N){
		return dev/sqrt(N-1);
	}

	long double chiQ(long double v[],unsigned int N, long double a[]){
		long double chi=0,d=dev(v,N);
		for(int i=0;i<N;i++){
			chi+=pow((v[i]-a[i])/d,2);
		}
		return chi;
	}

	long double chiR(long double chi,unsigned int liberta){
		if(liberta>23) liberta--;
		return chi/liberta;
	}
}
