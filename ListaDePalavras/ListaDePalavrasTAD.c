#include "ListaDePalavrasTAD.h"


void Cria_ListadPalavras(listaWord *pLista){
    pLista->primeiroLista = (CelulaLista*) malloc(sizeof(CelulaLista));             // Aloca espaço no heap para a celula cabeça
    pLista->ultimoLista = pLista->primeiroLista;                                    //Faz o ponteiro ultimo ser igual ao ponteiro primeiro
    pLista->ultimoLista->prox = NULL;                                               // O campo prox da primeira/ultima celula aponta para NULL
}
             
void Insere_fim (listaWord *pLista, Palavra *pPalavra){
    pLista->ultimoLista->prox = (CelulaLista*)malloc(sizeof(CelulaLista));              //Aloca no prox do ultimo da lista a nova celula
    pLista->ultimoLista = pLista->ultimoLista->prox;                                    //Colocando o apontador ultimo na nova ultima celula
    pLista->ultimoLista->caracteres = *pPalavra;                                        //Inserindo a nova palavra 
    pLista->ultimoLista->prox = NULL;                                                    // Fazendo o campo prox da ultima celula apontar pra NULL

}
int ListaE_Vazia(listaWord *pLista){
    if (pLista->primeiroLista == pLista->ultimoLista)  // Verificando se só tem a celula cabeça
       return 1;
}
       

void Remove_palavra(listaWord *pLista, char *palavra){
    CelulaLista *pAux, *pAnt;
    int encontrou = 0;
    if (ListaE_Vazia(pLista))                   //Verifica se a lista esta vazia, ou seja só tem a celula cabeca
        printf("Lista vazia");
    pAux= pLista->primeiroLista->prox;                           // Recebe o primeiro da lista
    pAnt = pAux;                                                    //Ponteiro para a celula anterior
    while (pAux != NULL){
        if (pAux->caracteres.palavra == palavra)    // o elemento que queremos é o primeiro da lista
        {
            encontrou = 1;                          // encontramos o elemento
                if (pAux == pLista->primeiroLista->prox)
                {
                pLista->primeiroLista->prox = pAux->prox;
                free(pAux);
                break;
                }else                                                // Caso a palavra procurada esteja no meio
                {
                    pAnt->prox = pAux->prox;                        //O anterior vai apontar para o proximo do proximo
                    free(pAux);
                    break;
                }
                
       }else{ 
            pAnt = pAux;                                              //Atualizando os ponteiros
            pAux = pAux->prox;
        }
        
    }
    if (encontrou == 0)                                 //Verificando caso o valor nao seja encontrado
    {
        printf("\n Valor nao encontrado");
    }
}
    
         

int Remove_palavra_fim(listaWord *pLista){
    if (ListaE_Vazia(pLista))     //Verifica se a lista esta vazia, ou seja só tem a celula cabeca
        return 1;
    CelulaLista *aux,*ant;
    aux = pLista->primeiroLista->prox;              //Faz aux aponta para a primeira celula 
    ant = aux;
    while (aux != NULL)                             //Percorre a lista
    {
        ant->prox = aux->prox;                        //O anterior vai apontar para o proximo do proximo
        free(aux);
        ant = aux;                                              //Atualizando os ponteiros
        aux = aux->prox;
    }
    
    
}
                                            

int Verifica_palavra(listaWord *pLista, char *palavra){
    if (ListaE_Vazia(pLista))     //Verifica se a lista esta vazia, ou seja só tem a celula cabeca
        return 1;
    int i;
    CelulaLista* pAux;
    pAux = pLista->primeiroLista->prox;
    while (pAux != NULL)  //Percorre a lista de palavras
    {
        if (strcmp(pLista->primeiroLista->caracteres.palavra, palavra))     // Faz a comparação entre palavras
        {
            return 0;  // retorna 0 se a palavra existir
        }
    pAux = pAux->prox;              // para ir para proxima celula
    }


}                                          
int  Retorna_qtd (listaWord *pLista){
    int numCel;
    CelulaLista* pAux;
    pAux = pLista->primeiroLista->prox;
    while (pAux != NULL)
    {
        numCel ++;
        pAux = pAux->prox; // Para ir para proxima celula//
    }
    pLista->qtd = numCel;
    return pLista->qtd;


}
void Imprime_Listaword( listaWord *pLista){
    CelulaLista* pAux;
    pAux = pLista->primeiroLista->prox;
    while (pAux != NULL)
    {
        printf("%s\n", pLista->primeiroLista->caracteres.palavra);
        pAux = pAux->prox; /* próxima célula */
    }
}