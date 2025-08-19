#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * arq;
    arq = fopen("carrinho.txt", "r");

    if (arq == NULL){
        printf("ERRO: arquivo nao aberto!\n");
        exit(1);
    }

    char Produto[50];
    int Unidades;
    float Valor;
    float Total;
    float TT = 0;

    for (int i = 0; i < 4; i++){
        fscanf(arq, "%s %d %f\n", Produto, &Unidades, &Valor); 
        Total = Unidades * Valor; 
        printf("%s - %d x RS %.2f == %.2f\n", Produto, Unidades, Valor, Total);
        TT += Total; 
    }

    printf("O valor total da compra eh RS %.2f", TT);

    return 0;
}