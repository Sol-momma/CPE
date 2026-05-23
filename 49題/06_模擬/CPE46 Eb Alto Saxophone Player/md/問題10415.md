| 10415 | Eb Alto | Saxophone | Player |     |
| ----- | ------- | --------- | ------ | --- |
Do you like saxophone? I have a Eb Alto Saxophone, shown on the right.
| My fingers | move A | LOT when playing | some music, | and I’m quite |
| ---------- | ------ | ---------------- | ----------- | ------------- |
interested in how many times each finger PRESS the button. Assume
that the music is composed of only 8 kinds of note. They are: C D E
F G A B in one octave and C D E F G A B in a higher octave. We
usec,d,e,f,g,a,b,C,D,E,F,G,A,Btorepresentthem. ThefingersIusefor
| each note   | are:                    |     |     |     |
| ----------- | ----------------------- | --- | --- | --- |
| • c: finger | 2(cid:24)4, 7(cid:24)10 |     |     |     |
| • d: finger | 2(cid:24)4, 7(cid:24)9  |     |     |     |
| • e: finger | 2(cid:24)4, 7, 8        |     |     |     |
2(cid:24)4,
| • f: finger | 7   |     |     |     |
| ----------- | --- | --- | --- | --- |
2(cid:24)4
| • g: finger |                        |     |     |     |
| ----------- | ---------------------- | --- | --- | --- |
| • a: finger | 2, 3                   |     |     |     |
| • b: finger | 2                      |     |     |     |
| • C: finger | 3                      |     |     |     |
| • D: finger | 1(cid:24)4, 7(cid:24)9 |     |     |     |
| • E: finger | 1(cid:24)4, 7, 8       |     |     |     |
1(cid:24)4,
| • F: finger | 7   |     |     |     |
| ----------- | --- | --- | --- | --- |
1(cid:24)4
| • G: finger |     |     |     |     |
| ----------- | --- | --- | --- | --- |
1(cid:24)3
| • A: finger |            |     |     |     |
| ----------- | ---------- | --- | --- | --- |
| • B: finger | 1(cid:24)2 |     |     |     |
(Note that every finger is controlling a specified button, different fingers are controlling different
buttons.)
Write a program to help count the number of times each finger presses the button. A finger presses
a button if it is needed in a note, but not used in the last note. Also, if it is the first note, every finger
| required presses | the button. |     |     |     |
| ---------------- | ----------- | --- | --- | --- |
Input
The first line of the input is a single integer t (1 (cid:20) t (cid:20) 1000), indicating the number of test
cases. For each case, there is only one line containing the song. The only allowed characters are
{‘c’,‘d’,‘e’,‘f’,‘g’,‘a’,‘b’, ‘C',‘D’,‘E’,‘F’,‘G’,‘A’,‘B’}. There are at most 200 notes in a song, and the song
maybe empty.

Universidad de Valladolid OJ: 10415 – Eb Alto Saxophone Player 2/2
Output
For each test case, print 10 numbers indicating the number of presses for each finger. Numbers are
| separated | by a single | space. |
| --------- | ----------- | ------ |
| Sample    | Input       |        |
3
cdefgab
BAGFEDC
CbCaDCbCbCCbCbabCCbCbabae
| Sample | Output    |     |
| ------ | --------- | --- |
| 0 1 1  | 1 0 0 1 1 | 1 1 |
| 1 1 1  | 1 0 0 1 1 | 1 0 |
| 1 8 10 | 2 0 0 2 2 | 1 0 |