main: main.o ListaDeNumerosTAD.o PalavraTAD.o ListaDePalavrasTAD.o DicionarioTAD.o
	gcc main.o ListaDeNumerosTAD.o PalavraTAD.o ListaDePalavrasTAD.o DicionarioTAD.o -o main

main.o: main.c
	gcc -c main.c

ListaDeNumerosTAD.o: Numeros/ListaDeNumerosTAD.c Numeros/ListaDeNumerosTAD.h
	gcc -c Numeros/ListaDeNumerosTAD.c

PalavraTAD.o: Palavra/PalavraTAD.c Palavra/PalavraTAD.h
	gcc -c Palavra/PalavraTAD.c
	
ListaDePalavrasTAD.o: ListaDePalavras/ListaDePalavrasTAD.c ListaDePalavras/ListaDePalavrasTAD.h
	gcc -c ListaDePalavras/ListaDePalavrasTAD.c

DicionarioTAD.o: Dicionario/DicionarioTAD.c Dicionario/DicionarioTAD.h
	gcc -c Dicionario/DicionarioTAD.c
	

clean:
	rm *.o