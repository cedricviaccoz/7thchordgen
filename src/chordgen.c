#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Hello, World!\n");

    return 0;
}

int rng(int const limit){
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    return rand() % limit;

}
