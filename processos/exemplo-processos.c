#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i;
    char c = 'a';
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // O código aqui dentro será executado no processo filho
        printf("pid do Filho: %d -> Pai: %d\n", getpid(), getppid());
        //printf("Caractere e endereco: %c - %p\n", c, &c);
    } else {
        c = 'b';
        // O código neste trecho será executado no processo pai
        printf("pid do Pai: %d\n", getpid());
        //printf("Caractere e endereco: %c - %p\n", c, &c);
    }

    printf("Esta regiao sera executada por ambos processos\n");
    printf("Caractere e endereco: %c - %p\n\n", c, &c);
    scanf("%d", &i);
    exit(0);
}
