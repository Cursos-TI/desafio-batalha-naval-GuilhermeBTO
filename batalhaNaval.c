#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10

int main() {
    int matriz[LINHAS][COLUNAS] = {0};
    
    //navio na horizontal
    int linha_navio1 = 7;   // indice 7, 8 linha
    int coluna_navio1 = 2;   // coluna C
    int tamanho_navio1 = 3;
 
    for (int i = linha_navio1; i < linha_navio1 + tamanho_navio1; i++) {
        for (int j = coluna_navio1; j < coluna_navio1 + tamanho_navio1; j++) {
            matriz[linha_navio1][j] = 3; // parte do navio.
        }
    }

     //navio na vertical
    int linha_navio2 = 0;   // indice 0, 1 linha
    int coluna_navio2 = 9;   // coluna J
    int tamanho_navio2 = 3;
 
    for (int i = linha_navio2; i < linha_navio2 + tamanho_navio2; i++) {
        for (int j = coluna_navio2; j < coluna_navio2 + tamanho_navio2; j++) {
            matriz[i][coluna_navio2] = 3; // parte do navio.
        }
    }

    //navio na diagonal da esquerda para direita descendo
    int linha_navio3 = 5;   // indice 5, 6 linha
    int coluna_navio3 = 6;   // coluna F
    int tamanho_navio3 = 3;
 
    for (int i = 0; i < tamanho_navio3; i++) {
        matriz[linha_navio3 + i][coluna_navio3 + i] = 3; // parte do navio.
    } 
    
    //navio na diagonal da direita para esquerda descendo
    int linha_navio4 = 1;   // indice 3, 4 linha
    int coluna_navio4 = 3;   // coluna C
    int tamanho_navio4 = 3;
 
    for (int i = 0; i < tamanho_navio4; i++) {
        matriz[linha_navio4 + i][coluna_navio4 - i] = 3; // parte do navio, atribuindo valor à matriz.
    }   
    
    //exibição da matriz completa
    for (int i = 0; i < LINHAS; i++ ) {
        for (int j = 0; j < COLUNAS; j++) {
        printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
