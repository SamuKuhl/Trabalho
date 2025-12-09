#include <stdio.h>


int menu_principal(){
    int op;
    printf("\n--- Controle de Aeronaves e Rotas ---\n");
    printf("1 - Cadastros\n");
    printf("2 - Relatorios e Consultas\n");
    printf("0 - Sair\n");
    printf("Escolha uma da opções: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int menu_cadastros() {
    int op;
    printf("\n--- Menu Cadastros ---\n");
    printf("1 - Nova Aeronave\n");
    printf("2 - Nova Rota\n");
    printf("0 - Voltar\n");
    printf("Escolha uma da opções: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int menu_relatorios() {
    int op;
    printf("\n--- Menu Relatorios ---\n");
    printf("1 - Listar Aviões\n");
    printf("2 - Procurar Avioes\n");
    printf("3 - Listar Avioes por Fabricante\n");
    printf("4 - Listar Avioes por Tipo\n");
    printf("5 - Listar Avioes por Modelo\n");
    printf("6 - Listar Avioes por Ano\n");
    printf("7 - Listar Avioes por Situacao\n");
    printf("8 - Listar Rotas por Destino\n");
    printf("9 - Listar Rotas por Origem\n");
    printf("10 - Listar Todas as Rotas\n");
    printf("0 - Voltar\n");
    printf("Escolha uma da opções: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int menu_saida() {
    int op;
    printf("\nQual formato de arquivo de sua preferência?\n");
    printf("1 - Na Tela\n");
    printf("2 - Arquivo CSV\n");
    printf("3 - Arquivo HTML\n");
    printf("0 - Cancelar\n");
    printf("Escolha uma da opções: ");
    scanf("%d", &op);
    getchar();
    return op;
}