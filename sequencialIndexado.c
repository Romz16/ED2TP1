#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/sequencialIndexado.h"
#include "headers/criaArquivo.h"

int pesquisa (tipoIndice tabela[], tipoItem* item, FILE *arq, int tamanho, int situacao, int itensPagina){
    tipoItem *pagina = (tipoItem*) malloc(sizeof(tipoItem) * itensPagina); 
    int i = 0, quantitens;
    long deslocamento;
    
    // procura pela página onde o item pode se encontrar
    if(situacao == 1)
        while (i < tamanho && tabela[i].chave <= item->chave) i++;
    else if(situacao == 2)
        while (i < tamanho && tabela[i].chave >= item->chave) i++;
    else{
        printf("Arquivo desordenado nao permitido para pesquisa Sequencial Indexada\n");
        free(pagina);
        return 0;
    }
    contComparacaoPesquisa = i;

    // caso a chave desejada seja menor que a 1a chave, o item não existe no arquivo
    if (i == 0) return 0;

    else {
        // a ultima página pode não estar completa
        if (i < tamanho) 
            quantitens = itensPagina;
        else {
            fseek (arq, 0, SEEK_END);
            quantitens = (ftell(arq)/sizeof(tipoItem))%itensPagina;

            if(quantitens == 0)
                quantitens = itensPagina;
        }
        
        // lê a página desejada do arquivo
        deslocamento = (tabela[i-1].posicao-1)*itensPagina*sizeof(tipoItem);
        fseek (arq, deslocamento, SEEK_SET);
        fread (pagina, sizeof(tipoItem), quantitens, arq);

        // pesquisa sequencial na página lida
        // Melhorar a pesquisa ---------------------
        for (i=0; i < quantitens; i++){
            contComparacaoPesquisa++;
            if (pagina[i].chave == item->chave) {
                *item = pagina[i]; 
                free(pagina);
                return 1;
            }
        }
        free(pagina);
        return 0;
    }
}

int sequencialIndexado(int quantidade, int situacao, int chave, char stringOP[]){
    int itensPagina = quantidade/25;
    tipoIndice *tabela = (tipoIndice*) malloc(sizeof(tipoIndice) * quantidade/itensPagina);
    tipoItem *itemTmp = (tipoItem*) malloc(sizeof(tipoItem) * itensPagina); 

    // abre o arquivo de registros---------------------
    // fazer adequada do escolha do arquivo
    FILE *arquivo = abrirArquivo(quantidade, situacao);

    //Medir o tempo de Execução
    clock_t comeco = clock();
    
    // gera a tabela de índice das páginas
    int posicao = 0;
    while (fread(itemTmp, sizeof(tipoItem)*itensPagina, 1, arquivo) == 1){
        if(strcmp("----", stringOP) != 0)
            for (int i = 0; i < itensPagina; i++)
                printf("%i ", itemTmp[i].chave);

        printf("\n");
        tabela[posicao].chave = itemTmp[0].chave;
        tabela[posicao].posicao = posicao+1;
        posicao++;

        contTranferenciaIndexacao++;
    }

    itemTmp[0].chave = chave;

    // ativa a função de pesquisa
    int returno;
    if (pesquisa (tabela, &itemTmp[0], arquivo, posicao, situacao, itensPagina)){
        printf("\nRegistro foi localizado. Dado 1: %li\n\n", itemTmp[0].dado1);
        printf("Numero Comparacoes Pesquisa: %i\n", contComparacaoPesquisa);
        printf("Numero Tranferencia Pesquisa: %i\n", contTranferenciaPesquisa);
        printf("Numero Comparacoes Indexacao: %i\n", contComparacaoPesquisa);
        printf("Numero Tranferencia Indexacao: %i\n\n", contTranferenciaPesquisa);
        returno = 1;
    }
    else{
        printf("Registro nao foi localizado. Chave %i\n", itemTmp[0].chave);
        returno = 0;
    }

    fclose(arquivo);
    free(tabela);
    free(itemTmp);

    clock_t fim = clock();
    double tempoDecorrido = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("Tempo para fazer pesquisa: %lf\n", tempoDecorrido);
    
    
    return returno;
    
}