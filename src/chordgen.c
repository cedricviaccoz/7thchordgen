#include "chordgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
  /*so the rng function has a distinctive seed each time
  the program is run.*/
  rng_init();

  /*we will juste change the variable of this statically
  alocated chord for the benefits of the program.*/
  Chord chord;

  //to handle error returned by functions.
  unsigned int interruptSig = 0;

  /*I don't see any benefit in adding a termination feature for
   the moment,so the program will forever keep on running if
   there isn't an error (error that should never occur, I just
   added an error handling by principe).*/
  while(!interruptSig){
    press_enter_to_continue(INTRO_STR);
    chord.note = rng(MAX_NOTES);
    chord.corde = rng(MAX_CORDES);
    chord.accord = rng(MAX_CHORDS);
    printf("You need to play this chord : %s%s on the %s string.\n\n",
            array_note[chord.note], array_accord[chord.accord],
            array_corde[chord.corde]);
    press_enter_to_continue(SOLUT_STR);

    /*now we extract the good chord diagram, make a copy and remplace
    the "x" with the good corresponding number on the copy*/
    const char * correct_diagram = get_the_good_string(chord.corde,chord.accord);
    if(correct_diagram == NULL){
      interruptSig = 1; //thus the program shall escape the infinite loop
      errorMsg();
    }else{
      char chord_diagram[CRD_STR_LGTH];

      strncpy(chord_diagram, correct_diagram, CRD_STR_LGTH);
      char xSubstitute = get_the_good_fret(chord.note, chord.corde);
      if(xSubstitute == 0){
        interruptSig = 1;
        errorMsg();
      }else{
        chord_diagram[TRUTH_POS] = xSubstitute;
        printf("\nthe solution was :\n\n%s\n", chord_diagram);
      }
    }
  }
    return interruptSig;
}

void rng_init(void){
      time_t t;
      /* Intializes random number generator */
      srand((unsigned) time(&t));
}

void press_enter_to_continue(const char * strng){
  printf("press ENTER key to %s.\n", strng);
  getchar();
}

const char * get_the_good_string(Corde corde, Accord accord){
  switch(corde){
    case THIRD: return c_forms_third[accord];
    case FOURTH: return c_forms_fourth[accord];
    case FIFTH: return c_forms_fifth[accord];
    case SIXTH: return c_forms_sixth[accord];
    default: return NULL;
  }
}

char get_the_good_fret(Note note, Corde corde){
  switch(corde){
    //+2 and +7 for the semitones in change between strings.
    case THIRD: return array_frette[((note + 9) % MAX_NOTES)];
    case FOURTH: return array_frette[((note + 2) % MAX_NOTES)];
    case FIFTH: return array_frette[((note + 7) % MAX_NOTES)];
    case SIXTH: return array_frette[note];
    default: return 0;
  }
}

int rng(int const limit){
    return rand() % limit;
}

void errorMsg(void){
  printf("An error occured, please restart the program "
         "or contact the dumbfuck responsible for this "
         "piece of trash.");
}
