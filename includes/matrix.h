#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** criaMatrizInt(int tamanho);
float ** criaMatrizFloat(int tamanho);
int ** criaJanela(int ** matriz, int tam, int i, int j);

void destroiMatriz(int ** matriz, int tam);
void destroiMatrizFloat(float ** matriz, int tam);

void imprimeMatriz(int ** matriz, int tamanho);
void imprimeMatrizFloat(float ** matriz, int tamanho);
void instanciaMatrizZero(int ** matriz, int tamanho);
int ** instaciaMatrizCSV(const char * diretorio, int tam);
#endif