#include <stdio.h>

#define TAM_TABULEIRO 10   // tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3        // tamanho fixo dos navios
#define AGUA 0             // valor para água
#define NAVIO 3            // valor para navio

// Função auxiliar para posicionar navio horizontal ou vertical
void posicionaNavioLinear(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                          int linha, int coluna, int orientacao) {
    // orientacao: 0 = horizontal, 1 = vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (orientacao == 0) { // horizontal
            if (coluna + i < TAM_TABULEIRO && tabuleiro[linha][coluna + i] == AGUA) {
                tabuleiro[linha][coluna + i] = NAVIO;
            }
        } else { // vertical
            if (linha + i < TAM_TABULEIRO && tabuleiro[linha + i][coluna] == AGUA) {
                tabuleiro[linha + i][coluna] = NAVIO;
            }
        }
    }
}

// Função auxiliar para posicionar navio diagonal
void posicionaNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                            int linha, int coluna, int direcao) {
    // direcao: 0 = diagonal principal (↘), 1 = diagonal secundária (↙)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 0) { // ↘ linha++, coluna++
            if (linha + i < TAM_TABULEIRO && coluna + i < TAM_TABULEIRO &&
                tabuleiro[linha + i][coluna + i] == AGUA) {
                tabuleiro[linha + i][coluna + i] = NAVIO;
            }
        } else { // ↙ linha++, coluna--
            if (linha + i < TAM_TABULEIRO && coluna - i >= 0 &&
                tabuleiro[linha + i][coluna - i] == AGUA) {
                tabuleiro[linha + i][coluna - i] = NAVIO;
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimeTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // tabuleiro inicializado com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // === Posicionamento dos quatro navios ===
    // Dois lineares (horizontal e vertical)
    posicionaNavioLinear(tabuleiro, 2, 1, 0); // horizontal (linha 2, coluna inicial 1)
    posicionaNavioLinear(tabuleiro, 5, 6, 1); // vertical   (linha 5, coluna 6)

    // Dois diagonais
    posicionaNavioDiagonal(tabuleiro, 0, 0, 0); // diagonal ↘ (começa no canto superior esquerdo)
    posicionaNavioDiagonal(tabuleiro, 3, 9, 1); // diagonal ↙ (começa na linha 3, coluna 9)

    // Exibir tabuleiro
    imprimeTabuleiro(tabuleiro);

    return 0;
}
