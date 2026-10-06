| 516 | Prime | Land |     |     |     |     |     |     |     |
| --- | ----- | ---- | --- | --- | --- | --- | --- | --- | --- |
Everybody in the Prime Land is using a prime base number system. In this system, each positive
fp g1
integer x is represented as follows: Let denote the increasing sequence of all prime numbers.
|     |     |     |     |     | i i=0 |     |     |     |     |
| --- | --- | --- | --- | --- | ----- | --- | --- | --- | --- |
We know that x > 1 can be represented in only one way in the form of product of powers of prime
factors. This implies that there is an integer k and uniquely determined integers e ;e ;:::;e ;e ,
|          |        |            |              |                                        |             | x               |      | kx kx (cid:0)1 | 1 0 |
| -------- | ------ | ---------- | ------------ | -------------------------------------- | ----------- | --------------- | ---- | -------------- | --- |
|          |        | e (cid:1)p | e kx(cid:0)1 | (cid:1)(cid:1)(cid:1)(cid:1)(cid:1)pe1 | (cid:1)pe0. |                 |      |                |     |
| (e > 0), | that x | = p kx     |              |                                        |             | The sequence    |      |                |     |
| kx       |        | kx         | kx (cid:0)1  |                                        | 1 0         |                 |      |                |     |
|          |        |            |              |                                        | (e ;e       | (cid:0)1 ;:::;e | ;e ) |                |     |
|          |        |            |              |                                        | kx          | kx              | 1 0  |                |     |
is considered to be the representation of x in prime base number system.
It is really true that all numerical calculations in prime base number system can seem to us a little
bit unusual, or even hard. In fact, the children in Prime Land learn to add to subtract numbers several
years. On the other hand, multiplication and division is very simple.
Recently, somebody has returned from a holiday in the Computer Land where small smart things
called computers have been used. It has turned out that they could be used to make addition and
subtraction in prime base number system much easier. It has been decided to make an experiment and
| let a computer | to        | do the    | operation | “minus | one”. |                 |          |     |     |
| -------------- | --------- | --------- | --------- | ------ | ----- | --------------- | -------- | --- | --- |
| Help           | people in | the Prime | Land      | and    | write | a corresponding | program. |     |     |
Forpracticalreasonswewillwriteheretheprimebaserepresentationasasequenceofsuchp ande
i i
from the prime base representation above for which e > 0. We will keep decreasing order with regard
i
to p .
i
Input
The input file consists of lines (at least one) each of which except the last contains prime base repre-
sentation of just one positive integer greater than 2 and less or equal 32767. All numbers in the line
| are separated | by  | one space. | The | last line | contains | number | ‘0’. |     |     |
| ------------- | --- | ---------- | --- | --------- | -------- | ------ | ---- | --- | --- |
Output
The output file contains one line for each but the last line of the input file. If x is a positive integer
x(cid:0)1
contained in a line of the input file, the line in the output file will contain in prime base rep-
resentation. All numbers in the line are separated by one space. There is no line in the output file
| corresponding | to    | the last | “null” | line of | the input | file. |     |     |     |
| ------------- | ----- | -------- | ------ | ------- | --------- | ----- | --- | --- | --- |
| Sample        | Input |          |        |         |           |       |     |     |     |
17 1
5 1 2 1
| 509 1 59 | 1   |     |     |     |     |     |     |     |     |
| -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
0
| Sample | Output |     |     |     |     |     |     |     |     |
| ------ | ------ | --- | --- | --- | --- | --- | --- | --- | --- |
2 4
3 2
| 13 1 11 | 1 7 1 | 5 1 3 1 | 2 1 |     |     |     |     |     |     |
| ------- | ----- | ------- | --- | --- | --- | --- | --- | --- | --- |