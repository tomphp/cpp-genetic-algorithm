#all:
#	g++ main.cpp Gene.cpp Individual.cpp Population.cpp -std=c++11 -o ga-solve
#g++ --std=c++11 -c Gene.cpp 
#	g++ --std=c++11 -c Individual.cpp
#	g++ --std=c++11 -c Population.cpp

#	g++ --std=c++11 main.cpp *.o -o ga-solve

CXX = g++
CXXFLAGS = --std=c++11

main: gene.o individual.o population.o executor.o main.o
	$(CXX) $(CXXFLAGS) -o ga-solve main.o gene.o individual.o population.o executor.o

main.o: population.h individual.h result.h gene.h executor.h

gene.o: gene.h

individual.o: individual.h gene.h result.h executor.h

population.o: population.h individual.h result.h gene.h executor.h

executor.o: executor.h gene.h result.h

clean:
	rm -f *.o ga-solve
