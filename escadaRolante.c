#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int t[N], d[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &t[i], &d[i]);
    }

    int current_time = 0;
    int direction = -1; // -1 significa que a escada rolante está inicialmente parada

    for (int i = 0; i < N; i++) {
        if (current_time <= t[i]) {
            // Se a escada rolante está parada ou a pessoa pode entrar imediatamente
            current_time = t[i] + 10;
            direction = d[i];
        } else {
            // A pessoa tem que esperar até que a escada rolante esteja disponível
            if (direction == d[i]) {
                // Mesma direção, a pessoa pode entrar imediatamente
                current_time += 10;
            } else {
                // Direção diferente, a pessoa tem que esperar até a escada parar e mudar de direção
                current_time = t[i] + 10;
                direction = d[i];
            }
        }
    }

    printf("%d\n", current_time);
    return 0;
}
