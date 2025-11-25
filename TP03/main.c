#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "expressao.h"

int main() {
    
    char *testes[] = {
        "3 4 + 5 *",          // resultado esperado: 35
        "7 2 * 4 +",          // resultado esperado: 18
        "8 5 2 4 + * +",      // resultado esperado: 38
        "6 2 / 3 + 4 *",      // resultado esperado: 24
        "9 5 2 8 * 4 + * +",  // resultado esperado: 109
        "2 3 + log 5 /",      // resultado esperado: ≈ 0.14
        "10 log 3 ^ 2 +",     // resultado esperado: 3
        "45 60 + 30 cos *",   // resultado esperado: ≈ 90.93
        "0.5 45 sen 2 ^ +"    // resultado esperado: 1
    };

    char *testesExtras[] = {
        "90 tg",              // resultado esperado: deve dar erro ou infinito
        "16 raiz",            // resultado esperado: 4
        "100 log",            // resultado esperado: 2
        "2 3 ^ 4 +",          // resultado esperado: 12
        "5 0 /",              // resultado esperado: erro
        "9 -3 raiz",          // resultado esperado: erro
        "0 log"               // resultado esperado: erro
    };

    int n = sizeof(testes) / sizeof(testes[0]);
    int m = sizeof(testesExtras) / sizeof(testesExtras[0]);

    printf("=== Testes do enunciado ===\n\n");
    for (int i = 0; i < n; i++) {
        printf("Teste %d:\n", i+1);
        printf("Posfixa: %s\n", testes[i]);

        char *infixa = getFormaInFixa(testes[i]);
        if (infixa != NULL) {
            printf("Infixa: %s\n", infixa);
        } else {
            printf("Infixa: ERRO na conversao!\n");
        }

        float valor = getValorPosFixa(testes[i]);
        printf("Valor: %.2f\n\n", valor);
    }

    printf("=== Testes extras ===\n\n");
    for (int i = 0; i < m; i++) {
        printf("Teste extra %d:\n", i+1);
        printf("Posfixa: %s\n", testesExtras[i]);

        char *infixa = getFormaInFixa(testesExtras[i]);
        if (infixa != NULL) {
            printf("Infixa: %s\n", infixa);
        } else {
            printf("Infixa: ERRO na conversao!\n");
        }

        float valor = getValorPosFixa(testesExtras[i]);
        printf("Valor: %.2f\n\n", valor);
    }

    return 0;
}