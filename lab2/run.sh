# executar hello-thread.c
# gcc -o t hello-thread.c -lpthread
# for i in {1..10}; do ./t | grep thread; done

# executar thread-join.c
# gcc -o t divisao-tarefas.c -lpthread -lm
# ./t

# executar escalonamento-tarefas.c
gcc -o t escalonamento-tarefas.c -lpthread
./t

# executar contador.c
# gcc -o t contador.c -lpthread
# ./t