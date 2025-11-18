#include <stdio.h>
#include <stdlib.h>

typedef struct No {

    int Chave;

    // No caso de árvore BINÁRIA (máximo 2 filhos); 

    struct No * Esquerda; // 1° filho
    struct No * Direita; // 2° filho

} No; 

No * criarNo(int Chave) {

    No * N = (No *) malloc(sizeof(No));

    if(N == NULL){
        printf("ERRO: nao ha memoria para o no.\n");
        return NULL;
    }

    N->Chave = Chave;
    N->Esquerda = NULL;
    N->Direita = NULL;

    return N; 
}

int contarNos(No * N){

    if (N == NULL){
        return 0; 
    }

    return 1 + contarNos(N->Direita) + contarNos(N->Esquerda); 

}

int main() {

    // No de nível 1: 

    No * Raiz = criarNo(10);

    // Nós de nível 2: 

    Raiz->Esquerda = criarNo(12);
    Raiz->Direita = criarNo(15); 

    // Nós de nível 3: 

    Raiz->Esquerda->Esquerda = criarNo(16);
    Raiz->Esquerda->Direita = criarNo(18);
    Raiz->Direita->Direita = criarNo(20); 

    // Nós de nível 4: 

    Raiz->Direita->Direita->Esquerda = criarNo(17);
    Raiz->Direita0->Direita->Direita = criarNo(19); 

}