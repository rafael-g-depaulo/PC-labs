### 1.1.1. Implementação do Hello Threads
Arquivo implementado em *hello-thread.c*

### 1.1.2. Execute o programa implementado no topico anterior diversas vezes e elenque os motivos os quais as saídas entre execuçoes são diferentes entre si.
Depois de compilar e executar o programa 100 (cem) vezes com os comandos:

```
gcc -o t hello-thread.c -lpthread
for i in {1..100}; do ./t | grep thread; done
```

Foram notados 2 casos da string "Olá, eu sou uma thread" aparecerem no terminal, das 100000 vezes em que o programa foi executado. Isso se dá por causa da thread principal, quase todas as vezes, terminar de executar (e portanto encerrar o programa) antes das threads filhas terminarem de ser criadas e executadas, e pela natureza não reentrante da função *printf*.

### 2.1.1. Divisão de tarefas
O código para a execução da tarefa está implementado no arquivo *divisao-tarefas.c*, e foi compilado e executado com os comandos:
```
gcc -o t divisao-tarefas.c -lpthread -lm
./t
```

### 3.1.1. Iterações entre Threads
O código para a execução da tarefa está implementado no arquivo *contador.c*, e foi compilado e executado com os comandos:

```
gcc -o t contador.c -lpthread
./t
```

### 3.1.1. Escalonador

O código para a execução da tarefa está implementado no arquivo *escalonador.c*, e foi compilado e executado com os comandos:

```
gcc -o t escalonador.c -lpthread
./t
```

### 4.1.1 Questionário
De maneira analoga a demonstrada entre threads, variaveis globais podem compartilhar informações em tempo de execução entre dois processos diferentes, onde um dos processos foi criado pela chamada fork do primeiro? Por que?