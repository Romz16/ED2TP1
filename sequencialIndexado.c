#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/sequencialIndexado.h"
#include "headers/criaArquivo.h"

#define ITENSPAGINA 4
#define MAXTABELA 100

int pesquisa (tipoIndice tabela[], int tamanho, int situacao, tipoItem* item, FILE *arq){
    tipoItem pagina[ITENSPAGINA];
    int i = 0, quantitens;
    long deslocamento;
    
    // procura pela página onde o item pode se encontrar
    if(situacao == 1)
        while (i < tamanho && tabela[i].chave >= item->chave) i++;
    if(situacao == 2)
        while (i < tamanho && tabela[i].chave <= item->chave) i++;


    // caso a chave desejada seja menor que a 1a chave, o item não existe no arquivo
    if (i == 0) return 0;

    else {
        // a ultima página pode não estar completa
        if (i < tamanho) 
            quantitens = ITENSPAGINA;
        else {
            fseek (arq, 0, SEEK_END);
            quantitens = (ftell(arq)/sizeof(tipoItem))%ITENSPAGINA;

            if(quantitens == 0)
                quantitens = ITENSPAGINA;
        }
        
        // lê a página desejada do arquivo
        deslocamento = (tabela[i-1].posicao-1)*ITENSPAGINA*sizeof(tipoItem);
        fseek (arq, deslocamento, SEEK_SET);
        fread (&pagina, sizeof(tipoItem), quantitens, arq);

        // pesquisa sequencial na página lida
        // Melhorar a pesquisa ---------------------
        for (i=0; i < quantitens; i++)
            if (pagina[i].chave == item->chave) {
                *item = pagina[i]; return 1;
        }
        return 0;
    }
}

int sequencialIndexado(int quantidade, int situacao, int chave, char stringOP[]){
    tipoIndice *tabela = (tipoIndice*) malloc(sizeof(tipoIndice) * MAXTABELA);
    tipoItem *itemTmp = (tipoItem*) malloc(sizeof(tipoItem) * ITENSPAGINA); 

    // abre o arquivo de registros---------------------
    // fazer adequada do escolha do arquivo
    FILE *arquivo = abrirArquivo(MAXTABELA, 1);

    // gera a tabela de índice das páginas
    int posicao = 0;
    while (fread(itemTmp, sizeof(tipoItem)*4, 1, arquivo) == 1){
        if(strcmp("----", stringOP) != 0)
            printf("%i\n%i\n%i\n%i\n", itemTmp[0].chave, itemTmp[1].chave, itemTmp[2].chave, itemTmp[3].chave);
            
        tabela[posicao].chave = itemTmp[0].chave;
        tabela[posicao].posicao = posicao+1;
        posicao++;
    }

    itemTmp[0].chave = chave;
    // ativa a função de pesquisa
    int returno;
    if (pesquisa (tabela, posicao, situacao, &itemTmp[0], arquivo)){
        printf ("Registro foi localizado. Dado 1: %li\n", itemTmp[0].dado1);
        returno = 1;
    }
    else{
        printf ("Registro nao foi localizado. Chave %i\n", itemTmp[0].chave);
        returno = 0;
    }

    fclose(arquivo);
    free(tabela);
    free(itemTmp);
    return returno;
    
}