#include "../include/cadastros.h"
#include <stdio.h>
#include <stdlib.h>

void inicicar_aeronaves(struct lista_aeronaves *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

void iniciar_rotas(struct lista_rotas *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd =0;
}

void adicionar_aeronave(struct lista_aeronaves *lista, struct aeronave *novo) {
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->qtd++;
}


void adicionar_rota(struct lista_rotas *lista, struct rota *novo) {
    if(lista->inicio == NULL){
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
    printf("\n---Cadastro de Aeronave (ID: %d)---\n", novo->id);

    printf("Modelo: ");
    fgets(novo->modelo, TAM_TEXTO, stdin);

    printf("Fabricamte: ");
    fgets(novo->fabricante, TAM_TEXTO, stdin);

    printf("Matricula: ");
    fgets(novo->matricula, TAM_TEXTO, stdin);
    
    printf("Ano Fabricacao: ");
    scanf("%d", &novo->ano);
    getchar();

    printf("Tipo (Carga 1/Passageiro 2): ");
    fgets(novo->tipo, TAM_TEXTO, stdin);

    printf("Capacidade: ");
    scanf("%d", &novo->capacidade);
    getchar();

    printf("Situação (Opertando/Manuntecao): ");
    fgets(novo->situacao, TAM_TEXTO, stdin);

    printf("Quantidade Pilotos: ");
    scanf("%d", &novo->pilotos);

    printf("Quantidade Comissarios: ");
    scanf("%d", &novo->comissarios);
    getchar;

    novo->prox = NULL;
    return novo;
}

struct rota* criar_aeronave(int id_atual) {
    struct rota *novo = (struct rota*) malloc(sizeof(struct aeronave));

    novo->codigo = id_atual + 1;
    printf("\n---Cadastro de Rotas (ID: %d)---\n", novo->codigo);

    printf("Data e Hora (DD MM AAAA): ");
    fgets(novo->data_hora, TAM_TEXTO, stdin);

    printf("Origem: ");
    fgets(novo->origem, TAM_TEXTO, stdin);

    printf("Destino: ");
    fgets(novo->destino, TAM_TEXTO, stdin);
    
    printf("Tempo de voo (horas): ");
    scanf(novo->tempo_voo, TAM_TEXTO, stdin);
    getchar();

    printf("Combustivel necessario: ");
    scanf("%f",&novo->combustivel);

    printf("Quantidade Passageiros: ");
    scanf("%d", &novo->passageiros);

    printf("Carga Util (kg): ");
    scanf("%f",&novo->carga);
    getchar();

    printf("Tripulacao (Nomes dos pilotos): ");
   fgets(novo->tripulacao, TAM_TEXTO, stdin);

    printf("ID do Aviao da Rota: ");
    scanf("%d", &novo->id_aviao);
    getchar();

    novo->prox = NULL;
    return novo;
}
