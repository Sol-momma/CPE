| 10920                         | Spiral         |         | Tap            |                             |           |            |            |
| ----------------------------- | -------------- | ------- | -------------- | --------------------------- | --------- | ---------- | ---------- |
| The game                      | of Spiral      | Tap     | is played      | on a square                 |           | grid.      | Pieces are |
| placed                        | on a grid      | and the | moves          | are realized                | according |            | to the     |
| positionofthepiecesonthegrid. |                |         |                | However,thecoordinatesystem |           |            |            |
| in the                        | game of Spiral | Tap     | are            | a bit different             | that      | those      | find in    |
| traditional                   | board games,   |         | such           | as chess.                   |           |            |            |
| The                           | cell numbering |         | scheme         | follow a spiral,            | starting  |            | from the   |
| center of                     | the grid       | in an   | anti-clockwise | fashion.                    | The       | figure     | on the     |
| right illustrates             | the            | cell    | numbering      | scheme.                     |           |            |            |
| The                           | goal is, given | the     | spiral         | tap coordinates             |           | of a cell, | find its   |
| cartesian                     | coordinates    | (line   | 1 is           | at the bottom,              |           | and column | 1 is       |
the leftmost).
Input
The input is a series of lines. Each line is composed of two numbers: SZ and P. SZ is the size of the
border of the grid and is an odd number no larger than 100000. P is the spiral position of a cell in this
grid. The line such that SZ = P = 0 marks the end of the input (and is not part of the data set).
Output
For each line in the data set of the input, your program must echo a line ‘Line = X, column = Y.’,
where X and Y are the cartesian coordinates of the corresponding cell.
| Sample | Input |     |     |     |     |     |     |
| ------ | ----- | --- | --- | --- | --- | --- | --- |
3 1
3 3
3 9
5 9
5 10
0 0
| Sample | Output    |      |     |     |     |     |     |
| ------ | --------- | ---- | --- | --- | --- | --- | --- |
| Line = | 2, column | = 2. |     |     |     |     |     |
| Line = | 3, column | = 1. |     |     |     |     |     |
| Line = | 3, column | = 3. |     |     |     |     |     |
| Line = | 4, column | = 4. |     |     |     |     |     |
| Line = | 5, column | = 4. |     |     |     |     |     |