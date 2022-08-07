#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "headers/criaArquivo.h"


FILE *escolherArquivo(){
    FILE *arquivo = NULL;

    arquivo = fopen("files/file100.bin", "rb");

    if (arquivo){
        return arquivo;
    }
    
    printf("Erro Ao Abrir Arquivo");
    return NULL; // error
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


int criaArquivo(){
    tipoItem registro;
    FILE *arquivo;
    int tamanho = 10;

    srand(time(NULL));

    if((arquivo = fopen("files/file100.bin", "wb")) == NULL){
        printf("ERRO\n");
        return 0;
    } 

    for (int i = 0; i < tamanho; i++){
        registro.chave = i;
        registro.dado1 = rand();

        randString(registro.dado2, 1000);
        randString(registro.dado3, 5000);

        fwrite(&registro, sizeof(tipoItem), 1, arquivo);

    }

    fclose(arquivo);

    return 0;
}