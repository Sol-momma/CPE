642 Word Amalgamation
In millions of newspapers across the United States there is a word game called Jumble. The object of
this game is to solve a riddle, but in order to find the letters that appear in the answer it is necessary
to unscramble four words. Your task is to write a program that can unscramble words.
Input
The input file contains four parts:
1. a dictionary, which consists of at least one and at most 100 words, one per line;
2. a line containing ‘XXXXXX’, which signals the end of the dictionary;
3. one or more scrambled ‘words’ that you must unscramble, each on a line by itself; and
4. another line containing ‘XXXXXX’, which signals the end of the file.
All words, including both dictionary words and scrambled words, consist only of lowercase English
lettersandwillbeatleastoneandatmostsixcharacterslong. (Notethatthesentinel‘XXXXXX’contains
uppercase X’s.) The dictionary is not necessarily in sorted order, but each word in the dictionary is
unique.
Output
For each scrambled word in the input, output an alphabetical list of all dictionary words that can be
formed by rearranging the letters in the scrambled word. Each word in this list must appear on a line
byitself. Ifthelistisempty(becausenodictionarywordscanbeformed), outputtheline‘NOT A VALID
WORD’ instead. In either case, output a line containing six asterisks to signal the end of the list.
Sample Input
tarp
given
score
refund
only
trap
work
earn
course
pepper
part
XXXXXX
resco
nfudre
aptr
sett
oresuc
XXXXXX

| Universidad | de Valladolid | OJ: 642 | – Word Amalgamation | 2/2 |
| ----------- | ------------- | ------- | ------------------- | --- |
| Sample      | Output        |         |                     |     |
score
******
refund
******
part
tarp
trap
******
| NOT A VALID | WORD |     |     |     |
| ----------- | ---- | --- | --- | --- |
******
course
******