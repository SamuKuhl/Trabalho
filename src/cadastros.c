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




}
