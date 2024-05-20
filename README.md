#Repositório Lab Sistemas Operacionais

## Vitor Leandro Machado | 10409358 / Rodrigo Lucas Rosales | 10365071 / Gabriel Forster Souza | 10409702 / Rodrigo Mello de Campos Silva | 10409316

## Como encontrar atividades

Cada atividade está em sua própria branch. Basta selecionar a branch de uma atividade para visualizar o readme e arquivos respectivos.

## PROJETO 2
NESSA BRANCH ENCONTRA-SE O PROJETO 2

## Resumo do Código:

Leitura de Dados:

Lê o número de pessoas N.
Para cada pessoa, lê o tempo t[i] de chegada e a direção d[i] desejada (0 para esquerda-direita, 1 para direita-esquerda).
Simulação da Escada Rolante:

Inicializa o tempo atual current_time como 0 e a direção direction como -1 (indicando que a escada está parada).
Para cada pessoa:
Se a pessoa chega quando a escada está parada ou antes do tempo atual (current_time <= t[i]), a escada começa a se mover na direção desejada pela pessoa e o tempo atual é atualizado para t[i] + 10.
Se a pessoa chega quando a escada já está se movendo (current_time > t[i]):
Se a direção é a mesma, a pessoa entra imediatamente e o tempo atual é incrementado em 10.
Se a direção é diferente, a pessoa espera a escada parar e começar na nova direção, atualizando o tempo atual para t[i] + 10.
Resultado Final:

Imprime current_time, que é o último momento em que a escada rolante está ativa.
