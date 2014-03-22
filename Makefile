CFLAGS=-O0 -g
CXXFLAGS=-O0 -g
FCFLAGS=-O0 -g
F77FLAGS=-O0 -g

all: main.o sip_interface.o aoladder_contraction.o lookup_shell.o
	g++ $(CXXFLAGS) main.o sip_interface.o aoladder_contraction.o lookup_shell.o -lgfortran -lm -o test_bed

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp 

sip_interface.o: sip_interface.cpp
	g++ $(CXXFLAGS) -c sip_interface.cpp

aoladder_contraction.o: aoladder_contraction.F
	gfortran $(FCFLAGS) -c aoladder_contraction.F

lookup_shell.o: lookup_shell.f
	gfortran $(F77FLAGS) -c lookup_shell.f

clean:
	rm sip_interface.o aoladder_contraction.o lookup_shell.o test_bed
