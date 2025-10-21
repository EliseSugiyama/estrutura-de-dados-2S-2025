#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um ITEM da lista ENCADEADA

typedef struct Item{
    
    int Chave;
    struct Item * Proximo; 

} Item;

Item * CriarItem(int Chave);

void ExibirLista(Item * Inicio); // Para lista não circular
void InserirItem(Item * Inicio, Item * I, int Posicao); 
void ExcluirItem(Item * Inicio, int Posicao); 

// Bloco Principal 

int main() {
    
    Item * A = CriarItem(17);
    Item * B = CriarItem(29);
    Item * C = CriarItem(41);
    Item * D = CriarItem(97); 

    // Lista A, B, C, D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;

    ExibirLista(A); 

    // Inserir o item P, cuja chave é 67, logo após C
    Item * P = CriarItem(67);

    P->Proximo = D;
    C->Proximo = P; 

    ExibirLista(A);

    // Inserir o item B da lista

    // A->Proximo = C;
    A->Proximo = B->Proximo;
    free(B);

    ExibirLista(A); 
}


Item * CriarItem(int Chave) {

    Item * X = (Item *) malloc(sizeof(Item));
    X->Chave = Chave;
    X->Proximo = NULL;
    return X; 
}

void ExibirLista(Item * Inicio) { 

    Item * X = Inicio;

    for(int i = 0; X != NULL; i++, X = X->Proximo){
        printf("%d\t", X->Chave); 
    }   
    printf("\n");
}
