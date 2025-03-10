#ifndef TIPOS_H
#define TIPOS_H
#define TOTAL 100
typedef struct // a estrutura mais importante do código!
{
    int matricula;
    char nome[TOTAL];
    int idade;
} Aluno;

typedef struct Raiz Raiz;

struct Raiz
{
    Aluno aluno;
    Raiz *prox;
};

typedef struct
{
    Raiz *inicio;
    Raiz *fim;
    int total;
} Lista;

// Declare your types and function prototypes here
void lista_alunos(Lista *lista);
void consultar_aluno(Lista *lista);
Lista*adicionar_aluno(Lista **lista);
Lista*remover_aluno(Lista **lista);
void qntd_alunos(Lista *lista);
void liberarListas(Lista **lista);
#endif // TIPOS_H