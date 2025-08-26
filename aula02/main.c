#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

#include "fracao.h"

int main() {

    system("cls");

    Fracao F1 = criarFracao(24, 30);
    F1 = simplificarFracao(F1);
    exibirFracao(F1); //Deve ser exibido 4/5

    Fracao F2 = criarFracao(-30, 40);
    F2 = simplificarFracao(F2);
    exibirFracao(F2); //Deve ser exibido -3/4

    Fracao F3 = criarFracao(37, 42);
    F3 = simplificarFracao(F3);
    exibirFracao(F3); //Deve ser exibido 37/42

    Fracao F4 = criarFracao(5, 6);
    Fracao F5 = criarFracao(4, 9);
    Fracao F6 = somarFracoes(F4, F5);
    exibirFracao(F6); //Deve ser exibido 23/18

    Fracao F7 = subtrairFuncoes(F4, F5); 
    exibirFracao(F7); //Deve ser exibido 7/18

    Fracao F8 = criarFracao(3, 4);
    Fracao F9 = criarFracao(7, 9);
    Fracao F10 = criarFracao (5, 12);
    Fracao F11 = subtrairFuncoes(F8, F9);
    Fracao F12 = somarFracoes(F11, F10);
    F12 = simplificarFracao(F12); 
    exibirFracao(F12); //Deve ser exibido 7/18

    return 0;
}
