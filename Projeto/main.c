#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "menus.c"

#define TOTAL 100

typedef struct // a estrutura mais importante do c?digo!
{
    int matricula;
    char nome[TOTAL];
    int idade;
} Aluno;

// fun??es a ser utilizadas
// usei "void" pq n?o retorna valor
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
    // essas variaveis,com exce??o de "opcao", ser?o utilizadas como parametros nas fun??es.
    //  a struct "aluno" inicializada, ? atrav?s dela que os dados ser?o registrados.
    Aluno alunos[TOTAL];
    int totalGraduando = 0, totalFormado = 0; // variaveis inicializadas;
    char resposta;                            // variavel para usada para definir a continuidade do usu?rio no programa.
    int escolha;
    do
    {
        menupricnipal();

        scanf("%d", &opcao);
        getchar(); // evita aparecer erros e garante a leitura correta das variaveis, funciona como fflush, para limpar o buffer.

        switch (opcao)
        {
        case 1:
            system("cls");
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
                    printf("            Op??o inv?lida!\n");

                    break;
                }
            } while (escolha != 2 && opcao != 5 && opcao != 6);
            break;
        case 2:
            system("cls");
            do
            {

                menuCaso2();
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
                    printf("Op??o inv?lida!\n");
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

    } while ((opcao != 5) && (opcao != 3)); // c?digo continuar? no loop at? uma dessas condi??es ser atendida

    return 0;
}

void consultar_aluno(Aluno alunos[TOTAL], int total)
{
    char nome_aluno[TOTAL];
    int encontrado = 0; // Variavel para ser usado como refer?ncia, se permanecer em 0, vai constar como "n?o encontrado".

    printf("Digite o nome do aluno:\n");
    fgets(nome_aluno, TOTAL, stdin);
    nome_aluno[strcspn(nome_aluno, "\n")] = '\0'; // strcspn vai ler a posi??o que encontra o \n e vai substitui-lo por nulo;
    // isso evita de ficar registrado caracteres indesejados na string.

    for (int i = 0; i < total; i++)
    {
        if (strcmp(alunos[i].nome, nome_aluno) == 0) // estrutura b?sica de compara??o de strings
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
        printf("Aluno n?o encontrado.\n");
    }
}

void adicionar_aluno(Aluno alunos[TOTAL], int *total) // a variavel *total(ponteiro) ? a que est? contabilizando os alunos, "TOTAL" ? o define usado no come?o do c?digo.
// o ponteiro "total" vai alterar as variav?is dentro da fun??o main.
{
    if (*total >= TOTAL) // este "if" vai garantir que n?o ultrapasse o total estipulado no inicio do codigo.
    {
        system("cls");
        printf("Limite de alunos atingido.\n");
        return;
    }

    alunos[*total].matricula = *total + 1;
    printf("Digite o nome do aluno: ");
    fgets(alunos[*total].nome, TOTAL, stdin);                       // funciona melhor para leitura de palavras, lendo tamb?m os espa?os.
    alunos[*total].nome[strcspn(alunos[*total].nome, "\n")] = '\0'; // Remove a nova linha
    printf("Digite a idade do aluno: ");
    scanf("%d", &alunos[*total].idade);
    getchar();

    (*total)++;    // adiciona mais um "aluno" na contagem total.
    system("cls"); // diminui a polui??o visual.
    printf("Aluno adicionado com sucesso.\n");
}

void remover_aluno(Aluno alunos[TOTAL], int *total)
{
    int matricula, encontrado = 0;

    printf("Digite a matr?cula do aluno a ser removido: ");
    scanf("%d", &matricula);
    fflush(stdin);

    for (int i = 0; i < *total; i++)
    {
        if (alunos[i].matricula == matricula) // vai fazer uma busca no banco de dados para encontrar a matricula digitada anteriormente
        {
            for (int j = i; j < *total - 1; j++) // encontrando o aluno no "if", o "for" ser? executado;
            {
                alunos[j] = alunos[j + 1];
            }
            (*total)--; // retira esse aluno do total contabilizado at? o momento.
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
    printf("    NOME                    MATR?CULA \n\n");
    for (int i = 0; i < total; i++)
    {
        printf("  %-20s  --     %03d\n", alunos[i].nome, alunos[i].matricula);
    }
    printf("\n");
}