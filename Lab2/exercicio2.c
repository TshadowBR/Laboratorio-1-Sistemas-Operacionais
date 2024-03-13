#include <stdio.h>

char* define_nota(float media){
    char* nota_letra;

    if (media >= 9.0) nota_letra =  "A";
    else if (media >= 7.5 && media < 9.0) nota_letra = "B";
    else if (media >= 6.0 && media < 7.5) nota_letra = "C";
    else if (media >= 4.0 && media < 6.0) nota_letra = "D";
    else nota_letra = "E";

    return nota_letra;
}

float calcula_media(int n1, int n2, int n3){
    float media;
    media = (n1 + n2*2 + n3*3 + 10)/7.0;
    return media;
}

void main(){
    int n1, n2, n3;

    int cont = 1;
    while (cont <= 3){
        int nota;
        printf("Digite sua %dº nota: ", cont);
        scanf("%d", &nota);

        if (cont == 1) n1 = nota;
        if (cont == 2) n2 = nota;
        if (cont == 3) n3 = nota;

        cont = cont + 1;
    }

    float media = calcula_media(n1, n2, n3);

    char* nota_letra = define_nota(media);
    
    printf("Sua nota final é: %s\n", nota_letra);
    printf("Sua média final é igual a: %.2f\n", media);
}