#ifndef CADASTROS_H
#define CADASTROS_H

#include "tipos.h"

void iniciar_aeronaves(struct lista_aeronaves *lista);
void iniciar_rotas(struct lista_rotas *lista);

struct aeronave* criar_aeronave(int id_atual);
struct rota* criar_rota(int id_atual);

#endif