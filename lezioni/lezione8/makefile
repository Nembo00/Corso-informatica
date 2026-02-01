all: prog1 prog2 prog3 prog4 prog5 prog6

prog1:: esercizio1.cc
	g++ -o prog1 esercizio1.cc

prog2:: esercizio2.cc
	g++ -o prog2 esercizio2.cc

prog3:: esercizio3.cc function.cc function.h
	g++ -o prog3 esercizio3.cc function.cc

prog4:: esercizio4.cc funzioni.cc funzioni.h
	g++ -o prog4 esercizio4.cc funzioni.cc

prog5:: esercizio5.cc
	g++ -o prog5 esercizio5.cc

prog6:: esercizio6.cc
	g++ -o prog6 esercizio6.cc
clean: 
	rm - f prog1 prog2 prog3 prog4 prog5 prog6