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

O primeiro programa utiliza um algoritmo visto em aula para calcular Pi. O uso de Threads faz com que a tarefa seja completa em menos tempo, já que mais de uma thread pode estar ativa simultaneamente. O segundo programa adiciona Mutex, que torna a espera de threads para acesso de recursos mais controlada e mais eficiente. Assim, os tempos de espera e execução são ainda menores.

## Execução do Programa

### Sem Mutex

![image](https://github.com/TshadowBR/Laboratorio-1-Sistemas-Operacionais/assets/53952323/1cf2c45a-b93a-403e-896b-f34544838f3a)

### Com Mutex
