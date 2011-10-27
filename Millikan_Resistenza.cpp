#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>


using namespace std;

int ohm(){
	double T=0;
	cerr << "Temperatura: ";
	cin >> T;
	
	
	if(T<9){ return 3.239E6;}
	if(T>=9  && T<=10){ return 3.239E6;}
	if(T>10 && T<=11){ return 3.118E6;}
	if(T>11 && T<=12){ return 3.004E6;}
	if(T>12 && T<=13){ return 2.897E6;}
	if(T>13 && T<=14){ return 2.795E6;}
	if(T>14 && T<=15){ return 2.700E6;}
	if(T>15 && T<=16){ return 2.610E6;}
	if(T>16 && T<=17){ return 2.526E6;}
	if(T>17 && T<=18){ return 2.446E6;}
	if(T>18 && T<=19){ return 2.371E6;}
	if(T>19 && T<=20){ return 2.300E6;}
	if(T>20 && T<=21){ return 2.233E6;}
	if(T>21 && T<=22){ return 2.169E6;}
	if(T>22 && T<=23){ return 2.110E6;}
	if(T>23 && T<=24){ return 2.053E6;}
	if(T>24 && T<=25){ return 2.000E6;}
	if(T>25 && T<=26){ return 1.950E6;}
	if(T>26 && T<=27){ return 1902E6;}
	if(T>27 && T<=28){ return 1.857E6;}
	if(T>28 && T<=29){ return 1.815E6;}
	if(T>29 && T<=30){ return 1.774E6;}
	if(T>30 && T<=31){ return 1.736E6;}
	if(T>31 && T<=32){ return 1.700E6;}
	if(T>32 && T<=33){ return 1.666E6;}
	if(T>33 && T<=34){ return 1.634E6;}
	if(T>34 && T<=35){ return 1.603E6;}
	if(T>35 && T<=36){ return 1.574E6;}
	if(T>36 && T<=37){ return 1.574E6;}
	if(T>37 && T<=38){ return 1.521E6;}
	if(T>38 && T<=39){ return 1.496E6;}
	if(T>39) return -1;
}

int main(){
	system("clear");
	cerr << "Millikan - Calcolo resistenza" << endl;
	cerr << ohm() << endl;	
	return 0;
}
