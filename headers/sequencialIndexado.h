#include "structs.h"

#ifndef SEQUENCIAL_INDEXADO
#define SEQUENCIAL_INDEXADO

int sequencialIndexado(int quantidade, int situacao, int chave, char stringOP[]);
int PesquisaSequencialIndexado(tipoIndice tabela[], tipoItem* item, FILE *arq, int tamanho, int situacao, int itensPagina);

#endif