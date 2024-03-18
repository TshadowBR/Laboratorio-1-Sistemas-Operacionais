### Lab 2

Processos – Criacão e comunicacão

Código utilizado para resposta nas questões 1 e 2.
---

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    pid_t childpid = 0;
    int i, n;
    
    if (argc != 2){ /* check for valid number of command-line arguments */
    fprintf(stderr, "Usage: %s processes\n", argv[0]);
    return 1;
    }
    
    n = atoi(argv[1]);
    for (i = 1; i < n; i++)
    if (childpid = fork())
    break;
    fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
    i, (long)getpid(), (long)getppid(), (long)childpid);
    
    return 0;
}
---

### Questão 1 - Rode o programa anterior para valores grandes de n. As mensagens sempre estarão ordenadas pelo valor de i?

Resp: As mensagens não estarão necessariamente ordenadas pelo valor de 'i'. Ao executarmos e observamos o programa, chegamos a conclusão de o que determina a ordem das mensagens é a ordem em que os processos são concluídos e escrevem sua saída. Ao executarmos o programa para para valores grandes de n, múltiplos processos filho são criados e executados concorrentemente. No entanto, as mensagens impressas dependerá da ordem em que os processos filhos terminam sua execução. 


### Questão 2 - O que acontece se o programa anterior escreve-se as mensagens para sys.stdout, usando print, ao inv´es de para sys.stderr?

Resp: Se utilizássemos print para escrever as mensagens em sys.stdout em vez de sys.stderr, a saída poderia ser bufferizada e seria redirecionada junto com a saída regular do programa.
