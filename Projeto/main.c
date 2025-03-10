#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "menus.c"

#define TOTAL 100

typedef struct // a estrutura mais importante do código!
{
    int matricula;
    char nome[TOTAL];
    int idade;
} Aluno;
// a estrutura mais importante do código!
// funções a serem utilizadas
// usei "void" porque não retorna valor
void lista_alunos(Aluno alunos[TOTAL], int total);
void consultar_aluno(Aluno alunos[TOTAL], int total);
void adicionar_aluno(Aluno alunos[TOTAL], int *total);
void remover_aluno(Aluno alunos[TOTAL], int *total);
void qntd_alunos(int total);

// função principal

int main()
{
    setlocale(LC_ALL, "");

    int opcao;
    // essas variáveis, com exceção de "opcao", serão utilizadas como parâmetros nas funções.
    // a struct "aluno" inicializada, é através dela que os dados serão registrados.
    Aluno alunos[TOTAL];
    int totalGraduando = 0, totalFormado = 0; // variáveis inicializadas;
    char resposta;                            // variável para usada para definir a continuidade do usuário no programa.
    int escolha;
    do
    {
        menupricnipal();

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
                    lista_alunos(alunos, totalGraduando);
                    consultar_aluno(alunos, totalGraduando);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 2:
                    adicionar_aluno(alunos, &totalGraduando);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 3:
                    lista_alunos(alunos, totalGraduando);
                    remover_aluno(alunos, &totalGraduando);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 4:
                    qntd_alunos(totalGraduando);
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 5:
                    printf("Saindo...\n");
                    break;
                case 6:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf("            Opção inválida!\n");

                    break;
                }
            } while (escolha != 2 && opcao != 5 && opcao != 6);
            break;
        case 2:
            system("clear");
            do
            {

                menuCaso2();
                scanf("%d", &opcao);
                fflush(stdin);

                switch (opcao)
                {
                case 1:
                    lista_alunos(alunos, totalFormado);
                    consultar_aluno(alunos, totalFormado); // chama a função para consultar
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 2:
                    adicionar_aluno(alunos, &totalFormado); // o símbolo '&' está sendo usado como endereço do ponteiro(*total), que está contido na função depois do "main".
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 3:
                    lista_alunos(alunos, totalFormado);
                    remover_aluno(alunos, &totalFormado); // chama a função para remover
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 4:
                    qntd_alunos(totalFormado); // chama a função para ver a quantidade de alunos
                    desejaVoltarAoMenu();
                    scanf("%d", &escolha);
                    system("clear");
                    break;
                case 5:
                    printf("Saindo...\n");
                    break;
                case 6:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf("Opção inválida!\n");
                    break;
                }
            } while (escolha != 2 && opcao != 5 && opcao != 6);

            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("            Opção inválida!\n");
            break;
        }

    } while ((opcao != 5) && (opcao != 3)); // código continuará no loop até uma dessas condições ser atendida

    return 0;
}

void consultar_aluno(Aluno alunos[TOTAL], int total)
{
    char nome_aluno[TOTAL];
    int encontrado = 0; // Variável para ser usada como referência, se permanecer em 0, vai constar como "não encontrado".

    printf("Digite o nome do aluno:\n");
    fgets(nome_aluno, TOTAL, stdin);
    nome_aluno[strcspn(nome_aluno, "\n")] = '\0'; // strcspn vai ler a posição que encontra o \n e vai substituí-lo por nulo;
    // isso evita de ficar registrado caracteres indesejados na string.

    for (int i = 0; i < total; i++)
    {
        if (strcmp(alunos[i].nome, nome_aluno) == 0) // estrutura básica de comparação de strings
        {
            system("clear");
            printf("-- Registro do aluno --\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Matrícula: 00%d\n", alunos[i].matricula);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0)
    {
        system("clear");
        printf("Aluno não encontrado.\n");
    }
}

void adicionar_aluno(Aluno alunos[TOTAL], int *total) // a variável *total(ponteiro) é a que está contabilizando os alunos, "TOTAL" é o define usado no começo do código.
// o ponteiro "total" vai alterar as variáveis dentro da função main.
{
    if (*total >= TOTAL) // este "if" vai garantir que não ultrapasse o total estipulado no início do código.
    {
        system("clear");
        printf("Limite de alunos atingido.\n");
        return;
    }

    alunos[*total].matricula = *total + 1;
    printf("Digite o nome do aluno: ");
    fgets(alunos[*total].nome, TOTAL, stdin);                       // funciona melhor para leitura de palavras, lendo também os espaços.
    alunos[*total].nome[strcspn(alunos[*total].nome, "\n")] = '\0'; // Remove a nova linha
    printf("Digite a idade do aluno: ");
    scanf("%d", &alunos[*total].idade);
    getchar();

    (*total)++;      // adiciona mais um "aluno" na contagem total.
    system("clear"); // diminui a poluição visual.
    printf("Aluno adicionado com sucesso.\n");
}

void remover_aluno(Aluno alunos[TOTAL], int *total)
{
    int matricula, encontrado = 0;

    printf("Digite a matrícula do aluno a ser removido: ");
    scanf("%d", &matricula);
    fflush(stdin);

    for (int i = 0; i < *total; i++)
    {
        if (alunos[i].matricula == matricula) // vai fazer uma busca no banco de dados para encontrar a matrícula digitada anteriormente
        {
            for (int j = i; j < *total - 1; j++) // encontrando o aluno no "if", o "for" será executado;
            {
                alunos[j] = alunos[j + 1];
            }
            (*total)--; // retira esse aluno do total contabilizado até o momento.
            encontrado = 1;
            system("clear");
            printf("Aluno removido com sucesso.\n");
            break;
        }
    }

    if (encontrado == 0)
    {
        system("clear");
        printf("Aluno não encontrado.\n");
    }
}

void qntd_alunos(int total)
{

    system("clear");
    printf("Quantidade de alunos cadastrados: %d\n", total);
}

void lista_alunos(Aluno alunos[TOTAL], int total)
{
    system("clear");
    printf("          -- Banco de alunos --\n\n");
    printf("    NOME                    MATRÍCULA \n\n");
    for (int i = 0; i < total; i++)
    {
        printf("  %-20s  --     %03d\n", alunos[i].nome, alunos[i].matricula);
    }
    printf("\n");
}