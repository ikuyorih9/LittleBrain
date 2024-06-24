#ifndef FILTROS_H
#define FILTROS_H
#include <stdio.h>
#include "matrix.h"

#define TAMANHO_IMAGEM 9
#define TAMANHO_FILTRO 3
#define TAMANHO_MAP (TAMANHO_IMAGEM - 2)

#define FILTRO_1_PATH "./filters/filtro1.csv"
#define FILTRO_2_PATH "./filters/filtro2.csv"
#define FILTRO_3_PATH "./filters/filtro3.csv"

#define TRAIN_X_PATH "treinamentoX.txt"
#define TRAIN_O_PATH "treinamentoO.txt"

float * propagacaoDireta(int ** imagem, int ** filtro);
float ** convolucao(int ** imagem, int ** filtro);
void reLu(float ** featureMap);
int pooling(float *** featureMap, int tamanho);
float * flattening(float ** pooledMap, int tamanho);
float verificaSemelhanca(float * imagemBase, float * imagem, int tamanho);
float * juntaTresFiltros(float * vector1, float * vector2, float * vector3, int tamanho);
int produtoEscalarFiltro(int ** janela, int ** filtro);
void classificaImagem(int ** imagem);
float * abreVetorArquivo(char * linha, int tamanho);
void treina(int ** imagem);
#endif