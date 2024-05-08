#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

typedef struct reg celula;

struct reg {
  int conteudo;
  celula *prox;
};

void remover_elemento(celula **p) {
  if (*p == NULL) {
    return;
  }

  celula *aux = *p;
  *p = (*p)->prox;
  free(aux);

  printf("Elemento removido!\n");
}

void imprimir(celula *p) {
  printf("Valores da função imprimir: ");
  while (p != NULL) {
    printf("%d ", p->conteudo);
    p = p->prox;
  }
}

int max_elementos() {
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);

  long memoria_usada = usage.ru_maxrss;
  int tamanho_celula = sizeof(int) + sizeof(celula *);

  return memoria_usada / tamanho_celula;
}

int main() {
  // Allocate memory for the cells using malloc
  celula *c1 = (celula *)malloc(sizeof(celula));
  celula *c2 = (celula *)malloc(sizeof(celula));
  celula *c3 = (celula *)malloc(sizeof(celula));

  if (c1 == NULL || c2 == NULL || c3 == NULL) {
    printf("Erro: Memória insuficiente para alocar células!\n");
    return 1;
  }

  // Assign values and link the cells
  c1->conteudo = 10;
  c1->prox = NULL;

  c2->conteudo = 20;
  c2->prox = c1;

  c3->conteudo = 30;
  c3->prox = c2;

  imprimir(c3);

  int tamanho_celula = sizeof(int) + sizeof(celula *);
  printf("\nTamanho da célula: %d bytes\n", tamanho_celula);

  remover_elemento(&c3);

  imprimir(c2);

  printf("\nMemória disponível: %d", max_elementos());

  return 0;
}
