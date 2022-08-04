#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "headers/criaArquivo.h"

/*
Diretivas de Compilação

gcc criaArquivo.c -o criaArquivo.exe -Wall
./criaArquivo.exe 
*/

char *rand_string(char *str, int size){
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    --size;

    for (int n = 0; n < size; n++) {
        int key = rand() % (int) (sizeof(charset) - 1);
        str[n] = charset[key];
    }
    str[size] = '\0';

    return str;
}


int criaArquivo(){
    tipoItem registro1;
    FILE *arquivo;
    int tamanho = 100;

    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    int size = 1000;

    srand(time(NULL));

    if((arquivo = fopen("files/file100.bin", "wb")) == NULL){
        printf("ERRO\n");
        exit(1);
    } 

    for (int i = 0; i < tamanho; i++){
        registro1.chave = i;
        registro1.dado1 = rand();

        size = 1000;
        --size;

        for (int n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof(charset) - 1);
            registro1.dado2[n] = charset[key];
        }
        registro1.dado2[size] = '\0';

        size = 5000;
        --size;

        for (int n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof(charset) - 1);
            registro1.dado3[n] = charset[key];
        }
        registro1.dado3[size] = '\0';

        fwrite(&registro1, sizeof(tipoItem), 1, arquivo);

    }

    fclose(arquivo);

    return 0;
}