# 7thchordgen
Just a samll C program to train myself into learning chords.

Once you run the program, you juste have to press a key, then it will dictate you to play a random chord
for example a Cmin7 with the bass on the 5th string.
Then when you've played that chord you can press enter key and the program will show you the solution as a simplified ASCII output of a chord diagram.

The source code was written to be compiled by gcc on a linux terminal, I'm certain it might also works on macOS, but for windows I have no idea since I have never developped C programs on it.

#The chords
The chords you are required to play have three variables :
* the base (tonique) (all twelve note from A to G with semi-tones)
* the string in wich the bass (tonique) has to be played (4th, 5th, or 6th string)
* and the chord itself, the choices are the following :
  * Maj7
  * 7
  * m7 (-7)
  * m7b5 (%)
  * diminished/diminué (°)
