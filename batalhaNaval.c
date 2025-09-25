#include <stdio.h>

#define TAM_TABULEIRO 10   // tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3        // tamanho fixo dos navios
#define AGUA 0             // valor para água
#define NAVIO 3            // valor para navio

int main() {
    // tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Definição das coordenadas iniciais dos navios
    // (linha, coluna) -> índices começam em 0
    int linhaNavioHorizontal = 2; 
    int colunaNavioHorizontal = 4;  

    int linhaNavioVertical = 5;  
    int colunaNavioVertical = 7;  

    // Posicionando navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        // valida se está dentro dos limites do tabuleiro
        if (colunaNavioHorizontal + i < TAM_TABULEIRO) {
            // evita sobreposição
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == AGUA) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = NAVIO;
            }
        }
    }

    // Posicionando navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        // valida se está dentro dos limites do tabuleiro
        if (linhaNavioVertical + i < TAM_TABULEIRO) {
            // evita sobreposição
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == AGUA) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = NAVIO;
            }
        }
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
