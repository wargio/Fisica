GCC	=	g++ -o 

LIBSTAT	=	stat_funcs.cpp
LIBMILLIKAN=	millikan_funcs.cpp

PRG1	=	devstd
PRG2	=	millikan
PRG3	=	millikan_ohm

PRGC1	=	$(LIBSTAT) devstd.cpp
PRGC2	=	$(LIBSTAT) $(LIBMILLIKAN) millikan.cpp
PRGC3	=	Millikan_Resistenza.cpp

all: compile


compile: 
	@clear
	$(GCC) $(PRG1) $(PRGC1) 
	$(GCC) $(PRG2) $(PRGC2) 
	$(GCC) $(PRG3) $(PRGC3) 

devstd: all
	./devstd

millikan: all
	./millikan


ohm: all
	./millikan_ohm

clean:
	rm -rf $(PRG1) $(PRG2) $(PRG3)



