#define MAX_NOTES 12
#define MAX_CORDES 3  //à changer en 4 plus tard.
#define MAX_CHORDS 5
#include <stdlib.h>
#include <stdio.h>

const char * c_forms_sixth[MAX_CHORDS] = {
  " ||||||\n ||||||\nx*|||*|\n ||**||\n ||||||\n",
  " ||||||\n ||||||\nx*|||*|\n ||**||\n ||||||\n",
  " ||||||\n ||||||\nx*|||*|\n ||**||\n ||||||\n",
  " ||||||\n ||||||\nx*|||*|\n ||**||\n ||||||\n",
  " ||||||\n ||||||\nx*|||*|\n ||**||\n ||||||\n"
};

/* enum pour représenter la tonique de l'accord.
   starts on F for reason, shut up.*/
typedef enum Note Note;
enum Note{
    F,
    Gb,
    G,
    Ab,
    A,
    B,
    C,
    Db,
    D,
    Eb,
    E
};

//enum pour représenter sur quelle corde se trouve la tonique
typedef enum Corde Corde;
enum Corde{
    //THIRD,  à ajouter plus tard quand mon prof l'aura dessiné
    FOURTH,
    FIFTH,
    SIXTH
};

//enum pour représenter l'accord
typedef enum Accord Accord;
enum Accord{
    MAJ7,
    SEVEN,
    MIN7,
    m7b5,
    diminished
};

/*Struct that represents the chord to be displayed*/
typedef struct Chord Chord;
struct Chord{
  Note note;
  Corde corde;
  Accord accord;
};

/* initialize the rng with system's time as seed.
   Must imperatively be called once in the main before
   using the rng function.*/
void rng_init();


//retourne un entier choisi aléatoirement compris entre 0 et la limite donné en argument
int rng(int const limit);
