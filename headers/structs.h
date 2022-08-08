// struct.h
#ifndef STRUCT_H
#define STRUCT_H

int contTranferenciaIndexacao;
int contTranferenciaPesquisa;
int contComparacaoPesquisa;
int contComparacaoIndexacao;

typedef struct{
    int chave;
    long int dado1;
    char dado2[1000];
    char dado3[5000];
}tipoItem;

typedef struct {
    int posicao;
    int chave;
}tipoIndice;

#endif
