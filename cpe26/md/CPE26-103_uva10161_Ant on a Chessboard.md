| 10161 | Ant on | a Chessboard |     |
| ----- | ------ | ------------ | --- |
One day, an ant called Alice came to an M*M chessboard. She wanted to go around all the grids. So
she began to walk along the chessboard according to this way: (you can assume that her speed is one
| grid per | second) |     |     |
| -------- | ------- | --- | --- |
At the first second, Alice was standing at (1,1). Firstly she went up for a grid, then a grid to the
right, a grid downward. After that, she went a grid to the right, then two grids upward, and then two
| grids to     | the left¡ in a word, | the path was | like a snake.   |
| ------------ | -------------------- | ------------ | --------------- |
| For example, | her first            | 25 seconds   | went like this: |
( the numbers in the grids stands for the time when she went into the grids)
25 24 23 22 21 5
10 11 12 13 20 4
9 8 7 14 19 3
2 3 6 15 18 2
1 4 5 16 17 1
1 2 3 4 5
At the 8-th second , she was at (2,3), and at 20-th second, she was at (5,4).
Your task is to decide where she was at a given time (you can assume that M is large enough).
Input
(cid:20) (cid:20) 2(cid:3)109),
Input file will contain several lines, and each line contains a number N (1 N which stands
for the time. The file will be ended with a line that contains a number ‘0’.
Output
For each input situation you should print a line with two numbers (x,y), the column and the row
| number, | there must be | only a space | between them. |
| ------- | ------------- | ------------ | ------------- |
| Sample  | Input         |              |               |
8
20
25
0
| Sample | Output |     |     |
| ------ | ------ | --- | --- |
2 3
5 4
1 5