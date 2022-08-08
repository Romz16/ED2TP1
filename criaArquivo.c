#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "headers/criaArquivo.h"


FILE *abrirArquivo(int quantidade, int situacao){
    FILE *arquivo = NULL;

    char nomeArquivo[50] = "files/";
    char stringQuantidade[10];

    if(situacao == 1){
        sprintf(stringQuantidade, "%d", quantidade);
        strcat(nomeArquivo, stringQuantidade);
        strcat(nomeArquivo, "Crescente.bin");
    }
    else if(situacao == 2){
        sprintf(stringQuantidade, "%d", quantidade);
        strcat(nomeArquivo, stringQuantidade);
        strcat(nomeArquivo, "Decrescente.bin");
    }
    else if(situacao == 3){
        sprintf(stringQuantidade, "%d", quantidade);
        strcat(nomeArquivo, stringQuantidade);
        strcat(nomeArquivo, "Aleatorio.bin");
    }

    if((arquivo = fopen(nomeArquivo, "rb")) == NULL){
        printf("Criando Arquivo\n");
        criaArquivo(quantidade, situacao);
        arquivo = fopen(nomeArquivo, "rb");
    }
    if(arquivo == NULL){
        printf("Erro Ao Abrir Arquivo");
        return NULL; // error
    }

    return arquivo;

}

void randString(char *str, int size){
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    --size;

    for (int n = 0; n < size; n++) {
        int key = rand() % (int) (sizeof(charset) - 1);
        str[n] = charset[key];
    }
    str[size] = '\0';

}

void embaralhaVetor(int *array, int n){
    
    for (int i = 0; i < n; i++){
        array[i] = i;
    }

    for (int i = 0; i < n - 1; i++){          
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

int criaArquivo(int quantidade, int situacao){
    tipoItem registro;
    FILE *arquivo;
    char nomeArquivo[50] = "files/";
    char stringQuantidade[10];
    int *vetorQuantidade = (int*) malloc(sizeof(int) * quantidade);

    srand(time(NULL));

    if(situacao == 1){
        sprintf(stringQuantidade, "%d", quantidade);
        strcat(nomeArquivo, stringQuantidade);
        strcat(nomeArquivo, "Crescente.bin");
    }
    else if(situacao == 2){
        sprintf(stringQuantidade, "%d", quantidade);
        strcat(nomeArquivo, stringQuantidade);
        strcat(nomeArquivo, "Decrescente.bin");
    }
    else if(situacao == 3){
        sprintf(stringQuantidade, "%d", quantidade);
        strcat(nomeArquivo, stringQuantidade);
        strcat(nomeArquivo, "Aleatorio.bin");
    }


    if((arquivo = fopen(nomeArquivo, "wb")) == NULL){
        printf("ERRO\n");
        return 0;
    } 

    if(situacao == 1){
        for (int i = 0; i < quantidade; i++){
            registro.chave = i;
            registro.dado1 = rand();

            randString(registro.dado2, 1000);
            randString(registro.dado3, 5000);

            fwrite(&registro, sizeof(tipoItem), 1, arquivo);

        }
    }
    
    else if(situacao == 2){
        for (int i = quantidade-1; i >= 0; i--){
            registro.chave = i;
            registro.dado1 = rand();

            randString(registro.dado2, 1000);
            randString(registro.dado3, 5000);

            fwrite(&registro, sizeof(tipoItem), 1, arquivo);

        }
    }

    else if(situacao == 3){
        embaralhaVetor(vetorQuantidade, quantidade);
        for (int i = 0; i < quantidade; i++){
            registro.chave = vetorQuantidade[i];
            registro.dado1 = rand();

            randString(registro.dado2, 1000);
            randString(registro.dado3, 5000);

            fwrite(&registro, sizeof(tipoItem), 1, arquivo);

        }
    }

    free(vetorQuantidade);
    fclose(arquivo);

    return 0;
}