#include <stdio.h>
#include "tipos.h"
void menuPrincipal(){
    printf("\n===========================================================\n");
    printf("       Sistema Eletrônico de Gestão de Alunos - SEGA\n");
    printf("===========================================================\n\n");
    printf("                    - Menu Principal -\n\n\n");
    printf("    1. Alunos (graduando)\n");
    printf("    2. Alunos (formado)\n");
    printf("    3. Sair\n");
    printf("===========================================================\n");    
}

void menuCaso1(){
    printf("\n===========================================================\n\n");
    printf("            MENU DE GERENCIAMENTO DE DISCENTES \n\n\n");
    printf("    1. Consultar aluno;\n");
    printf("    2. Adicionar aluno;\n");
    printf("    3. Remover aluno;\n");
    printf("    4. Quantidade de alunos graduando\n");
    printf("    5. Listar alunos\n");
    printf("    6. Voltar ao menu principal;\n");
    printf("    7. Sair\n");
    printf("===========================================================\n");
}

void menuCaso2(){
    printf("\n===========================================================\n\n");
    printf("           MENU DE GERENCIAMENTO DE ALUNOS FORMADOS\n\n\n");
    printf("    1. Consultar aluno;\n");
    printf("    2. Adicionar aluno;\n");
    printf("    3. Remover aluno;\n");
    printf("    4. Quantidade de alunos formados;\n");
    printf("    5. Listar alunos\n");
    printf("    6. Voltar ao menu principal;\n");
    printf("    7. Sair\n");
    printf("===========================================================\n");
}

void desejaVoltarAoMenu(){
    printf("\nDeseja voltar ao menu?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
}

void printAluno(Aluno aluno){
    printf("-- Registro do Aluno --\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Matrícula: 00%d\n", aluno.matricula);
    printf("n");
}

void listaAlunos(){
    system("clear");
    printf("          -- Banco de alunos --\n\n");
    printf("    NOME                    MATRÍCULA \n\n");
}

void desejaVoltarAoMenu2(){
    printf("\nDigita 1 para voltar ao menu anterior ou 2 para sair: \n");
}

void sistema(){
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


}