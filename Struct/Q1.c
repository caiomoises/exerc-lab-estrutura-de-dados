#include <stdio.h>
#include <stdlib.h>

typedef struct funcionarios {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;

void preenche(Funcionario ** funcionario, int n){
    for(int i = 0; i < n; i++) {

        printf("\n\tFuncionario %d\n", i+1);
        
        printf("Nome: ");
        scanf(" %[^\n]s", funcionario[i]->nome);

        printf("Salario: R$");
        scanf("%f", &funcionario[i]->salario);

        printf("Identificador: ");
        scanf("%d", &funcionario[i]->identificador);

        printf("Cargo: ");
        scanf(" %[^\n]s", funcionario[i]->cargo);
    }
}

void imprime(Funcionario ** funcionario, int n){
    printf("\n\t\tFUNCIONARIOS CADASTRADOS:\n");
    for(int i = 0; i < n; i++) {
        printf("\n\tFuncionario %d\n", i+1);
        printf("Nome: %s\n", funcionario[i]->nome);
        printf("Salario: R$%.2f\n", funcionario[i]->salario);
        printf("Identificador: %d\n", funcionario[i]->identificador);
        printf("Cargo: %s\n", funcionario[i]->cargo);
    }

}

void altera_salario(Funcionario ** funcionario, int n){
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Novo valor do salario para o funcionario %d: R$", i+1);
        scanf("%f", &funcionario[i]->salario);
    }
}

void maior_menor(Funcionario ** funcionario, int n){
    int i, maior = 0, menor = 0;
    for (i = 0; i < n; i++) {
        if (funcionario[i]->salario > funcionario[maior]->salario) {
            maior = i;
        }
        if (funcionario[i]->salario < funcionario[menor]->salario) {
            menor = i;
        }
    }
    printf("\nMaior salario: R$%.2f", funcionario[maior]->salario);
    printf("\nMenor salario: R$%.2f", funcionario[menor]->salario);
}   

int main(){
    int n;
    printf("Informe a quantidade de funcionarios: ");
    scanf("%d", &n);
    Funcionario ** funcionario = (Funcionario**) malloc(n * sizeof(Funcionario*));

    if(funcionario == NULL) {
        printf("Erro!");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        funcionario[i] = (Funcionario*) malloc(n * sizeof(Funcionario));
    }

    preenche(funcionario, n);
    imprime(funcionario, n);
    altera_salario(funcionario, n);
    maior_menor(funcionario, n);
    
    for(int i = 0; i < n; i++){
        free(funcionario[i]);
    }  

    free(funcionario);

    return 0;
}
