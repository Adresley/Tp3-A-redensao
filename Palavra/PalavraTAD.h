
/*
 * Trabalho Prático 01 - AEDS 1 
 * Professora Thais R. M. Braga Silva
 * Universidade Federal de Viçosa - Campus Florestal
 * @author Adriano Ferreira - 4228 e Vitor Hugo - 4684
 * @version 0.1
 * @since 11 de out
*/

#ifndef TAD_PALAVRA_H
#define TAD_PALAVRA_H


#include <stdio.h>
#include <stdlib.h>
#include "../Numeros/ListaDeNumerosTAD.h"
#define lineTam 1024 /* uma linha é representada, normalmente, por 1024 caracteres */



typedef struct {
    char *palavra;
    ListadeNumeros lista;

}Palavra;

char* lerStringSeguramente(char* string, int tamanho);
Palavra* Palavra_vazia( Palavra *pPalavra,int tam);
void Preenche_palavra(Palavra *pPalavra,char *palavra,int linha);
char* Retorna_caracteres(Palavra *pPalavra);
void Imprime_caracteres(Palavra *pPalavra);
void Imprime_palavra(Palavra *pPalavra);
void separaArquivo();

#endif //Arquivo "TAD_PALAVRA_H"
