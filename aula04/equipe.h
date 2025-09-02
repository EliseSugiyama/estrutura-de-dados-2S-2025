#ifndef EQUIPE_H
#define EQUIPE_H

//Definição o TAD equipe 
 
#define ERRO -999

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
    float Aproveitamento; // % de pontos conquistados

} Time; 

Time * LerDados(char  * Arquivo); //retornar vetor de equipe
int getPontos(Time * T, int Posicao); 
float getAproveitamento(Time * T, char * Nome);

#endif