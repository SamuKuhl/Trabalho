#include "../include/relatorios.h"
#include <string.h>
#include <stdlib.h>


void imprimir_aviao(struct aeronave *a) {
    printf("ID: %d | Modelo: %s | Fab: %s | Mat: %s | Ano: %d | Sit: %s\n",
           a->id, a->modelo, a->fabricante, a->matricula, a->ano, a->situacao);
}

void imprimir_rota(struct rota *r) {
    printf("COD: %d | Origem: %s -> %s | Aviao ID: %d\n",
           r->codigo, r->origem, r->destino, r->id_aviao);
}


void listar_todos_avioes(struct aeronave *i) {
    if (!i) printf("Nenhum aviao cadastrado.\n");
    while (i) { imprimir_aviao(i); i = i->prox; }
}

void listar_todas_rotas(struct rota *i) {
    if (!i) printf("Nenhuma rota cadastrada.\n");
    while (i) { imprimir_rota(i); i = i->prox; }
}
#define FILTRO_TEXTO(lista, campo, valor, func) \
    while (lista) { if (strstr(lista->campo, valor)) func(lista); lista = lista->prox; }

#define FILTRO_INT(lista, campo, valor, func) \
    while (lista) { if (lista->campo == valor) func(lista); lista = lista->prox; }

void filtrar_avioes_fabricante(struct aeronave *i, char *fab){ FILTRO_TEXTO(i,fabricante,fab,imprimir_aviao); }
void filtrar_avioes_tipo(struct aeronave *i, char *t){ FILTRO_TEXTO(i,tipo,t,imprimir_aviao); }
void filtrar_avioes_modelo(struct aeronave *i, char *m){ FILTRO_TEXTO(i,modelo,m,imprimir_aviao); }
void filtrar_avioes_ano(struct aeronave *i, int ano){ FILTRO_INT(i,ano,ano,imprimir_aviao); }
void filtrar_avioes_situacao(struct aeronave *i, char *s){ FILTRO_TEXTO(i,situacao,s,imprimir_aviao); }

void filtrar_rotas_destino(struct rota *i, char *d){ FILTRO_TEXTO(i,destino,d,imprimir_rota); }
void filtrar_rotas_origem(struct rota *i, char *o){ FILTRO_TEXTO(i,origem,o,imprimir_rota); }

void exportar_avioes(struct aeronave *i, int tipo, char *nome) {
    FILE *f = fopen(nome, "w");
    if (!f) return;

    if (tipo == 2) {
        fprintf(f, "ID;MODELO;MATRICULA;SITUACAO\n");
        while (i) {
            fprintf(f, "%d;%s;%s;%s\n", i->id, i->modelo, i->matricula, i->situacao);
            i = i->prox;
        }
    } else if (tipo == 3) {
        fprintf(f, "<html><body><h1>Relatorio Avioes</h1><table border=1>");
        fprintf(f, "<tr><th>ID</th><th>Modelo</th><th>Matricula</th></tr>");
        while (i) {
            fprintf(f, "<tr><td>%d</td><td>%s</td><td>%s</td></tr>",
                    i->id, i->modelo, i->matricula);
            i = i->prox;
        }
        fprintf(f, "</table></body></html>");
    }

    fclose(f);
    printf("Arquivo %s gerado com sucesso!\n", nome);
}

void exportar_rotas(struct rota *i, int tipo, char *nome) {
    FILE *f = fopen(nome, "w");
    if (!f) return;

    if (tipo == 2) {
        fprintf(f, "CODIGO;ORIGEM;DESTINO;ID_AVIAO\n");
        while (i) {
            fprintf(f, "%d;%s;%s;%d\n", i->codigo, i->origem, i->destino, i->id_aviao);
            i = i->prox;
        }
    } else if (tipo == 3) {
        fprintf(f, "<html><body><h1>Relatorio Rotas</h1><table border=1>");
        fprintf(f, "<tr><th>COD</th><th>Origem</th><th>Destino</th></tr>");
        while (i) {
            fprintf(f, "<tr><td>%d</td><td>%s</td><td>%s</td></tr>",
                    i->codigo, i->origem, i->destino);
            i = i->prox;
        }
        fprintf(f, "</table></body></html>");
    }

    fclose(f);
    printf("Arquivo %s gerado com sucesso!\n", nome);
}
