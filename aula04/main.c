#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

int main(){

    Time * Tabela = LerDados("tabela.csv");
    
    printf("%.2f%%\n", getAproveitamento(Tabela, "Flamengo"));


    return 0; 
}