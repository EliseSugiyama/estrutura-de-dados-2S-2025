#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    
    int Chave;
    struct Item * Proximo; 

} Item;

int main() {
    
    Item * I = (Item*) malloc (sizeof(Item));
    
    I->Chave = 23;
    I->Proximo = NULL;

    printf("endereco %x\n", I);
    printf("%d\n", I->Chave);
    printf("%x (NULL)\n", I->Proximo); 
}