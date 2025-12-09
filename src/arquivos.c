#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include <stdio.h>
#include <stdlib.h>

void salvar_binario_avioes(struct aeronave *inicio) {
    FILE *arquivo = fopen("avioes.bin", "wb"); 
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo avioes.bin\n");
        return;
    }
    

    while (inicio != NULL) {
        fwrite(inicio, sizeof(struct aeronave), 1, arquivo);
        inicio = inicio->prox;
    }
    fclose(arquivo);
}

void salvar_binario_rotas(struct rota *inicio) {
    FILE *arquivo = fopen("rotas.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo rotas.bin\n");
        return;
    }

    while (inicio != NULL) {
        fwrite(inicio, sizeof(struct rota), 1, arquivo);
        inicio = inicio->prox;
    }
    fclose(arquivo);
}

void carregar_binario_avioes(struct lista_aeronaves *lista) {
    FILE *arquivo = fopen("avioes.bin", "rb");
    if (arquivo == NULL) return; 

    struct aeronave *novo;
    while (1) {
        novo = (struct aeronave*) malloc(sizeof(struct aeronave));
        
        
        if (fread(novo, sizeof(struct aeronave), 1, arquivo) == 0) {
            free(novo);
            break; 
        }
        
        novo->prox = NULL;
        adicionar_aeronave(lista, novo);
    }
    fclose(arquivo);
    printf("Carregados %d avioes do arquivo.\n", lista->qtd);
}

void carregar_binario_rotas(struct lista_rotas *lista) {
    FILE *arquivo = fopen("rotas.bin", "rb");
    if (arquivo == NULL) return;

    struct rota *novo;
    while (1) {
        novo = (struct rota*) malloc(sizeof(struct rota));
        
        if (fread(novo, sizeof(struct rota), 1, arquivo) == 0) {
            free(novo);
            break;
        }
        
        novo->prox = NULL;
        adicionar_rota(lista, novo);
    }
    fclose(arquivo);
    printf("Carregadas %d rotas do arquivo.\n", lista->qtd);
}