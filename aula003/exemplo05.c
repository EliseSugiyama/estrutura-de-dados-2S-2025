#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fp;
    fp = fopen("bd.txt", "r"); //"r" para ler o arquivo

    if (fp == NULL){
        printf("ERRO: arquivo nao aberto!\n");
        exit(1);
    }

    int Conta; 
    float Saldo;
    char Nome[50];

    for(int i = 0; i < 4; i++){
    fscanf(fp, "%d %f %[^\n]\n", &Conta, &Saldo, Nome); //"%[^\n]" = lê até o \n 
    printf("%d\t%.2f\t\t%s\n", Conta, Saldo, Nome);
    }

    fclose(fp);
    return 0; 
}


// %[^] = lê até... 