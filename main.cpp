#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <stdio.h>

using namespace std;

int soma_diagonal_principal;
int soma_diagonal_secundaria;

void mostra_tabuleiro(char tabuleiro [3][3]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout << "|" <<tabuleiro[i][j] << "|";
        }
        cout << "\n";
    }
}
void faca_jogo_x(int jogada_x, int tabuleiro_calculo[3][3], char tabuleiro [3][3]){
    switch(jogada_x){
        case 1:
            tabuleiro [0][0] = 'X';
            tabuleiro_calculo [0][0] = 1;
            break;
        case 2:
            tabuleiro [0][1] = 'X';
            tabuleiro_calculo [0][1] = 1;
            break;
        case 3:
            tabuleiro [0][2] = 'X';
            tabuleiro_calculo [0] [2] = 1;
            break;
        case 4:
            tabuleiro [1][0] = 'X';
            tabuleiro_calculo [1][0] = 1;
            break;
        case 5:
            tabuleiro [1][1] = 'X';
            tabuleiro_calculo [1][1] = 1;
            break;
        case 6:
            tabuleiro [1][2] = 'X';
            tabuleiro_calculo [1][2] = 1;
            break;
        case 7:
            tabuleiro [2][0] = 'X';
            tabuleiro_calculo [2][0] = 1;
            break;
        case 8:
            tabuleiro [2][1] = 'X';
            tabuleiro_calculo [2][1] = 1;
            break;
        case 9:
            tabuleiro [2][2] = 'X';
            tabuleiro_calculo [2][2] = 1;
            break;
        }
}
void faca_jogo_o(int jogada_o, int tabuleiro_calculo[3][3], char tabuleiro [3][3]){
    switch(jogada_o){
        case 1:
            tabuleiro [0][0] = 'O';
            tabuleiro_calculo [0][0] = -1;
            break;
        case 2:
            tabuleiro [0][1] = 'O';
            tabuleiro_calculo [0][1] = -1;
            break;
        case 3:
            tabuleiro [0][2] = 'O';
            tabuleiro_calculo [0][2] = -1;
            break;
        case 4:
            tabuleiro [1][0] = 'O';
            tabuleiro_calculo [1][0] = -1;
            break;
        case 5:
            tabuleiro [1][1] = 'O';
            tabuleiro_calculo [1][1] = -1;
            break;
        case 6:
            tabuleiro [1][2] = 'O';
            tabuleiro_calculo [1][2] = -1;
            break;
        case 7:
            tabuleiro [2][0] = 'O';
            tabuleiro_calculo [2][0] = -1;
            break;
        case 8:
            tabuleiro [2][1] = 'O';
            tabuleiro_calculo [2][1] = -1;
            break;
        case 9:
            tabuleiro [2][2] = 'O';
            tabuleiro_calculo [2][2] = -1;
            break;
    }
}
void verifica_jogo(int tabuleiro_calculo[3][3], int soma, int soma_colunas[3], int soma_linhas[3]){
    soma_diagonal_principal = 0;
    soma_diagonal_secundaria = 0;
    for(int i=0;i<3;i++){
        soma = 0;
        for(int j=0;j<3;j++){
            soma += tabuleiro_calculo[i][j];
        }
        soma_linhas[i] = soma;
    }
    for(int j=0;j<3;j++){
        soma = 0;
        for(int i=0;i<3;i++){
            soma += tabuleiro_calculo[i][j];
        }
        soma_colunas[j] = soma;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j){
                soma_diagonal_principal += tabuleiro_calculo[i][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j == 3 - i - 1){
                soma_diagonal_secundaria += tabuleiro_calculo[i][3 - 1 - i];
            }
        }
    }
}

int main()
{
    setlocale (LC_ALL, "Portuguese");

    string jogador_x, jogador_o;
    int resposta;
    int placar_x , placar_o;
    int inicio_jogo = 0;
    srand(time(NULL));

    do{
        fflush(stdin);
        placar_x = 0;
        placar_o = 0;
        cout << "Nome jogador (X):\n";
        getline(cin, jogador_x);
        cout << "Nome jogador (O):\n";
        getline(cin, jogador_o);
        system("cls");
        do{
            char tabuleiro [3][3] = {'1','2','3','4','5','6','7','8','9'};
            int tabuleiro_calculo [3][3] = {0,0,0,0,0,0,0,0,0};
            int contador = 0, soma;
            int jogada_x, jogada_o;
            int jogo_invalido = 0;
            int soma_colunas[3], soma_linhas[3], memoria[9];

            do{
                inicio_jogo = 1+rand()%2;
            }
            while(inicio_jogo <1 || inicio_jogo >2);
            do{
                if(contador<9){
                    if(inicio_jogo==1 || inicio_jogo==0){
                        do{
                            inicio_jogo = 0;
                            jogo_invalido = 0;
                            mostra_tabuleiro(tabuleiro);
                            cout << jogador_x << " sua vez:";
                            cin >>jogada_x;
                            system("cls");
                            memoria[contador]=jogada_x;
                            for(int i=-1;i<contador;i++){
                                if(jogada_x == memoria[i] || jogada_x<1 || jogada_x>9){
                                    cout << "Jogada invalida!!\n";
                                    jogo_invalido = 1;
                                    break;
                                }
                            }
                        }
                        while(jogo_invalido==1);
                        faca_jogo_x(jogada_x,tabuleiro_calculo,tabuleiro);
                        contador++;
                        verifica_jogo(tabuleiro_calculo, soma, soma_colunas, soma_linhas);
                        if(soma_diagonal_principal==3 || soma_diagonal_secundaria==3 || soma_colunas[0]==3 || soma_colunas[1]==3 || soma_colunas[2]==3 || soma_linhas[0]==3 || soma_linhas[1]==3 || soma_linhas[2]==3){
                            cout << jogador_x << " venceu!!\n\n";
                            placar_x++;
                           break;
                        }
                    }
                }
                system("cls");
                if(contador<9){
                    if(inicio_jogo==2 || inicio_jogo==0){
                        do{
                            inicio_jogo = 0;
                            jogo_invalido = 0;
                            mostra_tabuleiro(tabuleiro);
                            cout << jogador_o << " sua vez:";
                            cin >>jogada_o;
                            system("cls");
                            memoria[contador]=jogada_o;
                            for(int i=0;i<contador;i++){
                                if(jogada_o == memoria[i] || jogada_o<1 || jogada_o>9){
                                    cout << "Jogada invalida!!\n";
                                    jogo_invalido = 1;
                                    break;
                                }
                            }
                        }
                        while(jogo_invalido==1);
                        faca_jogo_o(jogada_o,tabuleiro_calculo,tabuleiro);
                        contador++;
                        verifica_jogo(tabuleiro_calculo, soma, soma_colunas, soma_linhas);

                        if(soma_diagonal_principal==-3 || soma_diagonal_secundaria==-3 || soma_colunas[0]==-3 || soma_colunas[1]==-3 || soma_colunas[2]==-3 || soma_linhas[0]==-3 || soma_linhas[1]==-3 || soma_linhas[2]==-3){
                           cout << jogador_o << " venceu!!\n\n";
                           placar_o++;
                        break;
                        }
                    }
                }
                if(contador==9){
                    cout << "Deu velha!!!\n\n";
                }
            }
            while(contador<9);
            mostra_tabuleiro(tabuleiro);
            cout << "\n---PLACAR---\n";
            cout << jogador_x << ": " << placar_x << endl;
            cout << jogador_o << ": " << placar_o << endl;
            do{
                cout << "\n\nDeseja jogar novemente?\n1 - Sim\n2 - Não\n3 - Trocar jogador\n";
                cin >> resposta;
                system("cls");
            }
            while(resposta!=1 && resposta!=2 && resposta!=3);
            system("cls");
        }
        while(resposta==1);
    }
    while(resposta==3);
    cout << "\nFinalizado pelo jogador!!!\n";

    return 0;
}
