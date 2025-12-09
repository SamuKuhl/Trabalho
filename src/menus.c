#include "../include/menus.h"
#include <stdio.h>

int menu_principal() {
    int op;
    printf("\n=== CONTROLE DE FROTA AEREA ===\n");
    printf("1. Cadastros\n");
    printf("2. Relatorios e Consultas\n");
    printf("0. Sair\n");
    printf("Escolha: ");
    scanf("%d", &op);
    getchar(); // Limpa o buffer do teclado
    return op;
}

int menu_cadastros() {
    int op;
    printf("\n--- MENU CADASTROS ---\n");
    printf("1. Nova Aeronave\n");
    printf("2. Nova Rota\n");
    printf("0. Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int menu_relatorios() {
    int op;
    printf("\n--- MENU RELATORIOS ---\n");
    printf("1. Listar TODOS os Avioes\n");
    printf("2. Buscar Aviao (Recursivo)\n");
    printf("3. Listar Avioes por Fabricante\n");
    printf("4. Listar Avioes por Tipo\n");
    printf("5. Listar Avioes por Modelo\n");
    printf("6. Listar Avioes por Ano\n");
    printf("7. Listar Avioes por Situacao\n");
    printf("8. Listar Rotas por Destino\n");
    printf("9. Listar Rotas por Origem\n");
    printf("10. Listar TODAS as Rotas\n");
    printf("0. Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int menu_saida() {
    int op;
    printf("\nComo deseja ver o resultado?\n");
    printf("1. Na Tela\n");
    printf("2. Arquivo CSV (Excel)\n");
    printf("3. Arquivo HTML (Site)\n");
    printf("0. Cancelar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    getchar();
    return op;
}