#include <stdio.h>
#include <stdlib.h>

int main(void){
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;
    printf("Valor de X: %i \nValor de Y: %i \nValor de *p: %p", x, y, p);
    return 0;
}
