#include "../include/relatorios.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 

void imprimir_aviao(struct aeronave *a) {
    printf("ID: %d | Modelo: %s | Fab: %s | Mat: %s | Ano: %d | Sit: %s\n",
           a->id, a->modelo, a->fabricante, a->matricula, a->ano, a->situacao);
}

void imprimir_rota(struct rota *r) {
    printf("COD: %d | Origem: %s -> %s | Aviao ID: %d\n",
           r->codigo, r->origem, r->destino, r->id_aviao);
}

void listar_todos_avioes(struct aeronave *i) {
    if (!i) printf("Nenhum aviao cadastrado.\n"); /// Se a lista estiver vazia
    while (i) { imprimir_aviao(i); i = i->prox; } // Percorre a lista encadeada
}

void listar_todas_rotas(struct rota *i) {
    if (!i) printf("Nenhuma rota cadastrada.\n");
    while (i) { imprimir_rota(i); i = i->prox; }
}


void filtrar_avioes_fabricante(struct aeronave *i, char *fab) {
    while (i) {
        if (strstr(i->fabricante, fab)) {
            imprimir_aviao(i); // Imprime cada aeronave
        }
        i = i->prox; // Avança para o próximo elemento
    }
}

void filtrar_avioes_tipo(struct aeronave *i, char *t) {
    while (i) {
        if (strstr(i->tipo, t)) { //strstr busca se existe se o texto está contiddo dentro de i->fabricante
            imprimir_aviao(i); //se sim, imprime
        }
        i = i->prox;
    }
}

void filtrar_avioes_modelo(struct aeronave *i, char *m) {
    while (i) {
        if (strstr(i->modelo, m)) {
            imprimir_aviao(i);
        }
        i = i->prox;
    }
}

void filtrar_avioes_ano(struct aeronave *i, int ano) {
    while (i) {
        if (i->ano == ano) {
            imprimir_aviao(i);
        }
        i = i->prox;
    }
}

void filtrar_avioes_situacao(struct aeronave *i, char *s) {
    while (i) {
        if (strstr(i->situacao, s)) {
            imprimir_aviao(i);
        }
        i = i->prox;
    }
}

void filtrar_rotas_destino(struct rota *i, char *d) {
    while (i) {
        if (strstr(i->destino, d)) {
            imprimir_rota(i);
        }
        i = i->prox;
    }
}

void filtrar_rotas_origem(struct rota *i, char *o) {
    while (i) {
        if (strstr(i->origem, o)) {
            imprimir_rota(i);
        }
        i = i->prox;
    }
}

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