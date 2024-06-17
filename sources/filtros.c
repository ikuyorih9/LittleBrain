#include "filtros.h"

// const int filtro1[TAMANHO_FILTRO][TAMANHO_FILTRO] = {{1,-1,-1},{-1,1,-1},{-1,-1,1}};
// const int filtro2[TAMANHO_FILTRO][TAMANHO_FILTRO] = {{1,-1,1},{-1,1,-1},{1,-1,1}};
// const int filtro3[TAMANHO_FILTRO][TAMANHO_FILTRO] = {{-1,-1,1},{-1,1,-1},{1,-1,-1}};

float ** convolucao(int ** imagem, int **filtro){
    float ** featureMap = criaMatrizFloat(TAMANHO_MAP);

    for(int i = 0; i < TAMANHO_MAP; i++){
        for( int j = 0; j < TAMANHO_MAP; j++){
            int ** janela = criaJanela(imagem, TAMANHO_FILTRO, i, j);
            featureMap[i][j] = ((float)produtoEscalarFiltro(janela, filtro))/9;
            destroiMatriz(janela, TAMANHO_FILTRO);
        }
    }
    return featureMap;
}

void reLu(float ** featureMap){
    for(int i = 0; i < TAMANHO_IMAGEM - 2; i++){
        for(int j =0; j < TAMANHO_IMAGEM - 2; j++){
            if(featureMap[i][j] < 0)
                featureMap[i][j] = 0;
        }
    }
}

void pooling(float ** featureMap){
    for(int x = 0; x < TAMANHO_MAP; x+=2){
        for(int j = 0; j < TAMANHO_MAP; j++){
            if(x+1 < TAMANHO_MAP && featureMap[x][j] < featureMap[x+1][j])
                featureMap[x][j] = featureMap[x+1][j];
        }
    }

    for(int y = 0; y < TAMANHO_MAP; y+=2){
        for(int i = 0; i < TAMANHO_MAP; i++){
            if(y+1 < TAMANHO_MAP && featureMap[i][y] < featureMap[i][y+1])
                featureMap[i][y] = featureMap[i][y+1];
        }
    }

}

int produtoEscalarFiltro(int ** janela, int ** filtro){
    int produto = 0;
    for(int i = 0; i < TAMANHO_FILTRO; i++){
        for(int j = 0; j < TAMANHO_FILTRO; j++){
            produto += janela[i][j] * filtro[i][j];
        }
    }
    return produto;
}