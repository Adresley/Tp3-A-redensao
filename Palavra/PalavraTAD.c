#include "PalavraTAD.h"



/* Atua como se fosse a fgets sendo chamada com o fluxo da entrada padrão, stdin,
   mas não inclui a nova linha na string */
char* lerStringSeguramente(char* string, int tamanho) {
	if(fgets(string, tamanho, stdin) != NULL) {
		/* Remove a nova linha (\n), caso ela tenha sido lida pelo fgets */
		int indiceUltimoCaractere = strlen(string) - 1;
		if(string[indiceUltimoCaractere] == '\n') {
			string[indiceUltimoCaractere] = '\0';
		}
		return string;
	}
	return NULL;
}

Palavra* Palavra_vazia( Palavra *pPalavra, int tam){
    pPalavra =(Palavra*) malloc( sizeof(Palavra));
    pPalavra->palavra = (char*) malloc(tam * sizeof(char));
    IniciaVazia(&pPalavra->lista);
   
   return pPalavra;

}
void Preenche_palavra(Palavra *pPalavra, char *palavra, int linha){
    if(pPalavra != NULL){
        strcpy(pPalavra->palavra, palavra);

        if (pPalavra->palavra[strlen(pPalavra->palavra) - 1] == '\n') {
            pPalavra->palavra[strlen(pPalavra->palavra) - 1] = '\0';
        }
        Insere(&pPalavra->lista, linha);
    }else{
        printf("ERRO");

    }
}
char* Retorna_caracteres(Palavra *pPalavra){
    return pPalavra->palavra;
}
void Imprime_caracteres(Palavra *pPalavra){
    printf("Palavra: %s\n", pPalavra->palavra);
}
void Imprime_palavra(Palavra *pPalavra){
    printf("Palavra: %s\n", pPalavra->palavra);
    Imprime_ListaNum(&pPalavra->lista);
}
/*
void separaArquivo(){
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
                    if(temListaPalavraDessaLetra(pLista, palavraSeparada[0]) == 0){
                        // se sim insere palavra e linha nessa
                        
                        Insere_fim (ListaPalavraDessaLetra(pLista, palavraSeparada[0]), pPalavra);
                        
                    }/*else{
                        // senão cria insere lista de palavras com essa letra e coloca palavra
                        insereListaOrdenada( pLista, palavraSeparada[0]);
                        Insere_fim (ListaPalavraDessaLetra(pLista, palavraSeparada[0]), pPalavra);
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

}*/