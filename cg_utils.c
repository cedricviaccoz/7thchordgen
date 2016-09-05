#include "chordgen.h"
#include <stdlib.h>
#include <time.h>

int rng(int const limit){
    return rand() % limit;
}

void rng_init(){
      time_t t;
      /* Intializes random number generator */
      srand((unsigned) time(&t));
}
