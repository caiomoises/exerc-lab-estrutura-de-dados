#include <stdio.h>
#include <stdlib.h>

typedef enum meses{
    mesZero,
    janeiro,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
}Meses;

typedef struct data{
    int dia;
    Meses mes;
    int ano;
}Data;

int main(void){
    Data data;

    printf("Informe o dia: ");
    scanf("%d", &data.dia);
    printf("Informe o mes: ");
    scanf("%d", (int)&data.mes);
    printf("Informe o ano: ");
    scanf("%d", &data.ano);

    printf("\n");

    switch (data.mes)
    {
    case 1:
        printf("%d/Jan/%d", data.dia, data.ano);
        break;
    case 2:
        printf("%d/Fev/%d", data.dia, data.ano);
        break;
    case 3:
        printf("%d/Mar/%d", data.dia, data.ano);
        break;
    case 4:
        printf("%d/Abr/%d", data.dia, data.ano);
        break;
    case 5:
        printf("%d/Maio/%d", data.dia, data.ano);
        break;
    case 6:
        printf("%d/Jun/%d", data.dia, data.ano);
        break;
    case 7:
        printf("%d/Jul/%d", data.dia, data.ano);
        break;
    case 8:
        printf("%d/Ago/%d", data.dia, data.ano);
        break;
    case 9:
        printf("%d/Set/%d", data.dia, data.ano);
        break;
    case 10:
        printf("%d/Out/%d", data.dia, data.ano);
        break;
    case 11:
        printf("%d/Nov/%d", data.dia, data.ano);
        break;
    case 12:
        printf("%d/Dez/%d", data.dia, data.ano);
        break;
    
    default:
        break;
    }

    return 0;
}
