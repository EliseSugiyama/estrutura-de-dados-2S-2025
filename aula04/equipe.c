// Implementar todas as funções do Tipo de Dados Abstratos (TAD) Equipe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

Time * LerDados(char  * Arquivo){

    printf("Arquivo a ser aberto: %s\n", Arquivo);

    Time * X = malloc(20 * sizeof(Time));
    if (X == NULL){
        printf("ERRO: memoria insuficiente!\n");
        exit(1);
    } 

    FILE * fp = fopen(Arquivo, "r");
    if(fp == NULL){
        printf("ERRO: arquivo nao pode ser aberto!\n");
        exit(1);
    }

    int i = 0;

    char cabecalho[100];
    fscanf(fp, "%s", cabecalho);

    while(
        fscanf(
            fp, 
            "%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d\n", 
            &X[i].Pos, X[i].Estado, X[i].Equipe, &X[i].Pontos, &X[i].Jogos, &X[i].Vitoria, 
            &X[i].Empate, &X[i].Derrota, &X[i].GolsPro, &X[i].GolsContra, &X[i].SaldoGols
             ) == 11) {
                X[i].Aproveitamento = (float) 100 * X[i].Pontos / (3 * X[i].Jogos);
                i++;
             }
    
    fclose(fp);

    return X;
}