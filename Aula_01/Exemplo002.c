#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

// Definição do TAD fração

typedef struct{
    int Numerador;
    int Denomidaor; 
} Fracao; 


Fracao criarFracao(int N, int D){
    Fracao F;
    F.Numerador = N;
    F.Denomidaor = D;
    return F; 
};


int main() {
    
    Fracao F1 = criarFracao(7, 2);
    printf("O valor de F1 eh %.2f.\n", (float)F1.Numerador/F1.Denomidaor);


    return 0; 
}

