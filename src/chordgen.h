#define MAX_NOTES 12 //tweleve diatonics notes.
#define MAX_CORDES 4 // E A D G, the fourth lower strings
#define MAX_CHORDS 5  //five mode of seventh's chord.
#define CRD_STR_LGTH 47 //max chord diagram's string length
#define TRUTH_POS 19 // where is "x" located in chords diagram.
#define INTRO_STR "generate a new chord"
#define SOLUT_STR "see the solution"

/* these are the ascii strings representation of the chords diagram,
  "+" represents the place where the tonique is hold, and
  the "x" at the middle case is supposed to be remplaced by the number
  of the fret when needed"*/
const char * c_forms_sixth[MAX_CHORDS] = {
  "  ||||||\n  ||||||\n x+|||*|\n  ||**||\n  ||||||\n",
  "  ||||||\n  ||||||\n x+|*|*|\n  |||*||\n  ||||||\n",
  "  ||||||\n  ||||||\n x+|***|\n  ||||||\n  ||||||\n",
  "  ||||||\n  ||||*|\n x+|**||\n  ||||||\n  ||||||\n",
  "  ||||||\n  ||*-*|\n x+||*||\n  ||||||\n  ||||||\n"
};

const char * c_forms_fifth[MAX_CHORDS] = {
  "  ||||||\n  ||||||\n x|+---*\n  |||*||\n  ||*|*|\n",
  "  ||||||\n  ||||||\n x|+---*\n  ||||||\n  ||*|*|\n",
  "  ||*|||\n  ||||||\n x|+|*||\n  ||||*|\n  ||||||\n",
  "  ||||||\n  ||||||\n x|+|*||\n  ||*|*|\n  ||||||\n",
  "  ||||||\n  |||*||\n x|+||||\n  ||*|*|\n  ||||||\n"
};

const char * c_forms_fourth[MAX_CHORDS] = {
  "  ||||||\n  ||||||\n x||+|||\n  ||||||\n  |||*-*\n",
  "  ||||||\n  ||||||\n x||+|||\n  ||||*|\n  |||*|*\n",
  "  ||||||\n  ||||||\n x||+|||\n  ||||**\n  |||*||\n",
  "  ||||||\n  ||||||\n x||+|||\n  |||*-*\n  ||||||\n",
  "  ||||||\n  ||||||\n x||+|*|\n  |||*|*\n  ||||||\n"
};

const char * c_forms_third[MAX_CHORDS] = {
  "  ||||||\n  ||||||\n x||*+-*\n  ||||||\n  |||||*\n",
  "  ||||||\n  ||||||\n x||*+-*\n  |||||*\n  ||||||\n",
  "  ||||||\n  ||||*|\n x||*+||\n  ||||||\n  |||||*\n",
  "  ||||||\n  ||*-*|\n x|||+||\n  |||||*\n  ||||||\n",
  "  ||||||\n  ||*|*|\n x|||+|*\n  ||||||\n  ||||||\n"
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
    Bb,
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
  I use Hexadeciaml notation to represent them, and then
  handles their diagram representation later.*/
char array_frette[MAX_NOTES] = {
  '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'
};

/*enum pour représenter sur quelle corde se trouve la tonique.
suivi par son tableau de string*/
typedef enum Corde{
    THIRD,
    FOURTH,
    FIFTH,
    SIXTH
} Corde;

char * array_corde[MAX_CORDES] = {
  "third",
  "fourth",
  "fifth",
  "sixth"
};

//enum pour représenter l'accord suivi par son tableau de string.
typedef enum Accord{
    MAJ7,
    SEVEN,
    MIN7,
    M7B5,
    DIMINISHED
} Accord;

char * array_accord[MAX_CHORDS] = {
  "Maj7",
  "7",
  "m7",
  "m7b5",
  "diminished"
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
void rng_init(void);

/*dumb function to make the user control at which moment
he wants the program to procede to the next step,
takes a string as argument to modularize what comes
after "press enter key to " */
void press_enter_to_continue(const char * strng);

//returns a integer between 0 and the limit give as argument.
int rng(int const limit);

/* take care to replace the 'x' in diagram by the char toReplace
   made as function to handle the case of the frets '10','11' and '12'
   where they should be displayed correctly*/
void place_the_fret_num(char * diagram, char toReplace);

/*return a pointer on the correct chord diagram according
to the string of the base of the chord and the chord mode*/
const char * get_the_good_string(Corde corde, Accord accord);

/*return the correct frette where the base of the chord should be,
according on the string where the first note of the chord is played.*/
char get_the_good_fret(Note note, Corde corde);

/*prints the error message in case one of the two above
  functions would enter the default case. It should never
  happen in any case but who knows, shit happens.*/
void errorMsg(void);
