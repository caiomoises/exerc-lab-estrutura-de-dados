#include <stdio.h>

typedef union tipo{
    char ALIMENTO[20];
    char BEBIDA[20];
    char ELETRONICO[20];
}Tipo;

typedef struct produto{
    char nome[50];
    float valor;
    Tipo tipo;
}Produto;

int main(void){
    Produto produto;

    printf("Nome do produto: ");
    scanf(" %[^\n]", produto.nome);

    printf("Valor: ");
    scanf(" %f", &produto.valor);

    printf("Tipo: \n- Alimento \n- Bebida \n- Eletronico\n");
    scanf(" %[^\n]", produto.tipo.ALIMENTO);

    printf("\t---DADOS DO PRODUTO---\n");
    printf("\nNome do produto: %s", produto.nome);
    printf("\nValor do produto: %.2f", produto.valor);
    printf("\nTipo do produto: %s", produto.tipo.ALIMENTO);

    return 0;
}
