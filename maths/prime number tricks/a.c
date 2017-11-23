#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000000000

char P[SIZE];

void sieve();

int main()
{
    printf("%d\n", SIZE);
    sieve();
    for(int i = 0; i < 20; i++)
        if(P[i])
            printf("%d\n", i);
    return 0;
}

void sieve()
{
    memset(P, 1, sizeof(P));
    P[0] = P[1] = 0;
    for(int i = 2; i * i <= SIZE; i++)
    {
        if(P[i])
        {
            for(int j = i * i; i < SIZE; i += i)
                P[i] = 0;
        }
    }
}
