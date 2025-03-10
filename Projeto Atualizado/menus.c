#include <stdio.h>
#include "tipos.h"
void menuPrincipal(){
    printf("\n===========================================================\n");
    printf("       Sistema Eletr?nico de Gest?o de Alunos - SEGA\n");
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
    printf("    5. Voltar ao menu principal;\n");
    printf("    6. Sair\n");
    printf("===========================================================\n");
}

void menuCaso2(){
    printf("\n===========================================================\n\n");
    printf("           MENU DE GERENCIAMENTO DE ALUNOS FORMADOS\n\n\n");
    printf("    1. Consultar aluno;\n");
    printf("    2. Adicionar aluno;\n");
    printf("    3. Remover aluno;\n");
    printf("    4. Quantidade de alunos formados;\n");
    printf("    5. Voltar ao menu principal;\n");
    printf("    6. Sair\n");
    printf("===========================================================\n");
}

void desejaVoltarAoMenu(){
    printf("\nDeseja voltar ao menu?\n1 - Voltar ao menu anterior\n2 - Voltar ao menu principal\n");
}

void printAluno(Aluno aluno){
    printf("-- Registro do aluno --\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Matrícula: 00%d\n", aluno.matricula);
}