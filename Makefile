Rational: Rational.o main.o
	clang++ -o Rational Rational.o main.o

Rational.o: Rational.cc Rational.hh
	clang++ -c Rational.cc

main.o: main.cpp Rational.hh
	clang++ -c main.cpp
