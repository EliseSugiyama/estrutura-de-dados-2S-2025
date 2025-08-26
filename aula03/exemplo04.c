#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * arq;
    arq = fopen("tabuada.txt", "a");

    if (arq == NULL) {
        printf("ERRO: arquivo nao foi aberto!\n");
        exit(1);
    }

    int i;

    fprintf(arq, "Tabuada do 9: \n\n"); 

    for (i = 1; i <= 10; i++){
        fprintf(arq, "9 x %d = %d\n", i, i*9); 
    }

    fprintf(arq, "\n");
    fclose(arq);

    return 0;
}