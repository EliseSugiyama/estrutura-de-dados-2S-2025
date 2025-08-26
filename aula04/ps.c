// Implementando o algoritmo de PESQUISA SEQUENCIAL

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define ERRO -1

int PesquisaSequencial(int * V, int N, int Chave);
//char * PesquisaSequencial_2(int * V, int N, int Chave);

int main() {
    int Numeros[] = {
        14, 29, 37, 11, 43, 25, 19, 32, 16, 22,
        40, 13, 28, 35, 10, 45, 29, 38, 17, 24,
        30, 41, 15, 27, 33, 18, 26, 39, 12, 21
    };

    int Tamanho = sizeof(Numeros)/sizeof(int);
    int Elemento = 35;

    int Posicao = PesquisaSequencial(Numeros, Tamanho, Elemento);
    printf("%d\n", Posicao);

    //printf("%s", PesquisaSequencial_2(Numeros, Tamanho, Elemento)); 

    return 0;

}

// Implementação...

int PesquisaSequencial(int * V, int N, int Chave){

    int i;
    for (i = 0; i < N; i++){
        if (V[i] == Chave){
            return i; // O elemento chave foi encontrado no vetor.
        }
    } return ERRO; 

}

/*char * PesquisaSequencial_2(int * V, int N, int Chave){
    int i;
    char Resposta[100];

    for (i = 0; i < N; i++){
        if (V[i] == Chave){
            sprintf(Resposta, "O elemento %d esta na posicao %d\n", Chave, i);
            return Resposta; // O elemento chave foi encontrado no vetor
        }
    } 
    strcpy(Resposta, "ERRO: o elemento nao esta no vetor!\n");
    return Resposta; 

}*/