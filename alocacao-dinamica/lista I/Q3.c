#include <stdio.h>
#include <stdlib.h>

int main(void){
    int quant_frutas, linha;
    printf("Digite a quantidade de frutas: ");
    scanf("%d", &quant_frutas);
    char ** frutas = (char**) malloc(quant_frutas*sizeof(char*));
    if(frutas == NULL){
        printf("Erro!");
        exit(1);
    }

    for(linha = 0; linha < quant_frutas; linha++){
        frutas[linha] = (char*) malloc(50*sizeof(char));
    }

    float * valor = (float*) malloc(quant_frutas*sizeof(float));
    if(valor == NULL){
        printf("Erro!");
        exit(1);
    }

    printf("Informe as frutas e os seus valores: \n");
    for(linha = 0; linha < quant_frutas; linha++){
        scanf(" %[^\n]s ", frutas[linha]);
        scanf(" %f", &valor[linha]);
    }

    for(linha = 0; linha < quant_frutas; linha++){
        free(frutas[linha]);
    }
    
    free(frutas);

    return 0;
}
