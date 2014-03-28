CFLAGS=-O0 -g
CXXFLAGS=-O0 -g -std=c++11
FCFLAGS=-O0 -g
F77FLAGS=-O0 -g
CPPFLAGS="-Igtest-1.7.0/include"
LDFLAGS= -lgfortran -lm -Lgtest-1.7.0/lib/.libs/ -lgtest -pthread

all: main_test.o sip_interface_test.o aoladder_contraction.o lookup_shell.o constants_data_types.o aoladder_contraction_cpp.o
	g++ $(CXXFLAGS) main_test.o sip_interface_test.o aoladder_contraction.o aoladder_contraction_cpp.o constants_data_types.o lookup_shell.o -o test_bed $(LDFLAGS)

main_test.o: main_test.cpp
	g++ $(CXXFLAGS) $(CPPFLAGS) -c main_test.cpp  

sip_interface_test.o: sip_interface_test.cpp
	g++ $(CXXFLAGS) $(CPPFLAGS) -c sip_interface_test.cpp

aoladder_contraction.o: aoladder_contraction.F
	gfortran $(FCFLAGS) $(CPPFLAGS) -c aoladder_contraction.F

aoladder_contraction_cpp.o: aoladder_contraction_cpp.cpp
	g++ $(CXXFLAGS) $(CPPFLAGS) -c aoladder_contraction_cpp.cpp

lookup_shell.o: lookup_shell.f
	gfortran $(F77FLAGS) $(CPPFLAGS) -c lookup_shell.f

constants_data_types.o: constants_data_types.cpp
	g++ $(CXXFLAGS) $(CPPFLAGS) -c constants_data_types.cpp

clean:
	-rm -f main_test.o sip_interface_test.o aoladder_contraction.o lookup_shell.o constants_data_types.o aoladder_contraction_cpp.o test_bed
