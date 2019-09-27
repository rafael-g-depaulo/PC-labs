## Relatório

### 1.1.1.

Código implementado em *incremento.c*, e compilado e executado com

```gcc -o t incremento.c -lpthread
./t
```

### 1.1.2. Qual o problema do codigo anterior? Se há algum problema, ele acontece sempre? Por quê?

Nesse exemplo de código, o problema observado é que embora a variável seja compartilhada entre todas as *threads*, pode ocorrer de que duas ou mais *threads* incrementem a variável ao mesmo tempo. Como cada uma recebe a variável com um valor arbitrário X, ao termino de cada uma delas o novo valor da variável será X+1, mesmo que duas *threads* tenham incrementado.

O problema não acontece sempre, porque depende do escalonador do *SO* a ordem de execução das threads, e nem sempre a condição de corrida vai ocorrer.

### 1.1.3. De que forma seria possível resolver o problema do codigo, utilizando os conhecimentos já apresentados na disciplina?
O problema do código pode ser consertado, se quando um thread for acessar a área crítica (a variável compartilhada), nenhuma outra thread acessá-la.

### 1.2. Quais sao as quatro condições para se evitar condições de corrida? 

As quatro condições são:

  - Dois ou mais processos não podem estar simultaneamente dentro de suas regiões críticas.
  - Nenhuma consideração pode ser feita a respeito da velocidade relativa dos processos, ou a respeito dos processadores disponíveis.
  - Nenhum processo que esteja fora de sua região crítica pode bloquear a execução de outro processo.
  - Nenhum processo pode ser a obrigado a esperar indefinidamente para entrar em sua região crítica.

### 2.1.1.
Código implementado em *deposito.c*, e compilado e executado com 
```
gcc -o t deposito.c -lpthread
./t
```

### 2.1.2. O que acontece, com o funcionamento do algoritmo, como um todo, se a thread responsável pelo deposito terminar sua execução?
A thread de retirada executa mais uma vez. Em seguida ela passa a vez para o depósito, e a vez nunca volta pra ela.

### 2.1.3.
Código implementado em *deposito-contador.c*, e compilado e executado com 
```
gcc -o t deposito-contador.c -lpthread
./t
```
