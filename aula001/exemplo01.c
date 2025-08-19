#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    char Nome[150]; //151 caracteres
    char Telefone[14]; //15 caracteres
    char Endereco[200]; //201 caracteres
} Pessoa;

int main(){

    struct Pessoa X; 

    strcpy(X.Nome, "Maria Alves");
    strcpy(X.Telefone, "(61) 12345-6789");
    strcpy(X.Endereco, "SHIS 12 25 13"); 

    printf("%s\t%s\t%s\n", X.Nome, X.Endereco, X.Telefone);

    return 0;
}