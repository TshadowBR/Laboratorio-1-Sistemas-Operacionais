#include <stdio.h>

int main() {
    int matrix[2][2];
    int n;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%s", "Insira um numero inteiro: ");
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            n = n < matrix[i][j] ? n : matrix[i][j];
        }
    }

    printf("%s", "O menor numero inserido eh: ");
    printf("%d", n);
}