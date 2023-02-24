#include <stdio.h>
#include <stdlib.h>

int main(void){
    int m, n, i, j, cont = 0;
    
    do{
    printf("Quantidade de linhas: ");
    scanf("%d", &m);
    printf("Quantidade de colunas: ");
    scanf("%d", &n);
    }while(m < 1 || m > 1000 || n < 1 || n > 1000);

    char ** mapa = (char**) malloc(m*sizeof(char*));
    if(mapa == NULL){
        exit(1);
    }

    for(i = 0; i < m; i++){
        mapa[i] = malloc(n*sizeof(char*));
    }
    printf("Informe os caracteres: \n");
    for(i = 0; i < m; i++){    
            scanf(" %[^\n]s", mapa[i]);
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
           if(i == 0){
            if ((mapa[i][j] == '#' && mapa[i][j + 1] == '.') || (mapa[i][j] == '#' && mapa[i][j - 1] == '.'))
                {
                    cont++;
                }
                else if ((mapa[i][j] == '#' && mapa[i + 1][j] == '.'))
                {
                    cont++;
                }
            } 
            else if (i > 0 && i < m - 1)
            {
                if ((mapa[i][j] == '#' && mapa[i][j + 1] == '.') || (mapa[i][j] == '#' && mapa[i][j - 1] == '.'))
                {
                    cont++;
                }
                else if ((mapa[i][j] == '#' && mapa[i + 1][j] == '.') || (mapa[i][j] == '#' && mapa[i - 1][j] == '.'))
                {
                    cont++;
                }
            }
            else if (i == m - 1)
            {
                if ((mapa[i][j] == '#' && mapa[i][j + 1] == '.') || (mapa[i][j] == '#' && mapa[i][j - 1] == '.'))
                {
                    cont++;
                }
                else if ((mapa[i][j] == '#' && mapa[i - 1][j] == '.'))
                {
                    cont++;
                }
            }
        }
    }

    printf("%d", cont);

    for(i = 0; i < m; i++){
        free(mapa[i]);
    }    

    free(mapa); 

    return 0;
}
