#include "DicionarioTAD.h"

void iniciarDicionario(Dicionarie *pLista){
      pLista->primeiroListaPalavras = (CelulaListaPalavras*)malloc(sizeof(CelulaListaPalavras));
      pLista->ultimoListaPalavras = pLista->primeiroListaPalavras;
      pLista->ultimoListaPalavras->prox = NULL;
}

int estaVazia(Dicionarie* pLista){

   return (pLista->ultimoListaPalavras == NULL);
}



int temListaPalavraDessaLetra(Dicionarie *pLista, char letra){
    int opt = 1;
    CelulaListaPalavras* pAux;
    pAux = pLista->primeiroListaPalavras;
    while (pAux != NULL)
    {
        if (letra == pAux->letraLista){
            opt = 0;
        }
        pAux = pAux->prox; /* próxima célula */
    }
    return opt;
}

CelulaListaPalavras* ListaPalavraDessaLetra(Dicionarie *pLista, char letra){
    CelulaListaPalavras* pAux;
    pAux = pLista->primeiroListaPalavras;
    while (pAux != NULL)
    {
        if(letra == pAux->letraLista){
            return pAux;
        }
        pAux = pAux->prox; /* próxima célula */
    }
    return NULL;
}

//ordenar
void insereListaOrdenada(Dicionarie* pLista, char letra){
    
    CelulaListaPalavras *aux, *novo = (CelulaListaPalavras*) malloc(sizeof(CelulaListaPalavras));
    Cria_ListadPalavras(&novo->listaPalavraPorLetra);
    if(novo){
        novo->letraLista = letra;

        // a lista está vazia?
        if(pLista->primeiroListaPalavras == NULL){
            pLista-> primeiroListaPalavras = novo;
            pLista-> primeiroListaPalavras->prox = NULL;
            pLista-> ultimoListaPalavras = novo;

        } // é o menor?
        else if(novo->letraLista < pLista->primeiroListaPalavras->letraLista){
            novo->prox = pLista->primeiroListaPalavras;
            pLista->primeiroListaPalavras = novo;
        }
        else{
            aux = pLista->primeiroListaPalavras;
            while(aux->prox && novo->letraLista > aux->prox->letraLista)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");

}

void constroiDicionario(Dicionarie *pLista){

    char stringFile[lineTam]; 

	printf("Nome do arquivo de entrada: ");

	if(lerStringSeguramente(stringFile, sizeof(stringFile)) != NULL) {

		FILE *archive;
        archive = fopen(stringFile, "r");//Abre arquivo de teste para leitura
        
        if (archive == NULL){
            printf("Erro na abertura do arquivo");
            exit(1);
        }else{
            
            char str[lineTam];
            const char s[2] = " ";
            char *palavraSeparada;
            int line = 0;

            fgets(str, sizeof(str), archive);
            // Separa palavra por palavra por loop
            do {
            
                //pega pre
                palavraSeparada = strtok(str, s);
                
                while( palavraSeparada != NULL ) {
                    //printf( "%s\n", palavraSeparada );
                    
                    Palavra *pPalavra = NULL;
                    pPalavra = Palavra_vazia(pPalavra, strlen(palavraSeparada));
                    if(pPalavra == NULL){
                        printf("ERRO");
                    }
                    
                    Preenche_palavra(pPalavra, palavraSeparada, line);
                    Imprime_palavra(pPalavra);
                    if(pLista != NULL && temListaPalavraDessaLetra(pLista, palavraSeparada[0]) == 0){
                        // se sim insere palavra e linha nessa
                        CelulaListaPalavras* pAux1 = ListaPalavraDessaLetra(pLista, palavraSeparada[0]);
                        Insere_fim (&pAux1->listaPalavraPorLetra, pPalavra);
                        
                    }else{
                        // senão cria insere lista de palavras com essa letra e coloca palavra

                        
                        insereListaOrdenada( pLista, palavraSeparada[0]);
                        CelulaListaPalavras* pAux1 = ListaPalavraDessaLetra(pLista, palavraSeparada[0]);
                        if(pAux1 != NULL)
                            Insere_fim (&pAux1->listaPalavraPorLetra, pPalavra);
                    }
                    

                
                    palavraSeparada = strtok(NULL, s);
                }

                fgets(str, sizeof(str), archive);
                line++;
                // Verifica fim
            } while (!feof(archive));
        
            // Fecha arquivo

            fclose(archive);

        }
	} else {
		puts("Erro ao ler da entrada padrão.");
	}
}
void imprimeCertaLetraDicionario(Dicionarie *pLista, char letra){
    int opt = 1;
    CelulaListaPalavras* pAux;
    pAux = pLista->primeiroListaPalavras;
    while (pAux != NULL)
    {
        if(letra == pAux->letraLista){
            Imprime_Listaword(&pAux->listaPalavraPorLetra);
        }
        pAux = pAux->prox; /* próxima célula */
    }
}
void imprimeTudoDicionario(Dicionarie *pLista){
    int opt = 1;
    CelulaListaPalavras* pAux;
    pAux = pLista->primeiroListaPalavras;
    while (pAux != NULL)
    {
        Imprime_Listaword(&pAux->listaPalavraPorLetra);

        pAux = pAux->prox; /* próxima célula */
    }
}