#include "structs.h"

#ifndef SEQUENCIAL_INDEXADO
#define SEQUENCIAL_INDEXADO

int sequencialIndexado(int quantidade, int situacao, int chave, char p[]);
int pesquisaSequencialIndexado(tipoIndice tab[], int tam, tipoItem* item, FILE *arq);

#endif