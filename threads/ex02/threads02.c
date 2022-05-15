#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* funcao01(void* arg)
{
    int* num = arg;
    printf("Tarefa Funcao01 rodando... \n");
    *num = *num + 2;
}
void* funcao02(void* arg)
{
    int* num = arg;
    printf("Tarefa Funcao02 rodando... \n");
    *num = *num + 3;
}

int main()
{
    pthread_t thread_id_1, thread_id_2;
    int num_1 = 1, num_2 = 2;
    printf("Iniciando Threads\n");
    pthread_create(&thread_id_1, NULL, funcao01, &num_1);
    pthread_create(&thread_id_2, NULL, funcao02, &num_2);
    pthread_join(thread_id_1, NULL);
    pthread_join(thread_id_2, NULL);
    printf("Valor de num_1: %d\n", num_1);
    printf("Valor de num_2: %d\n", num_2);
    exit(0);
}
