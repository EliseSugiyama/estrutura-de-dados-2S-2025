#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "expressao.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846 
#endif

typedef struct {

    int topo;
    float itens[512];

} PilhaN; 

void empilhaN(PilhaN *p, float valor) {
    if(p->topo >= 511) {
        printf("ERRO: Pilha cheia!\n");
        return;
    }

    p->itens[++(p->topo)] = valor;
}

float desempilhaN(PilhaN *p) {
    if(p->topo < 0) {
        printf("ERRO: Pilha vazia!\n");
        return 0;
    }

    return p->itens[(p->topo)--];
}

typedef struct {

    int topo;
    char itens[512][512];

} PilhaS;

void empilhaS(PilhaS *p, char *valor) {
    if(p->topo >= 511) {
        printf("ERRO: Pilha cheia!\n");
        return;
    }

    strcpy(p->itens[++(p->topo)], valor);
}

char *desempilhaS(PilhaS *p) {
    if (p->topo < 0) {
        printf("ERRO: Pilha vazia!\n");
        return NULL;
    }

    return p->itens[(p->topo)--];
}

float getValorPosFixa(char *StrPosFixa) {
    PilhaN pilha;
    pilha.topo = -1;

    char copia [512];
    strcpy(copia, StrPosFixa);

    char *token = strtok(copia, " ");
    while (token != NULL) {
        char *endptr;
        float valor = strtof(token, &endptr);

        if(*endptr == '\0' && endptr != token) {
            empilhaN(&pilha, valor);

        } else if (strcmp(token, "+") == 0) {
            if(pilha.topo < 1) {
                printf("ERRO: Operadores insuficientes!\n");
                pilha.topo = -1;
                return 0;
            }
            float b = desempilhaN(&pilha);
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, a + b);

        } else if (strcmp(token, "-") == 0) {
            if(pilha.topo < 1) {
                printf("ERRO: Operadores insuficientes!\n");
                pilha.topo = -1;
                return 0;
            }
            float b = desempilhaN(&pilha);
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, a - b);

        } else if (strcmp(token, "*") == 0) {
            if(pilha.topo < 1) {
                printf("ERRO: Operadores insuficientes!\n");
                pilha.topo = -1;
                return 0;
            }
            float b = desempilhaN(&pilha);
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, a * b);

        } else if (strcmp(token, "/") == 0) {
            if(pilha.topo < 1) {
                printf("ERRO: Operadores insuficientes!\n");
                pilha.topo = -1;
                return 0;
            }
            float b = desempilhaN(&pilha);
            float a = desempilhaN(&pilha);
            if (b == 0) {
                printf("ERRO: Divisao por zero!\n");
                pilha.topo = -1;
                return 0;
            }
            empilhaN(&pilha, a / b);

        } else if (strcmp(token, "%") == 0) {
            if(pilha.topo < 1) {
                printf("ERRO: Operadores insuficientes!\n");
                pilha.topo = -1;
                return 0;
            }
            float b = desempilhaN(&pilha);
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, fmod(a, b));

        } else if (strcmp(token, "^") == 0) {
            if(pilha.topo < 1) {
                printf("ERRO: Operadores insuficientes!\n");
                pilha.topo = -1;
                return 0;
            }
            float b = desempilhaN(&pilha);
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, pow(a, b));

        } else if (strcmp(token, "sen") == 0) {
            if(pilha.topo < 0) {
                printf("ERRO: Expressao invalida!\n");
                pilha.topo = -1;
                return 0;
            }
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, sin(a * M_PI / 180.0));

        } else if (strcmp(token, "cos") == 0) {
            if(pilha.topo < 0) {
                printf("ERRO: Expressao invalida!\n");
                pilha.topo = -1;
                return 0;
            }
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, cos(a * M_PI / 180.0));

        } else if (strcmp(token, "tg") == 0) {
            if(pilha.topo < 0) {
                printf("ERRO: Expressao invalida!\n");
                pilha.topo = -1;
                return 0;
            }
            float a = desempilhaN(&pilha);
            empilhaN(&pilha, tan(a * M_PI / 180.0));

        } else if (strcmp(token, "raiz") == 0) {
            if(pilha.topo < 0) {
                printf("ERRO: Expressao invalida!\n");
                pilha.topo = -1;
                return 0;
            }
            float a = desempilhaN(&pilha);
            if (a < 0) {
                printf("ERRO: Raiz quadrada de numero negativo!\n");
                pilha.topo = -1;
                return 0;
            }
            empilhaN(&pilha, sqrt(a));

        } else if (strcmp(token, "log") == 0) {
            float a = desempilhaN(&pilha);
            if (a <= 0) {
                printf("ERRO: Logaritmo de numero negativo!\n");
                pilha.topo = -1;
                return 0;
            }
            empilhaN(&pilha, log10(a));
        }

        token = strtok(NULL, " ");
    }
    if (pilha.topo != 0) {
        printf("ERRO: Expressao invalida!\n");
        return 0;
    }

    return desempilhaN(&pilha);
}

char * getFormaInFixa(char *Str) {
    PilhaS pilha;
    pilha.topo = -1;

    char copia [512];
    strcpy(copia, Str);

    char *token = strtok(copia, " ");
    while (token != NULL) {
        char *endptr;
        strtof(token, &endptr);

        if(*endptr == '\0' && endptr != token) {
            empilhaS(&pilha, token);

        } else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
                   strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
                   strcmp(token, "%") == 0 || strcmp(token, "^") == 0) {

            if(pilha.topo < 1) {
                printf("ERRO: Expressao invalida!\n");
                return NULL;
            }

            char b[512], a[512], res[512];
            strcpy(b, desempilhaS(&pilha));
            strcpy(a, desempilhaS(&pilha));

            sprintf(res, "(%s%s%s)", a, token, b);
            empilhaS(&pilha, res);

        } else if (strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 ||
                   strcmp(token, "tg") == 0 || strcmp(token, "raiz") == 0 ||
                   strcmp(token, "log") == 0) {

            if(pilha.topo < 0) {
                printf("ERRO: Expressao invalida!\n");
                return NULL;
            }

            char a[512], res[512];
            strcpy(a, desempilhaS(&pilha));

            sprintf(res, "%s(%s)", token, a);
            empilhaS(&pilha, res);

        } else {
            printf("ERRO: Token desconhecido '%s'!\n", token);
            return NULL;
        }

        token = strtok(NULL, " ");
    }

    if(pilha.topo == 0){
        char *finalStr = pilha.itens[pilha.topo];
        int len = strlen(finalStr);
        if(len > 2 && finalStr[0] == '(' && finalStr[len - 1] == ')') {
            finalStr[len - 1] = '\0';
            return strdup(finalStr + 1);
        }
        return strdup(finalStr);
    }

    return NULL;
}