#include <stdio.h>
#include <stdlib.h>

int main(void){

    int i, quant, Sfeminino = 0, Smasculino = 0;

    printf("Numero de pessoas que serao entrevistadas: \n");
    scanf("%d", &quant);

    char * sexo = (char *) malloc(quant * sizeof(char)); 
    int * opn = (int *) malloc(quant * sizeof(int));

    printf("\t----QUESTIONARIO----:\n");

    for (i = 0; i < quant; i++){
        printf("Sexo:\nDigite F para feminino;\nDigite M para masculino.");
        scanf(" %c", &sexo[i]);
        printf("Opniao:\n1. nao gostou;\n2. gostou.\n");
        scanf("%d", &opn[i]);
    }

    for (i = 0; i < quant; i++){
        if ((sexo[i] == 'F') && (opn[i] == 2)){
            Sfeminino++;
        }

        if ((sexo[i] == 'M') && (opn[i] == 1)){
            Smasculino++;
        }
    }

    Sfeminino = (Sfeminino * 100.0f) / quant; 
    Smasculino = (Smasculino * 100.0f) / quant; 

    printf("\n%d %% das mulheres gostaram do produto; \n%d %% dos homens nao gostaram do produto.", Sfeminino, Smasculino);
 
    free(sexo);
    free(opn);

    return 0;
}
