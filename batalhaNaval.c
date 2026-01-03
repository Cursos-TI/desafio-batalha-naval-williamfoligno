#include <stdio.h>

int main() {

    // TABULEIRO
    int tabuleiro[10][10];
    int i, j;

    // água
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[2][2 + i] = 3;
    }

    // Navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[5 + i][6] = 3;
    }

    //HABILIDADE - CONE (5x5)
    int cone[5][5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    //cone no tabuleiro
    int origemConeLinha = 1;
    int origemConeColuna = 4;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int linhaTab = origemConeLinha + i;
                int colunaTab = origemConeColuna + j;

                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    //HABILIDADE - CRUZ (5x5)
    int cruz[5][5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    //cruz no tabuleiro
    int origemCruzLinha = 6;
    int origemCruzColuna = 2;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int linhaTab = origemCruzLinha + i;
                int colunaTab = origemCruzColuna + j;

                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    //HABILIDADE - OCTAEDRO (5x5)
    int octaedro[5][5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if ( (i + j >= 2) && (i + j <= 6) && (j - i <= 2) && (i - j <= 2) )
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    //octaedro no tabuleiro
    int origemOctLinha = 3;
    int origemOctColuna = 6;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int linhaTab = origemOctLinha + i;
                int colunaTab = origemOctColuna + j;

                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    // EXIBE O TABULEIRO
    printf("Tabuleiro Final:\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}