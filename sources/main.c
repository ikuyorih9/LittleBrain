#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtros.h"
#include "matrix.h"

#define TRAINX1 "./images/train/trainX_1.csv"
#define TRAINX2 "./images/train/trainX_2.csv"
#define TRAINX3 "./images/train/trainX_3.csv"
#define TRAINX4 "./images/train/trainX_4.csv"
#define TRAINX5 "./images/train/trainX_5.csv"

#define TRAINO1 "./images/train/trainO_1.csv"
#define TRAINO2 "./images/train/trainO_2.csv"
#define TRAINO3 "./images/train/trainO_3.csv"

#define TESTX1 "./images/test/testX_1.csv"
#define TESTX2 "./images/test/testX_2.csv"


int main(){
    printf("Hello world!\n");

    // int ** imagemTesteX1 = instaciaMatrizCSV(TRAINX1, TAMANHO_IMAGEM);
    // int ** imagemTesteX2 = instaciaMatrizCSV(TRAINX2, TAMANHO_IMAGEM);
    // int ** imagemTesteX3 = instaciaMatrizCSV(TRAINX3, TAMANHO_IMAGEM);
    // int ** imagemTesteX4 = instaciaMatrizCSV(TRAINX4, TAMANHO_IMAGEM);
    // int ** imagemTesteX5 = instaciaMatrizCSV(TRAINX5, TAMANHO_IMAGEM);
    // int ** imagemTesteO1 = instaciaMatrizCSV(TRAINO1, TAMANHO_IMAGEM);
    // int ** imagemTesteO2 = instaciaMatrizCSV(TRAINO2, TAMANHO_IMAGEM);
    // int ** imagemTesteO3 = instaciaMatrizCSV(TRAINO3, TAMANHO_IMAGEM);

    int ** imagemTesteX1 = instaciaMatrizCSV(TESTX1, TAMANHO_IMAGEM);
    int ** imagemTesteX2 = instaciaMatrizCSV(TESTX2, TAMANHO_IMAGEM);

    printf("Testando imagem X1 de teste...\n");
    classificaImagem(imagemTesteX1);

    printf("Testando imagem X2 de teste...\n");
    classificaImagem(imagemTesteX2);

    // printf("Testando imagem X3 de teste...\n");
    // classificaImagem(imagemTesteX3);

    // printf("Testando imagem X4 de teste...\n");
    // classificaImagem(imagemTesteX4);

    // printf("Testando imagem O de teste...\n");
    // classificaImagem(imagemTesteO);

    //treina(imagemTesteO1);


    destroiMatriz(imagemTesteX1, TAMANHO_IMAGEM);
    destroiMatriz(imagemTesteX2, TAMANHO_IMAGEM);
    // destroiMatriz(imagemTesteX3, TAMANHO_IMAGEM);
    // destroiMatriz(imagemTesteX4, TAMANHO_IMAGEM);
    // destroiMatriz(imagemTesteO1, TAMANHO_IMAGEM);
    // destroiMatriz(imagemTesteO2, TAMANHO_IMAGEM);

    return 0;
}