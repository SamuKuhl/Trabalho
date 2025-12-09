#ifndef RELATORIOS_H
#define RELATORIOS_H

#include <stdio.h>
#include "tipos.h"

struct aeronave* buscar_recursivo(struct aeronave *elemento, char *prefixo);

void imprimir_aviao(struct aeronave *a);
void imprimir_rota(struct rota *r);

void listar_todos_avioes(struct aeronave *inicio);
void listar_todas_rotas(struct rota *inicio);

void filtrar_avioes_fabricante(struct aeronave *inicio, char *fab);
void filtrar_avioes_tipo(struct aeronave *inicio, char *tipo);
void filtrar_avioes_modelo(struct aeronave *inicio, char *modelo);
void filtrar_avioes_ano(struct aeronave *inicio, int ano);
void filtrar_avioes_situacao(struct aeronave *inicio, char *sit);
void filtrar_rotas_origem(struct rota *inicio, char *origem);
void filtrar_rotas_destino(struct rota *inicio, char *destino);

void exportar_avioes(struct aeronave *inicio, int tipo_arquivo, char *nome);
void exportar_rotas(struct rota *inicio, int tipo_arquivo, char *nome);

#endif