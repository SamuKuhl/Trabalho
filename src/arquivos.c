#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include <stdio.h>
#include <stdlib.h>

void salvar_avioes(struct aeronave *inicio) {
    FILE *arquivo = fopen("avioes.bin", "wb");
    if (arquivo == NULL){
        printf("Erro ao criar arquivo .bin\n");
        return;
    }


}