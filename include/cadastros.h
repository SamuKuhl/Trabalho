#ifndef CADASTROS_H
#define CADASTROS_H

#include "tipos.h"


void iniciar_lista_aeronaves(struct lista_aeronaves *lista);
void iniciar_lista_rotas(struct lista_rotas *lista);
struct aeronave* criar_aeronave(int id_atual);
struct rota* criar_rota(int id_atual);
void adicionar_aeronave(struct lista_aeronaves *lista, struct aeronave *novo);
void adicionar_rota(struct lista_rotas *lista, struct rota *novo);

#endif