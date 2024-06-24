#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtros.h"
#include "matrix.h"

#define TESTX1 "./images/train/trainX_1.csv"
#define TESTX2 "./images/train/trainX_2.csv"
#define TESTX3 "./images/train/trainX_3.csv"
#define TESTX4 "./images/train/trainX_4.csv"
#define TESTX5 "./images/train/trainX_5.csv"
#define TESTO "./images/train/trainO_1.csv"



int main(){
    printf("Hello world!\n");

    int ** imagemTesteX1 = instaciaMatrizCSV(TESTX1, TAMANHO_IMAGEM);
    int ** imagemTesteX2 = instaciaMatrizCSV(TESTX2, TAMANHO_IMAGEM);
    int ** imagemTesteX3 = instaciaMatrizCSV(TESTX3, TAMANHO_IMAGEM);
    int ** imagemTesteX4 = instaciaMatrizCSV(TESTX4, TAMANHO_IMAGEM);
    int ** imagemTesteX5 = instaciaMatrizCSV(TESTX5, TAMANHO_IMAGEM);
    int ** imagemTesteO = instaciaMatrizCSV(TESTO, TAMANHO_IMAGEM);

    // printf("Testando imagem X1 de teste...\n");
    // classificaImagem(imagemTesteX);

    // printf("Testando imagem X2 de teste...\n");
    // classificaImagem(imagemTesteX2);

    // printf("Testando imagem X3 de teste...\n");
    // classificaImagem(imagemTesteX3);

    // printf("Testando imagem X4 de teste...\n");
    // classificaImagem(imagemTesteX4);

    // printf("Testando imagem O de teste...\n");
    // classificaImagem(imagemTesteO);

    treina(imagemTesteX1);
    treina(imagemTesteX2);
    treina(imagemTesteX3);
    treina(imagemTesteX4);
    treina(imagemTesteX5);


    destroiMatriz(imagemTesteX1, TAMANHO_IMAGEM);
    destroiMatriz(imagemTesteX2, TAMANHO_IMAGEM);
    destroiMatriz(imagemTesteX3, TAMANHO_IMAGEM);
    destroiMatriz(imagemTesteX4, TAMANHO_IMAGEM);
    destroiMatriz(imagemTesteO, TAMANHO_IMAGEM);

    return 0;
}