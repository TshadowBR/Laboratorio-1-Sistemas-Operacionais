#include <stdio.h>

int main() {
    int maxNum;

    printf("%s", "Insira um numero impar (max 13): ");
    scanf("%d", &maxNum);

    int end = maxNum;
    int rows = (maxNum / 2) + 1;
    int start = 1;
    int count = 1;
    int spaces = 1;


    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < maxNum; j++) {

            if (count >= start && count <= end) {
                printf("%d", count);
            }
            if (count < end) {
                printf("%s", " ");
            }
            count++;
        }


        count = 1;
        start++;
        end--;

        printf("\n");

        for (int k = 0; k < spaces; k++) {
            printf("%s", " ");
        }

        spaces++;
    }
}