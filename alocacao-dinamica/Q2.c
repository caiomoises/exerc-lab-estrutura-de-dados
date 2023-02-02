#include <stdio.h>
#include <stdlib.h>

//Função para criar uma matriz float:
int ** CriaMatrizInt(int linhas, int colunas){

    int ** matriz = (int**) malloc(linhas*sizeof(int*));
    if(matriz == NULL){
        printf("Erro!");
        exit(1);
    }
    int linha;
    for(linha = 0; linha<linhas; linha++){
        matriz[linha] = (int*) malloc(colunas*sizeof(int));
    }
    return matriz;
}

int main(void){
    //Alocando uma matriz de tamanho 3x3
    int linhas = 3;
    int colunas = 3;
    int ** matriz = CriaMatrizInt(linhas, colunas);
    
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            matriz[i][j] = i*3 + j;
        }
    }

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%i ", matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
