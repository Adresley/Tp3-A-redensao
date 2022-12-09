
/*
 * Trabalho Prático 01 - AEDS 1 
 * Professora Thais R. M. Braga Silva
 * Universidade Federal de Virçosa - Campus Florestal
 * @author Adriano Ferreira - 4228, Aymê Faustino - 4704, Vitor Hugo - 4684
 * @version 0.1
 * @since 11 de out
*/

#ifndef LISTA_NUMEROS_H
#define LISTA_NUMEROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//CRIANDO UMA LISTA LINEAR PARA LINHAS QUE A PALAVRA APARECEU
 typedef struct listaNum
 {
   int numero;
   //struct listaNum* pProx;

 }CelulaNumeros;
/*
 typedef struct{
   CelulaNumeros* primeiroLista;
   CelulaNumeros* ultimoLista;

 }ListadeNumeros;*/



void IniciaVazia(ListadeNumeros* pLista);
int Vazia(ListadeNumeros* pLista);
void Insere(ListadeNumeros* pLista, int x);
void Retira(ListadeNumeros* pLista, int *p, int *pX);
void Imprime_ListaNum(ListadeNumeros* pLista);

#endif //Arquivo "LISTA_NUMEROS_H"

