#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.

struct arg_struct {
	long int num;
	long int param;
};

long int fib(long int v){
    if(v == 1 || v == 2)
        return 1;
    else
        return fib(v - 1) + fib(v - 2);
}

void* funcao01(void* arg)
{
    struct arg_struct *args = arg;
    int count = 0;
    printf("Tarefa Funcao01 rodando... \n");
    for(long int i=1;i<=(args->param);i++){
	count = 0;
	for (long int j=1;j<=(i/2);j++){
           if((i % j) == 0)
              count++;
       }
       if(count == 2)
            args->num = args->num + 1;
    }
}
void* funcao02(void* arg)
{
    struct arg_struct *args = arg;
    printf("Tarefa Funcao02 rodando... \n");
    for(int x=1;x<=(args->param);x++)
    	args->num = fib(x);
}

int main()
{
    pthread_t thread_id_1, thread_id_2;
    int opc = 0;
    int sair = 0;
    struct arg_struct arg1, arg2;
    arg1.num = 0;
    arg1.param = 0;
    arg2.num = 0;
    arg2.param = 0;
    while(1){
    	system("clear");
    	printf("#------------------------------------#\n");
    	printf("#  1 - Iniciar contagem de primos    #\n");
    	printf("#  2 - Iniciar sequencia Fibonnaci   #\n");
    	printf("#  3 - Mostrar valores               #\n");
    	printf("#  4 - Sair                          #\n");
    	printf("#------------------------------------#\n");
    	printf("# Informe um valor: ");
    	scanf("%d", &opc);
    	switch(opc){
    	    case 1:
  	       system("clear");
    	       printf("Informa o numero maximo: ");
    	       scanf("%ld", &arg1.param);
    	    	pthread_create(&thread_id_1, NULL, funcao01, &arg1);
    	    	pthread_tryjoin_np(thread_id_1, NULL);
    	    	break;
    	    case 2:
    	    	system("clear");
    	       printf("Informa o valor maximo da sequecia: ");
    	       scanf("%ld", &arg2.param);
    	    	pthread_create(&thread_id_2, NULL, funcao02, &arg2);
    	    	pthread_tryjoin_np(thread_id_2, NULL);
    	    	break;
    	    case 3:
    	    	printf("Valores de arg1: %ld -> %ld\n", arg1.param, arg1.num); 
    	    	printf("Valores de arg2: %ld -> %ld\n", arg2.param, arg2.num); 
		system("sleep 3");
    	    	break;
    	    default:
    	    	sair = 1;
    	    	break;
    	}
    	if(sair)
    	    break;
    	
    }
    exit(0);
}
