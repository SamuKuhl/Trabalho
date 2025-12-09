#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/arquivos.h"
#include "./include/utils.h"
#include <stdio.h>
#include <string.h>

int main() {

    struct lista_aeronaves lista_avioes;
    struct lista_rotas lista_voos;
    

    iniciar_lista_aeronaves(&lista_avioes);
    iniciar_lista_rotas(&lista_voos);


    carregar_binario_avioes(&lista_avioes);
    carregar_binario_rotas(&lista_voos);

    int op_princ, op_sub, op_saida;
    char texto_busca[100];
    char nome_arquivo[100];
    int int_busca;

    do {
        op_princ = menu_principal();

        switch (op_princ) {

            case 1:
                do {
                    op_sub = menu_cadastros();
                    if (op_sub == 1) {
                       
                        adicionar_aeronave(&lista_avioes, criar_aeronave(lista_avioes.qtd));
                    } 
                    else if (op_sub == 2) {
                        adicionar_rota(&lista_voos, criar_rota(lista_voos.qtd));
                    }
                } while (op_sub != 0);
                break;

           
            case 2:
                do {
                    op_sub = menu_relatorios();
                    if (op_sub == 0) break; 
            
                    if (op_sub == 1 || op_sub == 10) {
                        op_saida = menu_saida();
                        if (op_saida == 0) continue; 
                        
                        if (op_saida > 1) { 
                            printf("Nome do arquivo (sem extensao): ");
                            fgets(nome_arquivo, 100, stdin);
                            remover_enter(nome_arquivo);
                            if (op_saida == 2) strcat(nome_arquivo, ".csv");
                            else strcat(nome_arquivo, ".html");
                        }
                    } else {
                        op_saida = 1; 
                    }

                   
                    switch (op_sub) {
                        case 1: 
                            if (op_saida == 1) listar_todos_avioes(lista_avioes.inicio);
                            else exportar_avioes(lista_avioes.inicio, op_saida, nome_arquivo);
                            break;

                        case 2: 
                            printf("Digite o Prefixo (Matricula): ");
                            fgets(texto_busca, 100, stdin);
                            struct aeronave *enc = buscar_recursivo(lista_avioes.inicio, texto_busca);
                            if (enc != NULL) {
                                printf(">> ENCONTRADO:\n");
                                imprimir_aviao(enc);
                            } else {
                                printf(">> NAO ENCONTRADO.\n");
                            }
                            break;

                        case 3: 
                            printf("Digite Fabricante: "); fgets(texto_busca, 100, stdin);
                            filtrar_avioes_fabricante(lista_avioes.inicio, texto_busca);
                            break;

                        case 4: 
                            printf("Tipo (Carga/Passageiro): "); fgets(texto_busca, 100, stdin);
                            filtrar_avioes_tipo(lista_avioes.inicio, texto_busca);
                            break;

                        case 5: 
                            printf("Modelo: "); fgets(texto_busca, 100, stdin);
                            filtrar_avioes_modelo(lista_avioes.inicio, texto_busca);
                            break;

                        case 6: 
                            printf("Ano: "); scanf("%d", &int_busca); getchar();
                            filtrar_avioes_ano(lista_avioes.inicio, int_busca);
                            break;

                        case 7:
                            printf("Situacao: "); fgets(texto_busca, 100, stdin);
                            filtrar_avioes_situacao(lista_avioes.inicio, texto_busca);
                            break;

                        case 8: 
                            printf("Destino: "); fgets(texto_busca, 100, stdin);
                            filtrar_rotas_destino(lista_voos.inicio, texto_busca);
                            break;

                        case 9: 
                            printf("Origem: "); fgets(texto_busca, 100, stdin);
                            filtrar_rotas_origem(lista_voos.inicio, texto_busca);
                            break;

                        case 10:
                            if (op_saida == 1) listar_todas_rotas(lista_voos.inicio);
                            else exportar_rotas(lista_voos.inicio, op_saida, nome_arquivo);
                            break;
                    }

                    if (op_saida == 1) { 
                        printf("\nPressione ENTER para continuar...");
                        getchar();
                    }

                } while (op_sub != 0);
                break;

            case 0:
                printf("Salvando dados e saindo...\n");
                salvar_binario_avioes(lista_avioes.inicio);
                salvar_binario_rotas(lista_voos.inicio);
                break;
        }

    } while (op_princ != 0);

    return 0;
}