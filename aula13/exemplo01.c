#include <stdio.h>
#include <stdlib.h>

typedef struct No {

    char Chave;

    // No caso de árvore com grau 3: 

    struct No * F1; // 1° filho
    struct No * F2; // 2° filho
    struct No * F3; // 3° filho 

    // Outra possibilidade: 

    struct No * F[3]; //Filhos F[0], F[1] e F[2]. 

} No; 

No * criarNo(char Chave) {

    No * N = (No *) malloc(sizeof(No));

    if(N == NULL){
        printf("ERRO: nao ha memoria para o no.\n");
        return NULL;
    }

    N->Chave = Chave;
    N->F1 = NULL;
    N->F2 = NULL;
    N->F3 = NULL; 

    for(int i = 0; i < 3; i++){
        N->F[i] = NULL;

        return N; 
    }
}