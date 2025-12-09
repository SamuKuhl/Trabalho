#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include <stdio.h>
#include <stdlib.h>

//Função que cria o arquivo .bin/ sobrescreve eçe
void salvar_binario_avioes(struct aeronave *inicio) 
 {
    FILE *arquivo = fopen("avioes.bin", "wb"); //se fopen retornar 0, mostra a mensagem de erro.bin
    if (arquivo == NULL) {
        printf("Erro.bin\n");
        return;
    }

    while (inicio != NULL) { //vai percorrer aeronaves eescrever
        fwrite(inicio, sizeof(struct aeronave), 1, arquivo);
        inicio = inicio->prox; //avança para o próximo nó da lista, ex: ID sai de 1 e vai para 2 
    }
    fclose(arquivo);
}

void salvar_binario_rotas(struct rota *inicio) {
    FILE *arquivo = fopen("rotas.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro.bin\n");
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
    FILE *arquivo = fopen("rotas.bin", "rb"); // Abre o arquivo "rotas.bin" no modo de leitura binária ("rb") e retorna um ponteiro para ele
                                            // se o arquivo não existir, fopen retorna NULL.
    if (arquivo == NULL) return;
    struct rota *novo;
    while (1) {
        novo = (struct rota*) malloc(sizeof(struct rota));
        
        if (fread(novo, sizeof(struct rota), 1, arquivo) == 0) //quando chegar no final da lista ou ter erro, fread = 0
        {
            free(novo); //evita vazamento de memória
            break;
        }
        novo->prox = NULL;
        adicionar_rota(lista, novo); //vai pegar todas os dados que foram lidos e vai adicioar uma nova rota
    }
    fclose(arquivo);
    printf("Carregadas %d rotas do arquivo.\n", lista->qtd); //retorna quantas rotas foram carregadas
}