#include <stdio.h>

int main() {
    int matrix[2][2];
    int valueRow = 1;
    int valueCol = 1;
    int row = 1;
    int col = 1;


    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%s", "Insira um numero inteiro: ");
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("%s", "Escolha uma linha da matriz (0-1): ");
    scanf("%d", &row);

    printf("%s", "Escolha o multiplicador: ");
    scanf("%d", &valueRow);

    for(int i = 0; i < 2; i++)
        matrix[row][i] = matrix[row][i] * valueRow;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("%s", "Escolha uma coluna da matriz (0-1): ");
    scanf("%d", &col);

    printf("%s", "Escolha o multiplicador: ");
    scanf("%d", &valueCol);

    for(int i = 0; i < 2; i++)
        matrix[i][col] = matrix[i][col] * valueCol;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}