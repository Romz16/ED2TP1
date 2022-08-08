#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "headers/criaArquivo.h"
#include "headers/structs.h"
#include "headers/arvoreB*.h"
#include "headers/arvoreB.h"
#include "headers/arvoreBinaria.h"
#include "headers/sequencialIndexado.h"

/*
gcc *.c -o out.exe -Wall
./out.exe pesquisa 1 100 2 50 [-P]
*/

int main(int argc, char *argv[]){

    // criaArquivo(100, 1);
    // criaArquivo(100, 2);
    // criaArquivo(100, 3);

    // criaArquivo(1000, 1);
    // criaArquivo(1000, 2);
    // criaArquivo(1000, 3);

    // criaArquivo(10000, 1);
    // criaArquivo(10000, 2);
    // criaArquivo(10000, 3);

    // criaArquivo(100000, 1);
    // criaArquivo(100000, 2);
    // criaArquivo(100000, 3);

    // criaArquivo(1000000, 1);
    // criaArquivo(1000000, 2);
    // criaArquivo(1000000, 3);

    if(argc != 6 && argc != 7){
        printf("Erro1\n"); return 1;
    }

    char pesquisa[10];
    int metodo = atoi(argv[2]);
    int quantidade = atoi(argv[3]);
    int situacao = atoi(argv[4]);
    int chave = atoi(argv[5]);
    char p[5] = "----\0";

    contTranferenciaPesquisa = 0;
    contTranferenciaIndexacao = 0;
    contComparacaoPesquisa = 0;
    contComparacaoIndexacao = 0;

    if(argc == 7) strcpy(p, argv[6]);
    strcpy(pesquisa, argv[1]);

    //validar argumentos entrada
    if(strcmp(pesquisa, "pesquisa") != 0){
        printf("Erro2\n"); return 1;
    }
    if(metodo != 1 && metodo != 2 && metodo != 3 && metodo != 4){
        printf("Erro3\n"); return 1;
    }
    if(quantidade <= 0 || quantidade > 1000000){
        printf("Erro4\n"); return 1;
    }
    if(situacao != 1 && situacao != 2 && situacao != 3){
        printf("Erro5\n"); return 1;
    }
    if((chave >= 0 && chave < 0)){
        printf("Erro6\n"); return 1;
    }

    switch (metodo){
    case 1: sequencialIndexado(quantidade, situacao, chave, p);
        break;
    case 2: 
        break;
    case 3: 
        break;
    case 4: 
        break;
    }

    return 0;
}