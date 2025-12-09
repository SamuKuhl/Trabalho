#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "tipos.h"

void salvar_binario_avioes(struct aeronave *inicio);
void salvar_binario_rotas(struct rota *inicio);

void carregar_binario_avioes(struct lista_aeronaves *lista);
void carregar_binario_rotas(struct lista_rotas *lista);

#endif