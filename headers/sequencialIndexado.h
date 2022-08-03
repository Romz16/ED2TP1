#include "tipoItem.h"

#ifndef SEQUENCIAL_INDEXADO
#define SEQUENCIAL_INDEXADO

int pesquisa(tipoIndice tab[], int tam, tipoItem* item, FILE *arq);
int sequencialIndexado(int quantidade, int situacao, int chave, char p[]);

#endif