#include <stdio.h>

int main(void){
    int x, *p;
    x = 100;
    p = x;
    //*p = &p;
    printf("Valor de p: %d \nValor de *p: %p", p, p);
    return 0;
}

/*a) Esta mensagem é de erro ou advertência? nada sera exibido;
b) Por que o compilador emite tal mensagem? por causa do codigo de formatação, %p seria para *p e %d seria para p;
c) Compile e execute o programa. A execução foi bem sucedida? Sim, porém nada foi exibido;
d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida 
pelo compilador.
e) Compile e execute novamente o programa. A execução foi bem sucedida? Sim*/
