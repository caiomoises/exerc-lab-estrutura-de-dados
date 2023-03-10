#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    int idade;
    int CPF;
}Pessoa;

void preenche(Pessoa ** pessoa, int n){
    printf("\t\tCADASTRO DE PESSOAS: ");
    for(int i = 0; i < n; i++) {
        printf("\n\tDados pessoais: N - %d\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]s", pessoa[i]->nome);

        printf("Idade: ");
        scanf("%d", &pessoa[i]->idade);
        
        printf("Documento: ");
        scanf("%d", &pessoa[i]->CPF);
    }
}

void imprime(Pessoa ** pessoa, int n){
    printf("\n\n\t\tPESSOAS CADASTRADAS: ");
    for(int i = 0; i < n; i++) {
        printf("\nNome da pessoa: %s\n", pessoa[i]->nome);

        printf("Numero do documento da pessoa: %d\n", pessoa[i]->CPF);

        printf("Idade da pessoa: %d\n", pessoa[i]->idade);
    }

}

void altera_idade(Pessoa ** pessoa, int n){
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Infome a nova idade para a pessoa %d: ", i+1);
        scanf("%d", &pessoa[i]->idade);
    }
}

void maior_menor(Pessoa ** pessoa, int n){
    int i, maior = 0, menor = 0;
    for (i = 0; i < n; i++) {
        if (pessoa[i]->idade > pessoa[maior]->idade){
            maior = i;
        }
        if (pessoa[i]->idade < pessoa[menor]->idade){
            menor = i;
        }
    }
    printf("\nMaior idade: %d", pessoa[maior]->idade);
    printf("\nMenor idade: %d", pessoa[menor]->idade);
} 

int main(void){
    int n;
    printf("Quantidade de pessoas: ");
    scanf("%d", &n);
    Pessoa ** pessoa = (Pessoa**) malloc(n * sizeof(Pessoa*));

    if(pessoa == NULL) {
        exit(1);
    }

    for(int i = 0; i< n; i++){
        pessoa[i] = (Pessoa*) malloc(n * sizeof(Pessoa));
    }

    preenche(pessoa, n);
    imprime(pessoa, n);
    altera_idade(pessoa, n);
    maior_menor(pessoa, n);

    for(int i = 0; i< n; i++){

        free(pessoa[i]);
        
    }

    free(pessoa);

    return 0;
}
