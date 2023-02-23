#include <stdio.h>
#include <stdlib.h>

typedef enum genero{
    masculino,
    feminino
}Genero;

typedef struct pessoa{
    char nome[50];
    int idade;
    Genero sexo; 
}Pessoa;

int main(void){
    Pessoa inf;
    printf("Informe o nome: ");
    scanf(" %[^\n]", inf.nome);
    printf("Informe sua idade: ");
    scanf("%d", &inf.idade);
    printf("Informe Seus Genero: \n1 - Masculino \n2 - Feminino \n");
    scanf("%d", (int*)&inf.sexo);

    if(inf.sexo == masculino){
        printf("\nNome: %s \nIdade: %d \nGenero: %d", inf.nome, inf.idade, inf.sexo);
    } else if(inf.sexo == feminino){
        printf("\nNome: %s \nIdade: %d \nGenero: %d", inf.nome, inf.idade, inf.sexo);
    } else{
        printf("\nValor invalido!");
    }

    return 0;
}
