#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "tipos.h"

void salvar_avioes(struct aeronave *inicio);
void salvar_rotas(struct rota *inicio);

void carregar_avioes(struct lista_aeronaves *lista);
void carregar_rotas(struct lista_rotas *lista);

#endif