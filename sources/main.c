#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtros.h"
#include "matrix.h"

#define IMAGE_X_PATH "./images/x.csv"
#define IMAGE_O_PATH "./images/o.csv"
#define FILTRO_1_PATH "./filters/filtro1.csv"
#define FILTRO_2_PATH "./filters/filtro2.csv"
#define FILTRO_3_PATH "./filters/filtro3.csv"

int main(){
    printf("Hello world!\n");

    int ** imagemX = instaciaMatrizCSV(IMAGE_X_PATH, TAMANHO_IMAGEM);
    imprimeMatriz(imagemX, TAMANHO_IMAGEM);

    int ** filtro1 = instaciaMatrizCSV(FILTRO_1_PATH, TAMANHO_FILTRO);
    int ** filtro2 = instaciaMatrizCSV(FILTRO_2_PATH, TAMANHO_FILTRO);
    int ** filtro3 = instaciaMatrizCSV(FILTRO_3_PATH, TAMANHO_FILTRO);

    // int ** janela = criaJanela(imagemX, 3, 0, 0);
    // imprimeMatriz(janela, 3);

    // int num = produtoEscalar(janela, filtro1, 3);
    // printf("num = %d\n", num);



    // destroiMatriz(imagemX, TAMANHO_IMAGEM);
    // destroiMatriz(janela, 3);

    printf("\n");

    float ** featureMap = convolucao(imagemX, filtro1);
    imprimeMatrizFloat(featureMap, TAMANHO_IMAGEM - 2);

    printf("\n");

    reLu(featureMap);
    imprimeMatrizFloat(featureMap, TAMANHO_IMAGEM - 2);

    printf("\n");

    pooling(featureMap);
    imprimeMatrizFloat(featureMap, TAMANHO_IMAGEM - 2);

    printf("\n");

    for(int i = 0; i < TAMANHO_MAP; i+=2){
        for(int j = 0; j < TAMANHO_MAP; j+=2){
            printf("%.2f ", featureMap[i][j]);
        }
        printf("\n");
    }

    destroiMatriz(imagemX, TAMANHO_IMAGEM);
    destroiMatriz(filtro1, TAMANHO_FILTRO);
    destroiMatriz(filtro2, TAMANHO_FILTRO);
    destroiMatriz(filtro3, TAMANHO_FILTRO);
    destroiMatrizFloat(featureMap, TAMANHO_MAP);
    return 0;
}