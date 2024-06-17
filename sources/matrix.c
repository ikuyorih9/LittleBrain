#include "matrix.h"

int ** criaMatrizInt(int tamanho){
    int ** matriz = (int**) malloc(tamanho * sizeof(int*));
    for(int i = 0; i < tamanho; i++){
        matriz[i] = (int *) malloc(tamanho * sizeof(int));
    }
    return matriz;
}

float ** criaMatrizFloat(int tamanho){
    float ** matriz = (float**) malloc(tamanho * sizeof(float*));
    for(int i = 0; i < tamanho; i++){
        matriz[i] = (float *) malloc(tamanho * sizeof(float));
    }
    return matriz;
}

int ** criaJanela(int ** matriz, int tam, int i, int j){
    int ** janela = criaMatrizInt(tam);
    for(int x = 0; x < tam; x++){
        for( int y = 0; y < tam; y++){
            janela[x][y] = matriz[i + x][j + y];
        }
    }
    return janela;
}

void destroiMatriz(int ** matriz, int tam) {
    for(int i = 0 ; i < tam; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void destroiMatrizFloat(float ** matriz, int tam) {
    for(int i = 0 ; i < tam; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void imprimeMatriz(int ** matriz, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimeMatrizFloat(float ** matriz, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void instanciaMatrizZero(int ** matriz, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            matriz[i][j] = 0;
        }
    }
}

int ** instaciaMatrizCSV(const char * diretorio, int tam){
    FILE * arquivo = fopen(diretorio, "r");
    if(arquivo == NULL){
        printf("ERRO: nao foi possivel abrir o arquivo\n");
        exit(0);
    }

    int **matriz = criaMatrizInt(tam);
    int x = 0;
    do {
        char linha[32];
        fgets(linha, 32, arquivo);
        char * num = strtok(linha, ",");
        for(int y = 0; y < tam; y++) {
            matriz[x][y] = atoi(num);
            num = strtok(NULL, ",");
        }
        x++;
    } 
    while(!feof(arquivo));
    fclose(arquivo);
    return matriz;
}
