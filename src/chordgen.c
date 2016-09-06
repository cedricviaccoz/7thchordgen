#include "chordgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
  /*so the rng function has a distinctive seed each time
  the program is run.*/
  rng_init();

  /*we will juste change the variable of this statically
  alocated chord for the benefits of the program.*/
  Chord chord;

  /*I don't see any benefit in adding a termination feature for
   the moment,so the program will forever keep on running.*/
  while(1){
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
    char chord_diagram[CRD_STR_LGTH];
    strncpy(chord_diagram, correct_diagram, CRD_STR_LGTH);
    char xSubstitute = get_the_good_frette(chord.note, chord.corde);
    chord_diagram[TRUTH_POS] = xSubstitute;
    printf("\nthe solution was :\n\n%s\n", chord_diagram);
  }
    return 0;
}

const char * get_the_good_string(Corde corde, Accord accord){
  switch(corde){
    case FOURTH: return c_forms_fourth[accord];
    case FIFTH: return c_forms_fifth[accord];
    case SIXTH: return c_forms_sixth[accord];
    default: return c_forms_sixth[accord];
  }
}

char get_the_good_frette(Note note, Corde corde){
  switch(corde){
    //+2 and +7 for the semitones in change between strings.
    case FOURTH: return array_frette[((note + 2) % 12)];
    case FIFTH: return array_frette[((note + 7) % 12)];
    case SIXTH: return array_frette[note];
    default: return array_frette[note];
  }
}

int rng(int const limit){
    return rand() % limit;
}

void rng_init(){
      time_t t;
      /* Intializes random number generator */
      srand((unsigned) time(&t));
}

void press_enter_to_continue(const char * strng){
  printf("press ENTER key to %s\n.", strng);
  getchar();
}
