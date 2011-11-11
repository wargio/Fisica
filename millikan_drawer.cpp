#include <cairo.h>
#include <cairo-pdf.h>
#include <cairo-ps.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "millikan_funcs.h"

#define SIZEX 550
#define SIZEY 550
#define px 50.0
#define py 100.0

using namespace std;

//#define M_PI 3.14159265
double rad=45;
const char APP[]="GraphDrawer 2D - Created by Giovanni Dante Grazioli";

double FONTSIZE =1.7*SIZEX/100;

double penn=.1;	//grandezza Pennello
double line=.1;

Display *dpy;
Window rootwin;
Window win;


long double eq(long double q[],int N, double x){
	return Sq(q,N,x);
}

void paint(cairo_surface_t *cs, long double q[],int N)
{ 
	cairo_t *c;
	float Ax,Ay;
	long double yc;
	double xc;
	c = cairo_create(cs);
	cairo_rectangle (c, 0, 0, SIZEX, SIZEY);
	cairo_set_source_rgb (c, 1, 1, 1);
	cairo_fill (c);
	yc=-SIZEY/2;
	while(1){
		xc=0;
		cairo_set_line_width (c, 1);
		cairo_arc (c, xc+SIZEX/2, yc+SIZEY/2, .5, 0, 2*M_PI);
		cairo_set_source_rgb (c, 0.3,0.3,0.3);
		cairo_stroke (c);
		yc++;
		if(yc>=SIZEY/2) break;

	}
	xc=-SIZEX/2;
	while(1){
		yc=0;
		cairo_set_line_width (c, 1);
		cairo_arc (c, xc+SIZEX/2, yc+SIZEY/2, .5, 0, 2*M_PI);
		cairo_set_source_rgb (c, 0.3,0.3,0.3);
		cairo_stroke (c);
		xc++;
		if(xc>=SIZEX/2) break;

	}

//	cerr << "X: ";
//	cin >> Ax;
	Ax=1;
//	cerr << "Y: ";
	Ay=-1E-27;

	if(Ax==0) Ax=1;
	if(Ay==0) Ay=1;


	cerr << "Drawing.." << endl;
	xc=-(SIZEX/2)/Ax;
	while(1){
		yc=eq(q,N,xc);
		cairo_set_line_width (c, penn);
		cairo_arc (c, (xc*Ax)+SIZEX/2, (yc*Ay)+SIZEY/2, line, 0, 2*M_PI);
		cairo_set_source_rgb (c, 1, 0.5, 0);
		cairo_stroke (c);
		xc+=0.001;
		cerr << (yc*Ay)+SIZEY/2 << "\r";
		if(xc*Ax>SIZEX/2) break;
	}
	char scal[256];
	cairo_select_font_face (c, "Purisa", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size (c, FONTSIZE);
	cairo_set_source_rgb (c, 0, 0, 0);
	cairo_move_to (c, 10, 10);
	cairo_show_text (c, "Premi lo schermo per chiudere l'applicazione");

	cairo_select_font_face (c, "Purisa", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size (c, FONTSIZE);
	cairo_set_source_rgb (c, 0, 0, 0);
	cairo_move_to (c, 200-SIZEX, 50-SIZEY);
	sprintf(scal,"Scala Asse X: 1:%f     Asse Y: 1:%f", Ax,Ay);
	cairo_show_text (c, (const char*)scal);

	cairo_select_font_face (c, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size (c, FONTSIZE);
	cairo_set_source_rgb (c, 0, 0, 0);
	cairo_move_to (c, SIZEX/2-10, SIZEY/2+10);
	cairo_show_text (c, "o                                                                                                 x");

	cairo_select_font_face (c, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size (c, FONTSIZE);
	cairo_set_source_rgb (c, 0, 0, 0);
	cairo_move_to (c, SIZEX/2-10, 10);
	cairo_show_text (c, "y");
	cerr << "Done.. Waiting X11 Window" << endl;
	while(1){
		XEvent e;
		XNextEvent(dpy, &e);
		if(e.type==ButtonPress) break;
	}
	cairo_destroy(c);
	cerr << "closing.." << endl;

}

void showxlib( long double q[],int N){
	int scr;
	cairo_surface_t *cs;

	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0, 
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, APP);
	XSelectInput(dpy, win, ExposureMask|ButtonPressMask);
	XMapWindow(dpy, win);
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);

//		XNextEvent(dpy, &e);
//		if(e.type==Expose && e.xexpose.count<1) {
			paint(cs,q,N);
//		} else if(e.type==ButtonPress) break;

//	}

	cairo_surface_destroy(cs);
	XCloseDisplay(dpy);
}

int main(int argc, char *argv[])
{
	unsigned int N1;
	fstream F;
	F.open("/home/giovanni/Documenti/Statistica/carica.dat",ios::in);
	F >> N1;
	long double q[N1];

	for(int i=0;i<N1;i++){
		F >> q[i];
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
	showxlib(q,N1);

	return 0;
}


