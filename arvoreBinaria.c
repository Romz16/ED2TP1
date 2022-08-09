#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/arvoreBinaria.h"
#include "headers/criaArquivo.h"

int pesquisaArvoreBinaria(tipoIndice tab[], int tam, tipoItem* item, FILE *arq){

    //ler do arquivo arvoreBinariaExterna.bin e montar uma árvore binaria e fazer a pesquisa 
}

int arvoreBinaria(int quantidade, int situacao, int chave, char stringOP[]){
    tipoItem itemTmp;
    tipoItemArvoreBinariaExterna itemArvore;

    // abre o arquivo de registros---------------------
    // fazer adequada do escolha do arquivo
    FILE *arquivoRegistros = abrirArquivo(quantidade, situacao);
    FILE *arquivoArvore = abrirArquivo(quantidade, situacao);
    
    if((arquivoArvore = fopen("files/arvoreBinariaExterna.bin", "wb")) == NULL){
        printf("Erro Ao Abrir Arquivo");
        return 0; 
    }

    //Medir o tempo de Execução
    clock_t comeco = clock();

    while (fread(&itemTmp, sizeof(tipoItem), 1, arquivoRegistros) == 1){
        fwrite(&itemTmp, sizeof(tipoItemArvoreBinariaExterna), 1, arquivoArvore);
        
        //O pai vai ser um dos 2 anteriores
        //voltar no registro pai e arrumar o indice dele 
    }
    


    clock_t fim = clock();
    double tempoDecorrido = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("Tempo para fazer pesquisa: %lf\n", tempoDecorrido);
    
    
    return 0;

}