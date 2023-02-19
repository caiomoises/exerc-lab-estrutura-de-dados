#include <stdio.h>
#include <stdlib.h>

int main(void){
    int qtd_frutas, linha;
    float soma=0;
    printf("Digite a quantidade de frutas: ");
    scanf("%d", &qtd_frutas);
    char ** frutas = (char**) malloc(qtd_frutas*sizeof(char*));
    if(frutas == NULL){
        printf("Erro!");
        exit(1);
    }

    for(linha = 0; linha < qtd_frutas; linha++){
        frutas[linha] = (char*) malloc(50*sizeof(char));
    }

    float * valor = (float*) malloc(qtd_frutas*sizeof(float));
    if(valor == NULL){
        printf("Erro!");
        exit(1);
    }

    printf("Informe as frutas e os seus valores: \n");
    for(linha = 0; linha < qtd_frutas; linha++){
        printf("Nome da fruta: ");
        scanf(" %[^\n]s ", frutas[linha]);
        printf("Valor: ");
        scanf(" %f", &valor[linha]);
        soma += valor[linha];
    }

    for(linha = 0; linha < qtd_frutas; linha++){
        frutas[linha] = (char*) realloc(frutas[linha],50*sizeof(char));
    }

    printf("\nSeu pedido:");
    for(linha = 0; linha < qtd_frutas; linha++){
        printf("\n%s - R$%.2f", frutas[linha], valor[linha]);
    }
    
    printf("\nValor final: R$%.2f", soma);

    for(linha = 0; linha < qtd_frutas; linha++){
        free(frutas[linha]);
    }
    
    free(frutas);
    free(valor);

    return 0;
}
