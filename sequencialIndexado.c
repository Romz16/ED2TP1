#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/sequencialIndexado.h"
#include "headers/criaArquivo.h"

#define ITENSPAGINA 4
#define MAXTABELA 100

int pesquisa (tipoIndice tab[], int tam, tipoItem* item, FILE *arq){
    tipoItem pagina[ITENSPAGINA];
    int i, quantitens;
    long desloc;
    
    // procura pela página onde o item pode se encontrar
    i = 0;
    while (i < tam && tab[i].chave <= item->chave) i++;

    // caso a chave desejada seja menor que a 1a chave, o item não existe no arquivo
    if (i == 0) return 0;

    else {
        // a ultima página pode não estar completa
        if (i < tam) 
            quantitens = ITENSPAGINA;
        else {
            fseek (arq, 0, SEEK_END);
            quantitens = (ftell(arq)/sizeof(tipoItem))%ITENSPAGINA;

            if(quantitens == 0)
                quantitens = ITENSPAGINA;
        }
        
        // lê a página desejada do arquivo
        desloc = (tab[i-1].posicao-1)*ITENSPAGINA*sizeof(tipoItem);
        fseek (arq, desloc, SEEK_SET);
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

int sequencialIndexado(int quantidade, int situacao, int chave, char p[]){
    tipoIndice tabela[MAXTABELA];
    tipoItem itemTmp[ITENSPAGINA]; 
    //tipoItemTeste itemTmpTeste[4]; 
    //tipoItem tmp; 

    // abre o arquivo de registros---------------------
    // fazer adequada do escolha do arquivo
    FILE *arquivo = escolherArquivo();

    // ----------------
    // gera a tabela de índice das páginas
    // Mudar. Usar um fread pra ler 4 registro e depois ir sobrepondo ---------------------
    int pos = 0;
    while (fread(itemTmp, sizeof(tipoItem)*4, 1, arquivo) == 1) {

        tabela[pos].chave = itemTmp[0].chave;
        tabela[pos].posicao = pos+1;
        pos++;
    
    }

    itemTmp[0].chave = chave;

    // ativa a função de pesquisa
    // Mudar a saida ---------------------
    if (pesquisa (tabela, pos, &itemTmp[0], arquivo))
        printf ("Registro %li (codigo %d) foi localizado %s\n", itemTmp[0].dado1, itemTmp[0].chave, p);
    else
        printf ("Registro de código %d nao foi localizado\n", itemTmp[0].chave);

    fclose (arquivo);
    return 0;
}