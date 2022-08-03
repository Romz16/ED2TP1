#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "headers/structs.h"
#include "headers/arvoreB*.h"
#include "headers/arvoreB.h"
#include "headers/arvoreBinaria.h"
#include "headers/sequencialIndexado.h"



/*
pesquisa <método> <quantidade> <situação> <chave> [-P]

<método>  representa  o  método  de  pesquisa  externa  a  ser  executado,  podendo  ser  um  número 
inteiro de 1 a 4, de acordo com a ordem dos métodos mencionados; 

<quantidade> representa a quantidade de registros do arquivo considerado; 

<situação> representa a situação de ordem do arquivo, podendo ser 1 (arquivo ordenado 
ascendentemente), 2 (arquivo ordenado descendentemente) ou 3 (arquivo desordenado 
aleatoriamente); 

<chave> representa a chave a ser pesquisada no arquivo considerado; 

[-P] representa um argumento opcional que deve ser colocado quando se deseja que as chaves de 
pesquisa dos registros do arquivo considerado sejam apresentadas na tela.

*/

int main(int argc, char *argv[]){
    
    if(argc != 6 && argc != 7)
        printf("Erro\n"); //exit(1);

    char pesquisa[10];
    int metodo = atoi(argv[2]);
    int quantidade = atoi(argv[3]);
    int situacao = atoi(argv[4]);
    int chave = atoi(argv[5]);
    char p[5] = "----\0";

    if(argc == 7) strcpy(p, argv[6]);
    strcpy(pesquisa, argv[1]);

    //validar argumentos entrada
    if(strcmp(pesquisa, "pesquisa") != 0)
        printf("Erro\n"); //exit(1);
    if(metodo != 1 && metodo != 2 && metodo != 3 && metodo != 4)
        printf("Erro\n"); //exit(1);
    if(quantidade <= 0 || quantidade > 1000000)
        printf("Erro\n"); //exit(1);
    if(situacao != 1 && situacao != 2 && situacao != 3)
        printf("Erro\n"); //exit(1);
    //chave inteiro qualquer
    //p argumento adicional

    printf("%s %i %i %i %i %s\n", pesquisa, metodo, quantidade, situacao, chave, p);

    switch (metodo){
    case 1: sequencialIndexado(quantidade, situacao, chave, p);
        break;
    case 2: 
        break;
    case 3: 
        break;
    case 4: 
        break;

    default: printf("Erro\n"); exit(1); 
        break;
    }



    return 0;
}