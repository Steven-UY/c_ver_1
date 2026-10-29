#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    char *mem = malloc(500000000);
    int step = 12345678;
    int n = 500000000 / step;

    for (int i = 0; ; i = (i + 1) % n){
        printf("\r%p", (void *)&mem[i * step]);
        fflush(stdout);
        usleep(200000);
    }
}