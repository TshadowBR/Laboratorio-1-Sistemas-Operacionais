#Projeto 1 Sistemas Operacionais

## Vitor Leandro Machado | 10409358 / Rodrigo Lucas Rosales | 10365071 / Gabriel Forster Souza | 10409702 / Rodrigo Mello de Campos Silva | 10409316

## Como compilar o programa 
#Instalar GCC
sudo apt-get install gcc -y

#Passo a Passo
- cd caminho/para/o/arquivo
- gcc -o nomeDoArquivoParaExecutar projeto1.c #nomeDoArquivoParaExecutar pode ser definido por voce!

## Executar o programa
- Após compilar o programa usar o comando ./nomeDoArquivoParaExecutar

O código usa um “mutex” para garantir que a função de transferência não seja acessada simultaneamente por várias threads. Além disso, o código consome várias chamadas de sistema, como clone, malloc e free, para gerenciar processos e memória. O uso dessas chamadas de sistema é otimizado, pois clone é usado com flags que especificam o que deve ser compartilhado com o processo filho, e malloc e free são usados para alocar e desalocar memória conforme necessário.
