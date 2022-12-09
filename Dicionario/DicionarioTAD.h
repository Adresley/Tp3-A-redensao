/*
 * Trabalho Prático 01 - AEDS 1 
 * Professora Thais R. M. Braga Silva
 * Universidade Federal de Virçosa - Campus Florestal
 * @author Adriano Ferreira - 4228 e Vitor Hugo - 4684
 * @version 0.1
 * @since 11 de out
*/

#include "../ListaDePalavras/ListaDePalavrasTAD.h"


#ifndef TAD_DICIONARIO_H
#define TAD_DICIONARIO_H


typedef struct celulalista{
    listaWord listaPalavraPorLetra;
    char letraLista;
    //struct celulalista* prox; 
} CelulaListaPalavras;

/*typedef struct{
    CelulaListaPalavras* primeiroListaPalavras;
    CelulaListaPalavras* ultimoListaPalavras;
} Dicionarie;
*/
char* lerStringSeguramente(char* string, int tamanho);
void iniciarDicionario(Dicionarie *pLista);
void constroiDicionario(Dicionarie *pLista);
void imprimeCertaLetraDicionario(Dicionarie *pLista, char letra);
void imprimeTudoDicionario(Dicionarie *pLista);
int estaVazia(Dicionarie* pLista);
int temListaPalavraDessaLetra(Dicionarie *pLista, char letra);
CelulaListaPalavras* ListaPalavraDessaLetra(Dicionarie *pLista, char letra);
void insereListaOrdenada(Dicionarie* pLista, char letra);


#endif //Arquivo "TAD_DICIONARIO_H"
