#include <stdio.h>

int main(void) {
    int a, b, c, d, *p1, *p2 = &a, *p3 = &c;
    
    p1 = p2;
    *p2 = 10;
    b = 20;
    int **pp;
    pp = &p1;
    *p3 = **pp;
    int *p4 = &d;
    *p4 = b + (*p1)++;

    printf("%d\t%d\t%d\t%d\n", a, b, c, d);
    
    return 0;
}
