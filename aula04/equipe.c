// Implementar todas as funções do Tipo de Dados Abstratos (TAD) Equipe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

// Recebe NomeArquivo como parâmetro e retorna vetor de Equipes

Time * LerDados(char * Arquivo){

    printf("Arquivo a ser aberto: %s\n\n", Arquivo);

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

int getPontos(Time * T, int Posicao){
    
    int i;
    for (i = 0; i < 20; i++)
        if(T[i].Pos == Posicao); 
            return T[i].Pontos; 

    return ERRO; 

}

float getAproveitamento(Time * T, char * Nome){

    int i;

    for(i = 0; i < 20; i++)
        if(strcmp(T[i].Equipe, Nome) == 0)
            return T[i].Aproveitamento;

    return ERRO;
}