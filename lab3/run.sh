# executar incremento.c
# gcc -o t incremento.c -lpthread
# ./t

# executar deposito.c
# gcc -o t deposito.c -lpthread
# ./t

# executar contador.c
# gcc -o t contador.c -lpthread
# ./t

# executar deposito-contador.c
# gcc -o t deposito-contador.c -lpthread
# ./t

# executar incremento-atomico.c
gcc -o t incremento-atomico.c -lpthread
./t