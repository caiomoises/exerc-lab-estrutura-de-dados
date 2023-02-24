#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, tamanho = 10;
    int *vetor = (int*) malloc(tamanho*sizeof(int));
    if(vetor == NULL){
        printf("Erro!");
        exit(1);
    }
    for(i = 0; i < tamanho; i++){
        vetor[i] = i;
    }
    for(i = 0; i < tamanho; i++){
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}
