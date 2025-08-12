#ifndef FRACAO_H
#define FRACAO_H



// Definição do TAD fração

typedef struct{
    int Num;
    int Den; 
} Fracao; 

// Protótipos das funções

int calcularMDC(int A, int B);
Fracao simplificarFracao(Fracao F);
Fracao criarFracao(int N, int D);
Fracao somarFracoes(Fracao F, Fracao G);
Fracao subtrairFuncoes(Fracao F, Fracao G);
void exibirFracao(Fracao F);

#endif