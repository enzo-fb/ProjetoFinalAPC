#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "menus.c"
#include "tipos.h"

void consultar_aluno(Lista *lista);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opcao;
    // essas variáveis, com exceção de "opcao", serão utilizadas como parâmetros nas funções.
    // a struct "aluno" inicializada, é através dela que os dados serão registrados.
    Lista *lista_formados = NULL;   // inicializa a lista como nula
    Lista *lista_graduandos = NULL; // inicializa a lista como nula
    // Aluno alunos[TOTAL];
    int escolha;
    do
    {
        menuPrincipal();

        scanf("%d", &opcao);
        getchar(); // evita aparecer erros e garante a leitura correta das variáveis, funciona como fflush, para limpar o buffer.

        switch (opcao)
        {
        case 1:
            system("clear");
            do
            {
                menuCaso1();

                scanf("%d", &opcao);
                getchar();

                switch (opcao)
                {
                case 1:
                    lista_alunos(lista_graduandos);
                    consultar_aluno(lista_graduandos);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 2:
                    adicionar_aluno(&lista_graduandos);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 3:
                    lista_alunos(lista_graduandos);
                    remover_aluno(&lista_graduandos);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 4:
                    qntd_alunos(lista_graduandos);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 5:
                    lista_alunos(lista_graduandos);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 6:

                    system("clear");
                    break;
                case 7:
                    printf("Saindo...\n");
                    liberarListas(&lista_formados);
                    liberarListas(&lista_graduandos);
                    break;
                default:
                    system("clear");
                    printf("            Opção inválida!\n");

                    break;
                }
            } while (escolha != 2 && opcao != 6 && opcao != 7);
            break;
        case 2:
            system("clear");
            do
            {

                menuCaso2();
                scanf("%d", &opcao);
                getchar();

                switch (opcao)
                {
                case 1:
                    lista_alunos(lista_formados);
                    consultar_aluno(lista_formados);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 2:
                    adicionar_aluno(&lista_formados); // o símbolo '&' está sendo usado como endereço do ponteiro(*total), que está contido na função depois do "main".
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 3:
                    lista_alunos(lista_formados);
                    remover_aluno(&lista_formados); // chama a função para remover
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 4:
                    qntd_alunos(lista_formados); // chama a função para ver a quantidade de alunos
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 5:
                    lista_alunos(lista_formados);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;

                    
                    
                case 6:
                    system("clear");
                    break;
                case 7:
                    printf("Saindo...\n");            // mensagem de saída
                    liberarListas(&lista_formados);   // libera a lista de formados
                    liberarListas(&lista_graduandos); // libera a lista de graduandos
                    break;
                default:
                    system("clear");
                    printf("Opção inválida!\n");
                    break;
                }
            } while (escolha != 2 && opcao != 6 && opcao != 7);

            break;
        case 3:
            printf("Saindo...\n");
            liberarListas(&lista_formados);
            liberarListas(&lista_graduandos);
            break;
        default:
            printf("            Opção inválida!\n");
            break;
        }

    } while ((opcao != 5) && (opcao != 3)); // código continuará no loop até uma dessas condições ser atendida

    return 0;
}

void consultar_aluno(Lista *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    int matricula;
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);
    getchar();
    if (lista->inicio->aluno.matricula == matricula)
    {
        printAluno(lista->inicio->aluno);
        return;
    }
    else if (lista->fim->aluno.matricula == matricula)
    {
        printAluno(lista->fim->aluno);
        return;
    }
    Raiz *aux = lista->inicio;
    while (aux->prox != NULL)
    {
        if (aux->aluno.matricula == matricula)
        {
            printAluno(aux->aluno);
            return;
        }
        aux = aux->prox;
    }
    printf("Aluno não encontrado\n");
}

Lista *adicionar_aluno(Lista **lista)
{ // a variável *total(ponteiro) é a que está contabilizando os alunos, "TOTAL" é o define usado no começo do código.
  // o ponteiro "total" vai alterar as variáveis dentro da função main.
    if (*lista == NULL)
    {
        *lista = (Lista *)malloc(sizeof(Lista));
        (*lista)->inicio = NULL;
        (*lista)->fim = NULL;
        (*lista)->total = 0;
    }
    Aluno aluno;
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, TOTAL, stdin);              // funciona melhor para leitura de palavras, lendo também os espaços.
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; // Remove a nova linha
    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno.idade);
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &aluno.matricula);
    getchar();
    Raiz *novo = (struct Raiz *)malloc(sizeof(Raiz));
    novo->aluno = aluno;
    novo->prox = NULL;
    if ((*lista)->inicio == NULL)
    {
        (*lista)->inicio = novo;
        (*lista)->fim = novo;
    }
    else
    {
        (*lista)->fim->prox = novo;
        (*lista)->fim = novo;
    }
    system("clear");
    (*lista)->total++;
    printf("Aluno adicionado com sucesso.\n");
    return *lista;
}

Lista *remover_aluno(Lista **lista)
{
    if ((*lista) == NULL)
    {
        printf("Lista vazia\n");
        return NULL;
    }
    int matricula = 0;
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);
    getchar();
    if ((*lista)->inicio->aluno.matricula == matricula)
    {
        Raiz *aux = (*lista)->inicio;
        (*lista)->inicio = (*lista)->inicio->prox;
        free(aux);
        printf("Aluno removido com sucesso\n");
        (*lista)->total--;
        return *lista;
    }
    else if ((*lista)->fim->aluno.matricula == matricula)
    {
        Raiz *aux = (*lista)->inicio;
        while (aux->prox != (*lista)->fim)
        {
            aux = aux->prox;
        }
        free((*lista)->fim);
        (*lista)->fim = aux;
        (*lista)->fim->prox = NULL;
        (*lista)->total--;
        printf("Aluno removido com sucesso\n");
        return *lista;
    }
    Raiz *aux = (*lista)->inicio;
    while (aux->prox != NULL)
    {
        if (aux->aluno.matricula == matricula)
        {
            Raiz *aux2 = aux->prox;
            aux->prox = aux->prox->prox;
            free(aux2);
            printf("Aluno removido com sucesso\n");
            (*lista)->total--;
            return *lista;
        }
        aux = aux->prox;
    }
    printf("Aluno não encontrado\n");
    return *lista;
}

void qntd_alunos(Lista *lista)
{
    if (lista == NULL)
    {
        return;
    }
    
    system("clear");
    printf("Quantidade de alunos cadastrados: %d\n", lista->total);
}

void lista_alunos(Lista *lista)
{
    if (lista == NULL)
    {
        return;
    }
    Raiz *aux = lista->inicio;
    while (aux != NULL)
    {
        printAluno(aux->aluno);
        aux = aux->prox;
    }
    printf("\n");
}

void liberarListas(Lista **lista)
{
    if (*lista == NULL)
    {
        return;
    }
    Raiz *aux = (*lista)->inicio;
    while (aux != NULL)
    {
        Raiz *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*lista);
    *lista = NULL;
}