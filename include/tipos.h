#ifndef TIPOS_H
#define TIPOS_H

#define TAM_TEXTO 100
struct aeronave {
    int id;
    char modelo[TAM_TEXTO];
    char matricula[TAM_TEXTO];
    int ano;
    char tipo [TAM_TEXTO];
    int capacidade;
    char situacao[TAM_TEXTO];
    int pilotos;
    int comissarios;
    struct aeronave *prox;
};

struct rota{
    int codigo;
    char data_hora[TAM_TEXTO];
    char origem[TAM_TEXTO];
    char destino[TAM_TEXTO];
    char tempo_voo[TAM_TEXTO];
    float combustivel;
    int passageiros;
    float carga;
    char tripulacao[TAM_TEXTO];
    int id_aviao;
    struct rota *prox;
};

struct lista_aeronaves{
    struct aeronave *inicio;
    struct aeronave *fim;
    int qtd;
};

struct lista_rotas{
    struct rota *inicio;
    struct rota *fim;
    int qtd;
};

#endif