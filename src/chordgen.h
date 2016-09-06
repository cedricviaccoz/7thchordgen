#define MAX_NOTES 12 //tweleve diatonics notes.
#define MAX_CORDES 3  //change to 4 later.
#define MAX_CHORDS 5  //five mode of seventh's chord.
#define CRD_STR_LGTH 42 //max chord diagram's string length
#define TRUTH_POS 16 // where is "x" located in chords diagram.
#define INTRO_STR "generate a new chord"
#define SOLUT_STR "see the solution"

/* these are the ascii strings representation of the chords diagram,
  the "x" at the middle case is supposed to be remplaced by the number
  of the fret when needed"*/

const char * c_forms_sixth[MAX_CHORDS] = {
  " ||||||\n ||||||\nx*|||*|\n ||**||\n ||||||\n",
  " ||||||\n ||||||\nx*|*|*|\n |||*||\n ||||||\n",
  " ||||||\n ||||||\nx*|***|\n ||||||\n ||||||\n",
  " ||||||\n ||||*|\nx*|**||\n ||||||\n ||||||\n",
  " ||||||\n ||*-*|\nx*||*||\n ||||||\n ||||||\n"
};

const char * c_forms_fifth[MAX_CHORDS] = {
  " ||||||\n ||||||\nx|*---*\n |||*||\n ||*|*|\n",
  " ||||||\n ||*|||\nx|*|*||\n ||||||\n ||||*|\n",
  " ||*|||\n ||||||\nx|*|*||\n ||||*|\n ||||||\n",
  " ||||||\n ||||||\nx|*|*||\n ||*|*|\n ||||||\n",
  " ||||||\n |||*||\nx|*||||\n ||*|*|\n ||||||\n"
};

const char * c_forms_fourth[MAX_CHORDS] = {
  " ||||||\n ||||||\nx||*|||\n ||||||\n |||*-*\n",
  " ||||||\n ||||||\nx||*|||\n ||||*|\n |||*|*\n",
  " ||||||\n ||||||\nx||*|||\n ||||**\n |||*||\n",
  " ||||||\n ||||||\nx||*|||\n |||*-*\n ||||||\n",
  " ||||||\n ||||||\nx||*|*|\n |||*|*\n ||||||\n",
};
/* enum which represents the base of the chord.
  followed by its array of string
   starts on F because on 6th string it is on fret "1".*/
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
char * array_note[MAX_NOTES] = {
  "F", "F#", "G", "Ab", "A", "Bb", "B", "C", "C#","D", "Eb", "E"
};

/*to replace the "x" in the ASCII diagram
  Since I can't write "10", "11" and "12" as one char, 
  I use Hexadeciaml notation to represent them*/
char array_frette[MAX_NOTES] = {
  '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'
};

/*enum pour représenter sur quelle corde se trouve la tonique.
suivi par son tableau de string*/
typedef enum Corde{
    //THIRD,  à ajouter plus tard quand mon prof l'aura dessiné
    FOURTH,
    FIFTH,
    SIXTH
} Corde;

char * array_corde[MAX_CORDES] = {
  "fourth",
  "fifth",
  "sixth"
};

//enum pour représenter l'accord suivi par son tableau de string.
typedef enum Accord{
    MAJ7,
    SEVEN,
    MIN7,
    m7b5,
    diminished
} Accord;

char * array_accord[MAX_CHORDS] = {
  "Maj7",
  "7",
  "m7",
  "m7b5",
  "°"
};

/*Struct that represents the chord to be displayed*/
typedef struct Chord{
  Note note;
  Corde corde;
  Accord accord;
} Chord;

/* initialize the rng with system's time as seed.
   Must imperatively be called once in the main before
   using the rng function.*/
void rng_init();

/*dumb function to make the user control at which moment
he wants the program to procede to the next step, 
takes a string as argument to modularize what comes
after "press enter key to " */
void press_enter_to_continue(const char * strng);

//returns a integer between 0 and the limit give as argument.
int rng(int const limit);

/*return a pointer on the correct chord diagram according
to the string of the base of the chord and the chord mode*/
const char * get_the_good_string(Corde corde, Accord accord);

/*return the correct frette where the base of the chord should be,
according on the string where the first note of the chord is played.*/
char get_the_good_fret(Note note, Corde corde);