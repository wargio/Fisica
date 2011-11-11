GCC	=	g++ -o 

LIBSTAT	=	stat_funcs.cpp
LIBMILLIKAN=	millikan_funcs.cpp

PRG1	=	devstd
PRG2	=	millikan
PRG3	=	millikan_ohm
PRG4	=	millikan1
PRG5	=	millikan_drawer

PRGC1	=	$(LIBSTAT) devstd.cpp
PRGC2	=	$(LIBSTAT) $(LIBMILLIKAN) millikan.cpp
PRGC4	=	$(LIBSTAT) $(LIBMILLIKAN) aaa.cpp
PRGC3	=	Millikan_Resistenza.cpp

CFLAGS=-Wall -pedantic -g -I/usr/X11R6/include `pkg-config --cflags cairo`
LDFLAGS=-Wall -g `pkg-config --libs cairo` -L/usr/X11R6/lib -lX11
GFLAG = -I/usr/X11R6/include `pkg-config --cflags cairo`
LGFLAG = `pkg-config --libs cairo` -L/usr/X11R6/lib -lX11


all: compile drawer


compile: 
	@clear
	$(GCC) $(PRG1) $(PRGC1) 
	$(GCC) $(PRG2) $(PRGC2) 
	$(GCC) $(PRG3) $(PRGC3) 

devstd: all
	./devstd

millikan: all
	./millikan

ohm: 	all
	./millikan_ohm
draw:	drawer
	./$(PRG5)

clean:
	rm -rf $(PRG1) $(PRG2) $(PRG3)

drawer: 
	g++ -o $(PRG5).o ${GFLAG} -c $(PRG5).cpp
	g++ -o millikan_funcs.o -c $(LIBMILLIKAN)
	g++ -o millikan_drawer ${LGFLAG} $(PRG5).o millikan_funcs.o 
	rm ./$(PRG5).o millikan_funcs.o 

