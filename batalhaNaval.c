#include <stdio.h>

int main() {
    int tabuleiro[5][5] = {0};

    // Posiciona navio horizontalmente na linha 2, colunas 1-3
    int linha_2 = 1; // linha 2 (índice 1)
    for (int j = 0; j < 3; j++) {
        tabuleiro[linha_2][j] = 1;
        printf("Navio horizontal: (%d, %d)\n", linha_h + 1, j + 1);
    }

    // Posiciona navio verticalmente na coluna 5, linhas 3-5
    int coluna_e = 4; // coluna 5 (índice 4)
    for (int i = 2; i < 5; i++) {
        tabuleiro[i][coluna_e] = 2;
        printf("Navio vertical: (%d, %d)\n", i + 1, coluna_v + 1);
    }

    return 0;
}
