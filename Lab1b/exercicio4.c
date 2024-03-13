#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* to_lowerCase(char* nome)
{
    int len = strlen(nome);

    for (int i = 0; i < len; i++) {
        nome[i] = tolower(nome[i]);
    }

    return nome;
}

void main() {
    char nome1[50], nome2[50];

    // Leitura do primeiro nome
    printf("Digite o primeiro nome: ");
    scanf("%s", nome1);
    nome1[strcspn(nome1, "\n")] = '\0';

    // Leitura do segundo nome
    printf("Digite o segundo nome: ");
    scanf("%s", nome2);
    nome2[strcspn(nome2, "\n")] = '\0';

    if (strcmp(to_lowerCase(nome1), to_lowerCase(nome2)) < 0) 
        printf("Nomes ordenados: %s, %s\n", nome1, nome2);
    else 
        printf("Nomes ordenados: %s, %s\n", nome2, nome1);
}