// struct.h
#ifndef STRUCT_H
#define STRUCT_H

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
