| 10018 | Reverse | and Add |     |     |     |     |
| ----- | ------- | ------- | --- | --- | --- | --- |
The “reverse and add” method is simple: choose a number, reverse its digits and add it to the original.
If the sum is not a palindrome (which means, it is not the same number from left to right and right to
| left), repeat | this procedure. |     |     |     |     |     |
| ------------- | --------------- | --- | --- | --- | --- | --- |
195 Initial number
591
—–
786
687
—–
| For | example: 1473 |     |     |     |     |     |
| --- | ------------- | --- | --- | --- | --- | --- |
3741
—–
5214
4125
—–
|     | 9339 | Resulting palindrome |     |     |     |     |
| --- | ---- | -------------------- | --- | --- | --- | --- |
In this particular case the palindrome ‘9339’ appeared after the 4th addition. This method leads
to palindromes in a few step for almost all of the integers. But there are interesting exceptions. 196
is the first number for which no palindrome has been found. It is not proven though, that there is no
such a palindrome.
You must write a program that give the resulting palindrome and the number of iterations (addi-
| tions) | to compute the     | palindrome.    |                       |                |     |     |
| ------ | ------------------ | -------------- | --------------------- | -------------- | --- | --- |
| You    | might assume       | that all tests | data on this problem: |                |     |     |
| • will | have an answer     | ,              |                       |                |     |     |
| • will | be computable      | with less than | 1000 iterations       | (additions),   |     |     |
| • will | yield a palindrome | that is        | not greater than      | 4,294,967,295. |     |     |
Input
The first line will have a number N (0 < N (cid:20) 100) with the number of test cases, the next N lines will
| have a | number P to compute | its palindrome. |     |     |     |     |
| ------ | ------------------- | --------------- | --- | --- | --- | --- |
Output
For each of the N tests you will have to write a line with the following data :
minimum umber f terations(additions) o et o he alindrome and the esulting alindrome tself sep-
|        | n o i         |     | t g t t | p   | r p | i   |
| ------ | ------------- | --- | ------- | --- | --- | --- |
| arated | by one space. |     |         |     |     |     |
| Sample | Input         |     |         |     |     |     |
3
195
265
750

| Universidad | de Valladolid | OJ: 10018 | – Reverse | and Add | 2/2 |
| ----------- | ------------- | --------- | --------- | ------- | --- |
| Sample      | Output        |           |           |         |     |
4 9339
5 45254
3 6666