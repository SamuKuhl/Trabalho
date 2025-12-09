#include "../include/cadastros.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void iniciar_lista_aeronaves(struct lista_aeronaves *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

void iniciar_lista_rotas(struct lista_rotas *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

void adicionar_aeronave(struct lista_aeronaves *lista, struct aeronave *novo) {
    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->qtd++;
}

void adicionar_rota(struct lista_rotas *lista, struct rota *novo) {
    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->qtd++;
}

struct aeronave* criar_aeronave(int id_atual) {
    struct aeronave *novo = (struct aeronave*) malloc(sizeof(struct aeronave));
    
    novo->id = id_atual + 1;
    printf("\n--- Cadastro de Aeronave (ID: %d) ---\n", novo->id);

    printf("Modelo: ");
    fgets(novo->modelo, TAM_TEXTO, stdin);
    remover_enter(novo->modelo);
    para_maiusculo(novo->modelo);

    printf("Fabricante: ");
    fgets(novo->fabricante, TAM_TEXTO, stdin);
    remover_enter(novo->fabricante);
    para_maiusculo(novo->fabricante);

    printf("Matricula/Prefixo: ");
    fgets(novo->matricula, TAM_TEXTO, stdin);
    remover_enter(novo->matricula);
    para_maiusculo(novo->matricula);

    printf("Ano Fabricacao: ");
    scanf("%d", &novo->ano);
    getchar();

    printf("Tipo (Carga/Passageiro): ");
    fgets(novo->tipo, TAM_TEXTO, stdin);
    remover_enter(novo->tipo);
    para_maiusculo(novo->tipo);

    printf("Capacidade: ");
    scanf("%d", &novo->capacidade);
    getchar();

    printf("Situacao (Operacao/Manutencao): ");
    fgets(novo->situacao, TAM_TEXTO, stdin);
    remover_enter(novo->situacao);
    para_maiusculo(novo->situacao);

    printf("Qtd Pilotos: ");
    scanf("%d", &novo->pilotos);

    printf("Qtd Comissarios: ");
    scanf("%d", &novo->comissarios);
    getchar();

    novo->prox = NULL;
    return novo;
}

struct rota* criar_rota(int id_atual) {
    struct rota *novo = (struct rota*) malloc(sizeof(struct rota));
    
    novo->codigo = id_atual + 1;
    printf("\n--- Cadastro de Rota (COD: %d) ---\n", novo->codigo);

    printf("Data e Hora: ");
    fgets(novo->data_hora, TAM_TEXTO, stdin);
    remover_enter(novo->data_hora);

    printf("Origem: ");
    fgets(novo->origem, TAM_TEXTO, stdin);
    remover_enter(novo->origem);
    para_maiusculo(novo->origem);

    printf("Destino: ");
    fgets(novo->destino, TAM_TEXTO, stdin);
    remover_enter(novo->destino);
    para_maiusculo(novo->destino);

    printf("Tempo de Voo: ");
    fgets(novo->tempo_voo, TAM_TEXTO, stdin);
    remover_enter(novo->tempo_voo);

    printf("Combustivel necessario: ");
    scanf("%f", &novo->combustivel);

    printf("Qtd Passageiros: ");
    scanf("%d", &novo->passageiros);

    printf("Carga Util: ");
    scanf("%f", &novo->carga);
    getchar();

    printf("Tripulacao (nomes): ");
    fgets(novo->tripulacao, TAM_TEXTO, stdin);
    remover_enter(novo->tripulacao);

    printf("ID do Aviao Alocado: ");
    scanf("%d", &novo->id_aviao);
    getchar();

    novo->prox = NULL;
    return novo;
}