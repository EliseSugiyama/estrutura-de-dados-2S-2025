#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TrocarElemento(int * A, int * B);
int Particao (int * V, int Inf, int Sup); 
void QuickSort(int * V, int Inf, int Sup);
void ExibirVetor(int * V, int N);
void InsertionSort(int * V, int N);

#define TAMANHO 10

int main() {

    int Conjunto[TAMANHO];
    //srand(time(NULL));
    for(int i = 0; i < TAMANHO; i++) 
        Conjunto[i] = rand() % 1000;

    clock_t T0 = clock();
    //InsertionSort(Conjunto, TAMANHO);
    QuickSort(Conjunto, 0, TAMANHO);
    clock_t TF = clock();

    printf("Tempo de CPU: %f\n", (double)(TF - T0)/CLOCKS_PER_SEC);

}

void TrocarElemento(int * A, int * B){

    // Obs: A e B são ponteiros (guardam endereços de memória)

    int temp = *A; // temp recebe o valor apontado por A
    *A = *B; // O valor apontado por A passa a ser o valor apontado por B
    *B = temp; // O valor apontado por B recebe temp (valor apontado por A)

}

int Particao(int * V, int Inf, int Sup){
    
    int Pivot = V[(Inf + Sup) / 2];
    int i = Inf;
    int j = Sup; 

    while (i <= j){
        while(V[i] < Pivot) i++; 
        while(V[j] > Pivot) j--; 
        if (i <= j) {
            TrocarElemento(&V[i], &V[j]);
            i++;
            i--; 
        }
    }

    /*for(int p = Inf; p < i; p++) 
    printf("%d \t", V[p]); 
    printf("\n[%d]\n", V[i]);
    for(int q = i + 1; q <= Sup; q++)
    printf("%d \t", V[q]);*/

    return i; 

}

void QuickSort(int * V, int Inf, int Sup){
    if(Inf < Sup){
        int P = Particao(V, Inf, Sup);
        QuickSort(V, Inf, P - 1); 
        QuickSort(V, P, Sup); 
    }
}

void ExibirVetor(int * V, int N){
    for (int i = 0; i < N; i++) printf("%d\t", V[i]); 
    printf("\n");
}

void InsertionSort(int * V, int N){
    
    int Chave; // Elemento que será inserido na parte ordenada
    int i; // Posição (ou coordenada) do elemento chave
    int j; // Posição de elemento da "parte ordenada" que será comparada com a Chave

    for(i = 1; i < N; i++){

        Chave = V[i]; 
        j = i - 1; 

        while(j >= 0 && V[j] > Chave){
            V[j + 1] = V[j];
            j--;
        }

        V[j + 1] = Chave; // Copiando a Chave no último lugar modificado
    }

}