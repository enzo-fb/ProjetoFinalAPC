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
    sistema();
}
