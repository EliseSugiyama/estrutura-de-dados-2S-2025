#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main(){

    Item * I1 = criarItem(30);
    Item * I2 = criarItem(26);
    Item * I3 = criarItem(12);
    Item * I4 = criarItem(9);
    Item * I5 = criarItem(5);
    Item * I6 = criarItem(10);
    Item * I7 = criarItem(27);
    
    Pilha * MinhaPilha = criarPilha();

    printf("Endereco da pilha: %X \n", MinhaPilha);
    printf("\n");

    empilhar(MinhaPilha, I1); 
    empilhar(MinhaPilha, I2); 
    empilhar(MinhaPilha, I3); 
    empilhar(MinhaPilha, I4); 
    empilhar(MinhaPilha, I5); 
    empilhar(MinhaPilha, I6); 
    empilhar(MinhaPilha, I7); 

    printf("%d \n", MinhaPilha->Topo->Chave);

    desemplihar(MinhaPilha); 

    printf("%d \n", MinhaPilha->Topo->Chave);
}