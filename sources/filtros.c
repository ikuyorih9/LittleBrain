#include "filtros.h"


float * propagacaoDireta(int ** imagem, int ** filtro){
    int tamanho = TAMANHO_MAP;
    
    float ** featureMap = convolucao(imagem, filtro);

    reLu(featureMap);

    tamanho = pooling(&featureMap, TAMANHO_MAP);

    tamanho = pooling(&featureMap, tamanho);

    float * vector = flattening(featureMap, tamanho);

    return vector;
}

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

int pooling(float *** featureMap, int tamanho){
    for(int x = 0; x < tamanho; x+=2){
        for(int j = 0; j < tamanho; j++){
            if(x+1 < tamanho && (*featureMap)[x][j] < (*featureMap)[x+1][j]){
                (*featureMap)[x][j] = (*featureMap)[x+1][j];
                (*featureMap)[x+1][j] = 0;
            }
        }
    }

    for(int y = 0; y < tamanho; y+=2){
        for(int i = 0; i < tamanho; i++){
            if(y+1 < tamanho && (*featureMap)[i][y] < (*featureMap)[i][y+1]){
                (*featureMap)[i][y] = ((*featureMap))[i][y+1];
                (*featureMap)[i][y+1] = 0;
            }
        }
    }

    int tamanhoPooledMap = tamanho/2 + (tamanho%2);

    float ** pooledMap = criaMatrizFloat(tamanhoPooledMap);

    for(int i = 0, x = 0; i < tamanho; i+=2, x++){
        for(int j = 0, y = 0; j < tamanho; j+=2, y++){
            (pooledMap)[x][y] = (*featureMap)[i][j];
        }
    }
    destroiMatrizFloat(featureMap, tamanho);
    *featureMap = pooledMap;
    return tamanhoPooledMap;
}

float * flattening(float ** pooledMap, int tamanho){
    float * vector = (float*) malloc(sizeof(tamanho * tamanho));
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            vector[i*tamanho + j] = pooledMap[i][j];
        }
    }
    destroiMatrizFloat(&pooledMap, tamanho);
    return vector;
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

float verificaSemelhanca(float * imagemBase, float * imagem, int tamanho){
    int cont = 0;
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        if(imagemBase[i] == 1.0){
            //printf("(%d)\t\t%.2f > 0,7 --> %.2f\n",i,imagemBase[i], imagem[i]);
            soma += imagem[i];
            cont++;
        }
    }

    float porcentagem = 0.0;
    if(cont != 0)
        porcentagem = soma/cont;

    return porcentagem;
}

float * juntaTresFiltros(float * vector1, float * vector2, float * vector3, int tamanho){
    float * vector = (float*)malloc(3*tamanho*sizeof(float));
    if(vector == NULL){
        printf("Erro ao alocar vetor!\n");
        exit(-1);
    }

    for(int i = 0; i < tamanho; i++){
        vector[i] = vector1[i];
        vector[tamanho +i] = vector2[i];
        vector[2*tamanho + i] = vector3[i];
    }
    return vector;
}

float * abreVetorArquivo(char * linha, int tamanho){
    float * vector = (float*) malloc(tamanho * sizeof(float));
    int i = 0;
    int x = 0;
    int stopFor = 0;
    char valor[8];
    for(int pos = 0; !stopFor; pos++){
        if(linha[pos] == ' '){
            vector[x] = atof(valor);
            i = 0;
            x++;
        }
        else if(linha[pos] == '\0' || linha[pos] == '\n'){
            vector[x] = atof(valor);
            stopFor = 1;
        }
        else{
            valor[i] = linha[pos];
            valor[i+1] = '\0';
            i++;
        }
    }
    return vector;
}

void treinaX(int ** imagem){
    int ** filtro1 = instaciaMatrizCSV(FILTRO_1_PATH, TAMANHO_FILTRO);
    int ** filtro2 = instaciaMatrizCSV(FILTRO_2_PATH, TAMANHO_FILTRO);
    int ** filtro3 = instaciaMatrizCSV(FILTRO_3_PATH, TAMANHO_FILTRO);

    float * vector1 = propagacaoDireta(imagem, filtro1);
    float * vector2 = propagacaoDireta(imagem, filtro2);
    float * vector3 = propagacaoDireta(imagem, filtro3);
    float * vector = juntaTresFiltros(vector1, vector2, vector3, 4);

    imprimeVetorFloat(vector, 12);

    free(vector1);
    free(vector2);
    free(vector3);
    free(vector);
    destroiMatriz(filtro1, TAMANHO_FILTRO);
    destroiMatriz(filtro2, TAMANHO_FILTRO);
    destroiMatriz(filtro3, TAMANHO_FILTRO);
}

void treinaO(int ** imagem){
    int ** filtro1 = instaciaMatrizCSV(FILTRO_4_PATH, TAMANHO_FILTRO);
    int ** filtro2 = instaciaMatrizCSV(FILTRO_5_PATH, TAMANHO_FILTRO);
    int ** filtro3 = instaciaMatrizCSV(FILTRO_6_PATH, TAMANHO_FILTRO);

    float * vector1 = propagacaoDireta(imagem, filtro1);
    float * vector2 = propagacaoDireta(imagem, filtro2);
    float * vector3 = propagacaoDireta(imagem, filtro3);
    float * vector = juntaTresFiltros(vector1, vector2, vector3, 4);

    imprimeVetorFloat(vector, 12);

    free(vector1);
    free(vector2);
    free(vector3);
    free(vector);
    destroiMatriz(filtro1, TAMANHO_FILTRO);
    destroiMatriz(filtro2, TAMANHO_FILTRO);
    destroiMatriz(filtro3, TAMANHO_FILTRO);
}

void classificaImagem(int ** imagem){
    int ** filtro1 = instaciaMatrizCSV(FILTRO_1_PATH, TAMANHO_FILTRO);
    int ** filtro2 = instaciaMatrizCSV(FILTRO_2_PATH, TAMANHO_FILTRO);
    int ** filtro3 = instaciaMatrizCSV(FILTRO_3_PATH, TAMANHO_FILTRO);

    float * vector1 = propagacaoDireta(imagem, filtro1);
    float * vector2 = propagacaoDireta(imagem, filtro2);
    float * vector3 = propagacaoDireta(imagem, filtro3);
    float * vector = juntaTresFiltros(vector1, vector2, vector3, 4);
    //imprimeVetorFloat(vector,12);
    //printf("\n");

    destroiMatriz(filtro1, TAMANHO_FILTRO);
    destroiMatriz(filtro2, TAMANHO_FILTRO);
    destroiMatriz(filtro3, TAMANHO_FILTRO);

    free(vector1);
    free(vector2);
    free(vector3);

    FILE * vetorArquivoX = fopen(TRAIN_X_PATH, "r");
    if(vetorArquivoX == NULL){
        exit(-1);
    }

    float somaSemelhanca = 0;
    int cont = 0;

    char linha[1024];
    while(!feof(vetorArquivoX)){
        fgets(linha, 1024, vetorArquivoX);
        float * vectorX = abreVetorArquivo(linha, 12);
        //imprimeVetorFloat(vectorX, 12);

        somaSemelhanca += verificaSemelhanca(vectorX, vector,12);
        //printf("ACUMULADO: %.2f\n", somaSemelhanca);
        cont++;
        free(vectorX);
    }

    float semelhancaX = somaSemelhanca/cont;
    printf("\tX: %.2f\n", semelhancaX);

    free(vector);
    somaSemelhanca = 0;
    cont = 0;

    int ** filtro4 = instaciaMatrizCSV(FILTRO_4_PATH, TAMANHO_FILTRO);
    int ** filtro5 = instaciaMatrizCSV(FILTRO_5_PATH, TAMANHO_FILTRO);
    int ** filtro6 = instaciaMatrizCSV(FILTRO_6_PATH, TAMANHO_FILTRO);

    vector1 = propagacaoDireta(imagem, filtro4);
    vector2 = propagacaoDireta(imagem, filtro5);
    vector3 = propagacaoDireta(imagem, filtro6);
    vector = juntaTresFiltros(vector1, vector2, vector3, 4);
    //imprimeVetorFloat(vector,12);
    //printf("\n");

    destroiMatriz(filtro4, TAMANHO_FILTRO);
    destroiMatriz(filtro5, TAMANHO_FILTRO);
    destroiMatriz(filtro6, TAMANHO_FILTRO);

    free(vector1);
    free(vector2);
    free(vector3);

    FILE * vetorArquivoO = fopen(TRAIN_O_PATH, "r");
    if(vetorArquivoO == NULL){
        exit(-1);
    }

    while(!feof(vetorArquivoO)){
        fgets(linha, 1024, vetorArquivoO);
        float * vectorO = abreVetorArquivo(linha, 12);
        //imprimeVetorFloat(vectorO, 12);
        somaSemelhanca += verificaSemelhanca(vectorO, vector,12);
        cont++;
        free(vectorO);
    }

    float semelhancaO = somaSemelhanca/cont;
    printf("\tO: %.2f\n", semelhancaO);

    if(semelhancaX > semelhancaO){
        printf("\tA imagem de entrada é um X\n\n");
    }
    else if(semelhancaX < semelhancaO){
        printf("\tA imagem de entrada é um O\n\n");
    }
    else{
        printf("\tA imagem de entrada é um XO\n\n");
    }

    fclose(vetorArquivoX);
    fclose(vetorArquivoO);

}