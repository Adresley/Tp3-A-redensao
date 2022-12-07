#include "ListaDeNumerosTAD.h"
//Sem celula cabeca

void IniciaVazia(ListadeNumeros* pLista){
   pLista->primeiroLista = NULL;
   pLista->ultimoLista = NULL;

}
int Vazia(ListadeNumeros* pLista){

   return (pLista->ultimoLista == NULL);
}
void Insere(ListadeNumeros* pLista, int x){

   if (pLista->ultimoLista == NULL){
      pLista->ultimoLista = (CelulaNumeros*) malloc(sizeof(CelulaNumeros));
      pLista->primeiroLista = pLista->ultimoLista;
   }
   else{
      pLista->ultimoLista->pProx = (CelulaNumeros*) malloc(sizeof(CelulaNumeros));
      pLista->ultimoLista = pLista->ultimoLista->pProx;
   }
   pLista->ultimoLista->numero = x;
   pLista->ultimoLista->pProx = NULL;
   //printf("Dado inserido na lista de numeros\n");

}
void Retira(ListadeNumeros* pLista, int *p, int *pX){
   
   CelulaNumeros* pAux;
   if (Vazia(pLista)){
      printf("Não pode ser removido da lista de números\n");
   }

   *p = pLista->primeiroLista->pProx->numero;
   pAux = pLista->primeiroLista;
   pLista->primeiroLista = pLista->primeiroLista->pProx;
   free(pAux);
   
   printf("Dado retirado da lista de números\n");
}
void Imprime_ListaNum(ListadeNumeros* pLista){
   CelulaNumeros* pAux;
   pAux = pLista->primeiroLista;
   while (pAux != NULL)
   {
      printf("%d\n", pAux->numero);
      pAux = pAux->pProx; /* próxima célula */
   }
}

