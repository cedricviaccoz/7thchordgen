#7thchordgen
A small C program to help you learn jazz chords.

##Instructions
1. Run the program and press enter.
2. You will be told to play a random chord (e.g. a Cmin7 with the bass on the 5th string).
3. Press enter after you play the chord and the program will output a solution (a chord diagram) in ASCII.

##The chords
The chords you are required to play have three variables:
* the base (tonique) (all twelve notes from A to G with semi-tones)
* the string in which the bass (tonique) has to be played (3rd, 4th, 5th, or 6th string)
* and the chord itself, the choices are the following:
  * Maj7
  * 7
  * m7 (-7)
  * m7b5
  * diminished/diminué (°)

##The Diagrams
The diagrams will be displayed as an ASCII output, such as this one :

```
  ||||||
  ||*-*|
10+||*||
  ||||||
  ||||||
```
This is a Dm7b5. the fret where the chord should be placed always appears in the center, on the same fret as the "+" token which is the char used to represent the base (tonique) of the chord. If there is a "-" between two " * ", it means you have to perform a bar with one finger between the two star.
