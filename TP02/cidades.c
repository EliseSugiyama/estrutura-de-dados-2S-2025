#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidades.h"

#define MAX_CIDADES 100000
#define MAX_DISTANCIA 1000000000

Estrada *getEstrada(const char *nomeArquivo){

    FILE * arq = fopen(nomeArquivo, "r");
    if (!arq){
        printf("ERRO: arquivo nao encontrado.\n");
        fclose(arq);
        return NULL; 
    }

    Estrada * Wakanda = malloc(sizeof(Estrada)); 
    if (!Wakanda){
        printf("ERRO: estrada nao encontrada.\n");
        return NULL; 
    }

    Wakanda->Inicio = NULL; 

    if (fscanf(arq, "%d", &Wakanda->T) != 1 || fscanf(arq, "%d", &Wakanda->N) != 1){
        printf("ERRO: formato invalido.\n");
        fclose(arq);
        free(Wakanda);
        return NULL;
    }

    if(Wakanda->T < 3 || Wakanda->T > 1000000){
        printf("ERRO: o tamanho da estrada esta em desacordo com as restricoes!\n");

        fclose(arq); 
        Cidade * temp = Wakanda->Inicio;
            while (temp) {
                Cidade * prox = temp->Proximo;
                free(temp);
                temp = prox; 
            }
        free(Wakanda); 
        return NULL; 
    }

    if(Wakanda->N < 2 || Wakanda->N > 10000){
        printf("ERRO: a quantidade de cidades esta em desacordo com as restricoes!\n");

        fclose(arq); 
        Cidade * temp = Wakanda->Inicio;
            while (temp) {
                Cidade * prox = temp->Proximo;
                free(temp);
                temp = prox; 
            }
        free(Wakanda); 
        return NULL; 
    }

    Cidade * anterior = NULL;
    Cidade * cidadesOrdenadas[MAX_CIDADES];

    for(int i = 0; i < Wakanda->N; i++){
        Cidade * atual = malloc(sizeof(Cidade));

        if(!atual){
            printf("ERRO: memoria insuficiente.\n");

            fclose(arq);
            Cidade * temp = Wakanda->Inicio;
            while (temp) {
                Cidade * prox = temp->Proximo;
                free(temp);
                temp = prox; 
            }
            free(Wakanda);
            return NULL; 
        }

        if(fscanf(arq, "%d %[^\n]", &atual->Posicao, atual->Nome) < 2){
            printf("ERRO: formato invalido.\n");
            free(atual);
            fclose(arq);

            Cidade * temp = Wakanda->Inicio;
            while (temp) {
                Cidade * prox = temp->Proximo;
                free(temp);
                temp = prox; 
            }
            free(Wakanda); 
            return NULL;
        }

        atual->Proximo = NULL;

        if(atual->Posicao <= 0 || atual->Posicao >= Wakanda->T){
            printf("ERRO: a distancia da cidade esta em desacordo com as restricoes!\n");

            fclose(arq);
            Cidade * temp = Wakanda->Inicio;
            while (temp) {
                Cidade * prox = temp->Proximo;
                free(temp);
                temp = prox; 
            }
            free(Wakanda); 
            return NULL;
        }

        for(int j = 0; j < i; j++){
            if(cidadesOrdenadas[j]->Posicao == atual->Posicao){
                printf("ERRO: a localizacao de uma ou mais cidades estao em descordo com as restricoes!\n");

                fclose(arq);
                Cidade * temp = Wakanda->Inicio;
                while (temp) {
                    Cidade * prox = temp->Proximo;
                    free(temp);
                    temp = prox; 
                }
                free(Wakanda);
                return NULL;
            }
        }

        cidadesOrdenadas[i] = atual;

        if(anterior){
            anterior->Proximo = atual;
        } else {
            Wakanda->Inicio = atual; 
        }

        anterior = atual; 
    }

    fclose(arq);

    return Wakanda; 
}


double calcularMenorVizinhanca(const char *nomeArquivo){

    Estrada * Wakanda = getEstrada(nomeArquivo);
    if(!Wakanda){
        return -1.0;
    }

    if(Wakanda->N <= 1){
        return -1.0;
    }

    Cidade * cidadesOrdenadas[MAX_CIDADES];
    Cidade * atual = Wakanda->Inicio;
    int n = 0; 

    while(atual){
        if(n >= MAX_CIDADES){
            return -1.0;
        }

        cidadesOrdenadas[n++] = atual;
        atual = atual->Proximo;
    }

    if(n != Wakanda->N){
        return -1.0;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(cidadesOrdenadas[i]->Posicao > cidadesOrdenadas[j]->Posicao){
                Cidade * temp = cidadesOrdenadas[i];
                cidadesOrdenadas[i] = cidadesOrdenadas[j];
                cidadesOrdenadas[j] = temp; 
            }
        }
    }

    double menor;
    int indiceMenor; 

    for(int i = 0; i < n; i++){
        double esquerda, direita;

        if(i == 0){
            esquerda = 0.0;
        } else {
            esquerda = (cidadesOrdenadas[i]->Posicao + cidadesOrdenadas[i - 1]->Posicao) / 2.0;
        }

        if(i == n-1){
            direita = (double)Wakanda->T;
        } else {
            direita = (cidadesOrdenadas[i]->Posicao + cidadesOrdenadas[i+1]->Posicao) / 2.0;
        }

        double distancia = direita - esquerda;

        if(distancia < menor){
            menor = distancia;
        }
    }

    return menor; 
}


char *cidadeMenorVizinhanca(const char *nomeArquivo){
    Estrada * Wakanda = getEstrada(nomeArquivo);
    if(!Wakanda){
        return NULL;
    }

    if(Wakanda->N <= 1){
        return NULL;
    }

    Cidade * cidadesOrdenadas[MAX_CIDADES];
    Cidade * atual = Wakanda->Inicio;
    int n = 0;

    while(atual){
        if (n >= MAX_CIDADES){
            return NULL;
        }
        
        cidadesOrdenadas[n++] = atual;
        atual = atual->Proximo;
    }

    if(n != Wakanda->N){
        return NULL;
    }

    for(int i = 0 ; i < n - 1; i++){
        for(int j = i + 1; j <n; j++){
            if(cidadesOrdenadas[i]->Posicao > cidadesOrdenadas[j]->Posicao){
                Cidade * temp = cidadesOrdenadas[i];
                cidadesOrdenadas[i] = cidadesOrdenadas[j];
                cidadesOrdenadas[j] = temp; 
            }
        }
    }

    double menor = (double)Wakanda->T; 
    int indiceMenor = -1;

    for(int i = 0; i < n; i++){
       double esquerda = (i == 0)
            ? 0.0
            : (cidadesOrdenadas[i]->Posicao + cidadesOrdenadas[i-1]->Posicao) / 2.0;

        double direita = (i == n-1)
            ? (double)Wakanda->T
            : (cidadesOrdenadas[i]->Posicao + cidadesOrdenadas[i+1]->Posicao) / 2.0;

        double vizinhanca = direita - esquerda;

        if(vizinhanca < menor){
            menor = vizinhanca; 
            indiceMenor = i;
        }
    }

    if(indiceMenor == -1){
        return NULL;
    }

    const char * resultado = cidadesOrdenadas[indiceMenor]->Nome;

    char * menorVizinhaca = malloc(strlen(resultado) + 1);
    if(!menorVizinhaca){
        return NULL; 
    }

    strcpy(menorVizinhaca, resultado); 

    return menorVizinhaca; 


}