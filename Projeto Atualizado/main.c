#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "menus.c"
#include "tipos.h"
#include "funcoes.c"
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
                    system("clear");
                    lista_alunos(lista_graduandos);
                    desejaVoltarAoMenu2();
                    scanf("%d", &escolha);
                    if (escolha == 2)
                    {
                        printf("Saindo...\n");
                        liberarListas(&lista_formados);
                        liberarListas(&lista_graduandos);
                        exit(0);
                    }
                    break;
                case 6:

                    system("clear");
                    break;
                case 7:
                    printf("Saindo...\n");
                    liberarListas(&lista_formados);
                    liberarListas(&lista_graduandos);
                    exit(0);
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
                    system("clear");
                    lista_alunos(lista_formados);
                    desejaVoltarAoMenu2();
                    scanf("%d", &escolha);
                    if (escolha == 2)
                    {
                        printf("Saindo...\n");
                        liberarListas(&lista_formados);
                        liberarListas(&lista_graduandos);
                        exit(0);
                    }

                    break;

                case 6:
                    system("clear");
                    break;
                case 7:
                    printf("Saindo...\n");            // mensagem de saída
                    liberarListas(&lista_formados);   // libera a lista de formados
                    liberarListas(&lista_graduandos); // libera a lista de graduandos
                    exit(0);                          // finaliza o programa
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
