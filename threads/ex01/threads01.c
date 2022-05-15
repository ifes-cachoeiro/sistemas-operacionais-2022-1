#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* minhaFuncaoThread(void* arg)
{
    int* num = arg;
    printf("Tarefa %d rodando... \n", *num);
    *num = 2;
    while (1) {
        // sleep(1);
        int i, num = 1, primes = 0;

        while (num <= 1000) {
            i = 2;
            while (i <= num) {
                if (num % i == 0)
                    break;
                i++;
            }
            if (i == num)
                primes++;
            num++;
        }
    }
    return NULL;
}

int main()
{
    pthread_t thread_id_1, thread_id_2;
    int num_1 = 1, num_2 = 2;
    int res_1;
    printf("Iniciando Threads\n");
    pthread_create(&thread_id_1, NULL, minhaFuncaoThread, &num_1);
    pthread_create(&thread_id_2, NULL, minhaFuncaoThread, &num_2);
    pthread_join(thread_id_1, NULL);
    pthread_join(thread_id_2, NULL);
    exit(0);
}
