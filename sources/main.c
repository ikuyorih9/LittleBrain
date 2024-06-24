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
#define TRAINO4 "./images/train/trainO_4.csv"
#define TRAINO5 "./images/train/trainO_5.csv"

#define TESTX1 "./images/test/testX_1.csv"
#define TESTX2 "./images/test/testX_2.csv"

#define TESTO1 "./images/test/testO_1.csv"
#define TESTO2 "./images/test/testO_2.csv"


int main(){
    int ** imagemTesteX1 = instaciaMatrizCSV(TESTX1, TAMANHO_IMAGEM);
    int ** imagemTesteX2 = instaciaMatrizCSV(TESTX2, TAMANHO_IMAGEM);
    
    printf("Testando imagem X1 de teste...\n");
    classificaImagem(imagemTesteX1);

    printf("Testando imagem X2 de teste...\n");
    classificaImagem(imagemTesteX2);

    destroiMatriz(imagemTesteX1, TAMANHO_IMAGEM);
    destroiMatriz(imagemTesteX2, TAMANHO_IMAGEM);
    
    int ** imagemTesteO1 = instaciaMatrizCSV(TESTO1, TAMANHO_IMAGEM);
    int ** imagemTesteO2 = instaciaMatrizCSV(TESTO2, TAMANHO_IMAGEM);

    printf("Testando imagem O1 de teste...\n");
    classificaImagem(imagemTesteO1);

    printf("Testando imagem O1 de teste...\n");
    classificaImagem(imagemTesteO2);
    
    destroiMatriz(imagemTesteO1, TAMANHO_IMAGEM);
    destroiMatriz(imagemTesteO2, TAMANHO_IMAGEM);

    return 0;
}