## Vitor Leandro Machado | 10409358 / Rodrigo Lucas Rosales | 10365071 / Gabriel Forster Souza | 10409702 / Rodrigo Mello de Campos Silva | 10409316

Nesta branch, será incluida o código utilizado para a realização do exercicio Lab03_A!

## ENUNCIADO:

Na linguagem C, em sistemas Linux a criação de uma thread pode ser feita executando uma chamada à função clone()

clone()

Faz uma cópia compartilhada do processo (similar ao fork) mas mantém uma área de memória compartilhada.

Em sistemas Linux utilizamos o termo task para se referir a processos e threads. A principal diferença é o tipo de recurso que será compartilhado.

![clone](https://github.com/TshadowBR/Laboratorio-1-Sistemas-Operacionais/assets/32850196/f1ff67e7-e79a-4430-8470-42001fbd01f7)

O trecho abaixo apresenta uma criação de thread no Linux:


![Captura de tela 2024-05-01 192920](https://github.com/TshadowBR/Laboratorio-1-Sistemas-Operacionais/assets/32850196/d6a7a1d8-7edf-407c-a8dc-445f333c3b96)

EXERCÍCIO: Incremente o exemplo acima para representar a troca de informações de contexto entre a thread e o processo pai.


LINK DO CÓDIGO: https://github.com/TshadowBR/Laboratorio-1-Sistemas-Operacionais/blob/Lab03a/Lab03_A.c

## EXPLICAÇÃO:

Esse código em C cria uma thread usando a função clone() do Linux. Aqui está um resumo do funcionamento do código:
1. Inclui as bibliotecas necessárias.
2. Define o tamanho da pilha para a thread (FIBER_STACK).
3. Define a estrutura ThreadArgs para passar dados entre a thread pai e a thread filha.
4. Define a função threadFunction, que é a função que a thread filha executará.
5. No main():
     *  Aloca a pilha para a thread filha.
     *  Inicializa a estrutura ThreadArgs com os dados que serão passados para a thread filha.
     *  Usa a função clone() para criar a thread filha. Esta função recebe como argumentos:
     *  Ponteiro para a função que a thread filha executará.
     *  Ponteiro para a pilha da thread filha.
     *  Flags para definir os recursos que serão compartilhados com a thread pai.
     *  Ponteiro para os argumentos da função da thread filha.
     *  Aguarda a finalização da thread filha usando waitpid().
     *  Libera a pilha alocada para a thread filha.
     *  Imprime os dados retornados pela thread filha.

Em resumo, o programa cria uma thread filha que multiplica os dados passados por 2 e os retorna para a thread pai.

## EXECUÇÃO DO CÓDIGO:

![Captura de tela 2024-05-01 194131](https://github.com/TshadowBR/Laboratorio-1-Sistemas-Operacionais/assets/32850196/711a5486-f3fc-4341-bd76-fd2a84c04a09)
