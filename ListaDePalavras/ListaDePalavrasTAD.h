/*
 * Trabalho Prático 01 - AEDS 1 
 * Professora Thais R. M. Braga Silva
 * Universidade Federal de Virçosa - Campus Florestal
 * @author Adriano Ferreira - 4228 e Vitor Hugo - 4684
 * @version 0.1
 * @since 11 de out
*/

#include "../Palavra/PalavraTAD.h"
#include <string.h>


#ifndef TAD_LIST_H
#define TAD_LIST_H

typedef struct celula{
    Palavra caracteres ;
    //struct celula* prox; 
} CelulaLista;

/*typedef struct{
    CelulaLista* primeiroLista;
    CelulaLista* ultimoLista;
    int qtd;
} listaWord;
*/
void Cria_ListadPalavras(listaWord *pLista);                             //Cria lista de Palavras
void Insere_fim (listaWord *pLista, Palavra *pPalavra);                  //(Insere palavra no final)
void Remove_palavra(listaWord *pLista, char *palavra);                   //(Remove a palavra dada a palavra)
int Remove_palavra_fim(listaWord *pLista);                               //(Remove a palavra do final)
int Verifica_palavra(listaWord *pLista, char *palavra);                  //Dada a palavra, verifica se já existe na lista)
int Retorna_qtd (listaWord *pLista);                                     // Retorna a quantidade de celulas na lista
void Imprime_Listaword( listaWord *pLista);                               // Imprime a lista de palavras
int ListaE_Vazia(listaWord *pLista);                                        // Verifica se a lista esta vazia

#endif //Arquivo "TAD_LIST_H"
