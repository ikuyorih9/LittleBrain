#ifndef FILTROS_H
#define FILTROS_H
#include <stdio.h>
#include "matrix.h"

#define TAMANHO_IMAGEM 9
#define TAMANHO_FILTRO 3
#define TAMANHO_MAP (TAMANHO_IMAGEM - 2)

float ** convolucao(int ** imagem, int ** filtro);
void reLu(float ** featureMap);
void pooling(float ** featureMap);
int produtoEscalarFiltro(int ** janela, int ** filtro);
#endif