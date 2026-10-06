| 11063 | B2-Sequence |     |
| ----- | ----------- | --- |
A B2-Sequence is a sequence of positive integers 1 (cid:20) b < b < b ::: such that all pairwise sums b +b ,
1 2 3 i j
(cid:20)
| where | i j, are different. |     |
| ----- | ------------------- | --- |
Your task is to determine if a given sequence is a B2-Sequence or not.
Input
Each test case starts with 2 (cid:20) N (cid:20) 100, the number of elements in a sequence. Next line will have N
integers, representing the value of each element in the sequence. Each element b is an integer such that
i
b (cid:20) 10000. There is a blank line after each test case. The input is terminated by end of file (EOF).
i
Output
For each test case you must print the number of the test case, starting from 1, and a message indicating
if the corresponding sequence it is a B2-Sequence or not. See the sample output below. After each test
| case you | must print | a blank line. |
| -------- | ---------- | ------------- |
| Sample   | Input      |               |
4
1 2 4 8
4
| 3 7 10   | 14        |                |
| -------- | --------- | -------------- |
| Sample   | Output    |                |
| Case #1: | It is a   | B2-Sequence.   |
| Case #2: | It is not | a B2-Sequence. |