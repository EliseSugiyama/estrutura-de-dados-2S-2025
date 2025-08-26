#ifndef EQUIPE_H
#define EQUIPE_H

typedef struct {
    int Pos; //Posição final da equipe no CB2024 (Campeonato Brasileiro)
    char Estado[30];
    char Equipe[50];
    int Pontos; 
    int Jogos;
    int Vitoria;
    int Empate;
    int Derrota;
    int GolsPro;
    int GolsContra;
    int SaldoGols;
    float Aproveitamento; 

} Time; 

Time * LerDados(char  * Arquivo);

#endif