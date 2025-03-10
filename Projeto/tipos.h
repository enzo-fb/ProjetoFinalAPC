#ifndef TIPOS_H
#define TIPOS_H
#define TOTAL 100
typedef struct // a estrutura mais importante do código!
{
    int matricula;
    char nome[TOTAL];
    int idade;
} Aluno;

typedef struct
{
    Aluno aluno;
    struct raiz *prox;
} Raiz;

typedef struct
{
    Raiz *inicio;
    Raiz *fim;
} Lista;

// Declare your types and function prototypes here
void lista_alunos(Aluno alunos[TOTAL], int total);
void consultar_aluno(Aluno alunos[TOTAL], int total);
void adicionar_aluno(Aluno alunos[TOTAL], int *total);
void remover_aluno(Aluno alunos[TOTAL], int *total);
void qntd_alunos(int total);
#endif // TIPOS_H