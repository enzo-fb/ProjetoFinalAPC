#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TOTAL 100

typedef struct // a estrutura mais importante do código!
{
    int matricula;
    char nome[TOTAL];
    int idade;
} Aluno;

// funções a serem utilizadas
// usei "void" porque não retorna valor
void lista_alunos(Aluno alunos[TOTAL], int total);
void consultar_aluno(Aluno alunos[TOTAL], int total);
void adicionar_aluno(Aluno alunos[TOTAL], int *total);
void remover_aluno(Aluno alunos[TOTAL], int *total);
void qntd_alunos(int total);

// fun??o principal

int main()
{
    setlocale(LC_ALL, "");

    int opcao;
    // essas variáveis, com exceção de "opcao", serão utilizadas como parâmetros nas funções.
    // a struct "aluno" inicializada, é através dela que os dados serão registrados.
    Aluno alunos[TOTAL];
    int totalGraduando = 0, totalFormado = 0; // variaveis inicializadas;
    char resposta;                            // variavel para usada para definir a continuidade do usu?rio no programa.
    int escolha;
    do
    {
        printf("\n===========================================================\n");
        printf("       Sistema Eletrônico de Gestão de Alunos - SEGA\n");
        printf("===========================================================\n\n");
        printf("                    - Menu Principal -\n\n\n");
        printf("    1. Alunos (graduando)\n");
        printf("    2. Alunos (formado)\n");
        printf("    3. Sair\n");
        printf("===========================================================\n");

        scanf("%d", &opcao);
        getchar(); // evita aparecer erros e garante a leitura correta das variaveis, funciona como fflush, para limpar o buffer.

        switch (opcao)
        {
        case 1:
            system("cls");
            do
            {

                printf("\n===========================================================\n\n");
                printf("            MENU DE GERENCIAMENTO DE DISCENTES \n\n\n");
                printf("    1. Consultar aluno;\n");
                printf("    2. Adicionar aluno;\n");
                printf("    3. Remover aluno;\n");
                printf("    4. Quantidade de alunos graduando\n");
                printf("    5. Sair;\n");
                printf("    6. Voltar ao menu principal.\n");
                printf("===========================================================\n");

                scanf("%d", &opcao);
                getchar();

                switch (opcao)
                {
                case 1:
                    lista_alunos(alunos, totalGraduando);
                    consultar_aluno(alunos, totalGraduando);
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 2:
                    adicionar_aluno(alunos, &totalGraduando);
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 3:
                    lista_alunos(alunos, totalGraduando);
                    remover_aluno(alunos, &totalGraduando);
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 4:
                    qntd_alunos(totalGraduando);
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 5:
                    printf("Saindo...\n");
                    break;
                case 6:
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("            Opção inválida!\n");

                    break;
                }
            } while (escolha != 2 && opcao != 5 && opcao != 6);
            break;
        case 2:
            system("cls");
            do
            {

                printf("\n===========================================================\n\n");
                printf("           MENU DE GERENCIAMENTO DE ALUNOS FORMADOS\n\n\n");
                printf("    1. Consultar aluno;\n");
                printf("    2. Adicionar aluno;\n");
                printf("    3. Remover aluno;\n");
                printf("    4. Quantidade de alunos formados;\n");
                printf("    5. Sair;\n");
                printf("    6. Voltar ao menu principal.\n");
                printf("\n===========================================================\n");

                scanf("%d", &opcao);
                fflush(stdin);

                switch (opcao)
                {
                case 1:
                    lista_alunos(alunos, totalFormado);
                    consultar_aluno(alunos, totalFormado); // chama a fun??o para consultar
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 2:
                    adicionar_aluno(alunos, &totalFormado); // o simbolo '&' est? sendo usado como endere?o do ponteiro(*total), que est? contido na fun??o depois do "main".
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 3:
                    lista_alunos(alunos, totalFormado);
                    remover_aluno(alunos, &totalFormado); // chama a fun??o para remover
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 4:
                    qntd_alunos(totalFormado); // chama a fun??o para ver a quantidade de alunos
                    printf("\nDeseja voltar ao menu ?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
                    scanf("%d", &escolha);
                    system("cls");
                    break;
                case 5:
                    printf("Saindo...\n");
                    break;
                case 6:
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("Opção inválida!\n");
                    break;
                }
            } while (escolha != 2 && opcao != 5 && opcao != 6);

            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("            Op??o inv?lida!\n");
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
            system("cls");
            printf("-- Registro do aluno --\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Matr?cula: 00%d\n", alunos[i].matricula);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0)
    {
        system("cls");
        printf("Aluno não encontrado.\n");
    }
}

void adicionar_aluno(Aluno alunos[TOTAL], int *total) // a variável *total(ponteiro) é a que está contabilizando os alunos, "TOTAL" é o define usado no começo do código.
// o ponteiro "total" vai alterar as variáveis dentro da função main.
{
    if (*total >= TOTAL) // este "if" vai garantir que não ultrapasse o total estipulado no início do código.
    {
        system("cls");
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

    (*total)++;    // adiciona mais um "aluno" na contagem total.
    system("cls"); // diminui a poluição visual.
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
            system("cls");
            printf("Aluno removido com sucesso.\n");
            break;
        }
    }

    if (encontrado == 0)
    {
        system("cls");
        printf("Aluno n?o encontrado.\n");
    }
}

void qntd_alunos(int total)
{

    system("cls");
    printf("Quantidade de alunos cadastrados: %d\n", total);
}

void lista_alunos(Aluno alunos[TOTAL], int total)
{
    system("cls");
    printf("          -- Banco de alunos --\n\n");
    printf("    NOME                    MATRÍCULA \n\n");
    for (int i = 0; i < total; i++)
    {
        printf("  %-20s  --     %03d\n", alunos[i].nome, alunos[i].matricula);
    }
    printf("\n");
}