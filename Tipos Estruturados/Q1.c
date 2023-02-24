#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definição das variaveis globais:
 * MAX_VAGAS indica o número maximo de vagas por turma.
 * MAX_TURMAS indica o número maximo de turmas que podem ser criadas.
*/
#define MAX_VAGAS 3
#define MAX_TURMAS 2

/**
 * O tipo 'struct aluno' foi criado para agrupar tipos diversos de variaveis relacionadas a alunos.
 * O tipo 'struct turma' foi criado para agrupar variaveis relacionado as turmas, como id, vagas e os dados dos alunos.
 * typedef é a função utilizada para renomear a struct, aqui foi renomeada para Aluno. 
*/
typedef struct aluno{
    int mat;
    char nome[100];
    float notas[3];
    float media;
}Aluno;

typedef struct turma{
    char id;  
    int vagas; 
    Aluno * alunos[MAX_VAGAS];
}Turma;

/**
 * A função do tipo Turma com retorno, foi implementada para alocar e receber as as 
 * informações da turma, indicando se há alunos matriculados; 
 * @param id
*/
Turma *cria_turma(char id){
    Turma *turma = malloc(sizeof(Turma)); 
    turma->vagas = MAX_VAGAS;
    turma->id = id;
    for (int i = 0; i < MAX_VAGAS; i++){
        turma->alunos[i] = NULL; 
    }
    return turma;
}

/**
 * A função do tipo void, sem retorno, criada para imprimir o Id das turmas existentes e
 * a quantidade de vagas que ainda existem;
 * @param turmas
 * @param n 
*/
void imprime_turmas(Turma **turmas, int n){ //O parametro turmas esta alocado dinamicamente dentro da função principal.
    for (int i = 0; i < n; i++){
        Turma *turma = turmas[i];
        printf("Turma %c - Vagas disponiveis: %d\n", turma->id, turma->vagas);
    }
}

/**
 * A função do tipo Turma, criada para buscar uma turma atraves do seu id
 * caso a turma exista, ela retornara o index referente a essa turma.
 * @param turma
 * @param n
 * @param id
*/
Turma *procura_turma(Turma **turma, int n, char id){
    int i = 0, indice = -1;
    for (i = 0; i < n; i++){
        if (turma[i]->id == id){
            indice = i;
        }
    }
    if (indice == -1){
        return NULL;
    } else{
        return turma[indice];
    }
}

/**
 * A função 'matricula_aluno', do tipo void, criada para fazer a matricula de novos alunos
 * possui um limite de alunos que podem ser cadastrados, definido como MAX_VAGAS.
 * A cada aluno que é cadastrado, o valor das vagas é decrementado em 1.
 * @param turma
 * @param mat
 * @param nome
*/
void matricula_aluno(Turma *turma, int mat, char *nome){
    if (turma->vagas == 0){
        printf("Nao ha vagas disponiveis na turma %c.\n", turma->id);
        return;
    }

    Aluno *novo_aluno = malloc(sizeof(Aluno)); 
    novo_aluno->mat = mat;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->notas[0] = 0;
    novo_aluno->notas[1] = 0;
    novo_aluno->notas[2] = 0;
    novo_aluno->media = 0;
    
    for (int i = 0; i < MAX_VAGAS; i++){
        if (turma->alunos[i] == NULL){
            turma->alunos[i] = novo_aluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!");
            return;
        }
    }
}

/**
 * A função do tipo void, foi criada para que o usuario possa lançar as notas dos alunos, 
 * em suas respectivas turmas. Após as notas serem lançadas é feito a madia aritmética.
 * @param turma
*/
void lanca_notas(Turma *turma){
    int s;
    float soma = 0.0;
    printf("Lancamento de notas para a turma %c:\n", turma->id);
    for (int j = 0; j < MAX_VAGAS; j++){
        if (turma->alunos[j] != NULL){
            printf("Matricula: %d \nAluno: %s\n", turma->alunos[j]->mat, turma->alunos[j]->nome);//Dados do aluno ao qual sera atribuida a nota
            for (s = 0; s < 3; s++){
                printf("Digite a nota %d: ", s + 1);
                scanf("%f", &turma->alunos[j]->notas[s]); //Recebendo as notas
            }
            for (s = 0; s < 3; s++){
                soma += turma->alunos[j]->notas[s];//Soma das notas
            }
            turma->alunos[j]->media = soma / 3;//Media aritmetrica
        }
    }
    printf("Notas lancadas com sucesso!\n");
}

/**
 * imprime os dados dos alunos cadastrados em suas respectivas turmas,
 * demonstrando suas notas e media final. 
 * @param turma
*/
void imprime_alunos(Turma *turma){
    printf("Alunos da turma %c:\n\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++){
        Aluno * aluno = turma->alunos[i];
        if (aluno != NULL){
            printf("Matricula: %d\n", aluno->mat);
            printf("Nome: %s\n", aluno->nome);
            printf("Notas: %.1f, %.1f, %.1f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
            printf("Media: %.1f\n\n", aluno->media);
        }
    }
}

int main(void){
    
    char id, nome[100];
    Turma **turma = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));
    if (turma == NULL){
        printf("ERRO");
        exit(1);
    }
    Turma *minhaTurma;
    int op = 0, n = 0, matricula = 0;
    
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as \nfuncionalidades de matricula, lancamento de notas e listagem de \nalunos.");
    printf("\nAutor: Caio Moises Vieira Cavalcante\tVersao: 1.0.5");
    while (op != 6){ //Caso a opção 6 seja escolhida, saira do laço de repetição. 
        printf("\n\n\tMenu:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("Criando nova turma...");
                printf("\nDigite um id: ");
                scanf(" %c", &id);
                if (n == MAX_TURMAS){ // caso o numero maxima de turma seja cadastrado.
                    printf("numero maximo atingido");
                } else if (procura_turma(turma, n, id) != NULL){ //caso a turma ja esteja cadastrada
                    printf("A turma Ja existe!");
                } else{
                    turma[n] = (Turma *)malloc(sizeof(Turma));
                    turma[n] = cria_turma(id); //chamada da função para criar uma nova turma 
                    n++; //encremento para saber que mais uma turma foi criada
                    printf("Turma %c criada com sucesso!", id);
                }
                break;
            case 2:
                imprime_turmas(turma, n);
                break;
            case 3:
                printf("Matriculando aluno...");
                printf("\nDigite o id da turma: ");
                scanf(" %c", &id);
                minhaTurma = procura_turma(turma, n, id);
                if (minhaTurma != NULL){
                    printf("Digite a matricula: ");
                    scanf("%d", &matricula);
                    printf("Digite o nome: ");
                    scanf(" %[^\n]s", (char *)&nome);
                    matricula_aluno(minhaTurma, matricula, nome);
                } else{
                    printf("Turma inexistente!");
                }
                break;
            case 4:
                printf("Lancando notas...");
                printf("\nDigite o id da turma: ");
                scanf(" %c", &id);
                minhaTurma = procura_turma(turma, n, id);
                if (minhaTurma != NULL){
                    lanca_notas(minhaTurma);
                } else{
                    printf("Turma inexistente!");
                }
                break;
            case 5:
                printf("Listando alunos...");
                printf("\nDigite o id da turma: ");
                scanf(" %c", &id);
                minhaTurma = procura_turma(turma, n, id);
                if (minhaTurma != NULL){
                    imprime_alunos(minhaTurma);
                } else{
                    printf("Turma inexistente!");
                }
                break;
            case 6:
                printf("Obrigado por usar meu programa!");
                break;
            default:
                printf("opcao invalida!");
                break;
            }
        }
    for (int i = 0; i < n; i++){ //Liberando o espaco de memoria da matriz turma 
        free(turma[i]);
    }
    free(turma);//liberando o espaco de memoria que foi alocado para turma 
    return 0;
}
