#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    int *vetor = (int*) malloc(10*sizeof(int));
    if(vetor == NULL){
        printf("Erro!");
        exit(1);
    }
    for(i = 0; i < 10; i++){
        vetor[i] = i;
    }
    for(i = 0; i < 10; i++){
        printf("%d\n", vetor[i]);
    }

    free(vetor);
}
