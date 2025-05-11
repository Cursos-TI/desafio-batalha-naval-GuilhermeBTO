#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};
        
    // Exemplo de navio na horizontal
    for (int j = 2; j < 5; j++) {
        tabuleiro[7][j] = 3;
    }
    // Exemplo de navio na vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9] = 3;
    }
    // Exemplo de navio na diagonal principal
    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][6 + i] = 3;
    }  
    
    // HABILIDADE do tipo CONE (3x3)
    int Cone[3][3] = {0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j >= 1 - i && j <= 1 + i){
                Cone[i][j] = 1;
            }
        }
    }
    // MATRIZ do tipo CRUZ (3x3)
    int Cruz[3][3] = {0};
    for(int i = 0; i < 3; i++){
        Cruz[1][i] = 1;
        Cruz[i][1] = 1;
    }

    // HABILIDADE do tipo Losango (5x5)
    int Losango[5][5] = {0};
    for(int i = 0; i < 5; i++){
        int inicio = 2 - (i < 3 ? i : 4 - i);
        int fim = 2 + (i < 3 ? i : 4 - i);
        for(int j = inicio; j <= fim; j++){
            Losango[i][j] = 1;
        }
    }

    // Sobrepor Cone no centro superior do tabuleiro (posição 1,1)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // Só sobrepõe se for água
            if(Cone[i][j] == 1 && tabuleiro[i+1][j+1] == 0){
                tabuleiro[i+1][j+1] = 5;
            }
        }
    }
    // Sobrepor Cruz no centro do tabuleiro (posição 4,4)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // Só sobrepõe se for água
            if(Cruz[i][j] == 1 && tabuleiro[i+4][j+4] == 0){
                tabuleiro[i+4][j+4] = 5;
            }
        }
    }
    // Sobrepor Losango no canto inferior direito (posição 6,6)
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            // Só sobrepõe se for água
            int lin = i+6-2;
            int col = j+6-2;
            if(Losango[i][j] == 1 && lin >= 0 && lin < LINHAS && col >= 0 && col < COLUNAS && tabuleiro[lin][col] == 0){
                tabuleiro[lin][col] = 5;
            }
        }
    }

    // Exibir o tabuleiro
    printf("\nTabuleiro:\n");
    printf("Legendas: Navio - N, Agua - ~, Habilidade - *\n");
    printf("\n"); // para pular linha
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            if(tabuleiro[i][j] == 0)
                printf(" ~ ");
            else if(tabuleiro[i][j] == 3)
                printf(" N ");
            else if(tabuleiro[i][j] == 5)
                printf(" * ");
        }
        printf("\n");
    }
    return 0;
}
