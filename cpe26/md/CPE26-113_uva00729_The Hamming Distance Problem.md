| 729 | The | Hamming |     |     | Distance |     | Problem |     |     |
| --- | --- | ------- | --- | --- | -------- | --- | ------- | --- | --- |
The Hamming distance between two strings of bits (binary integers) is the number of corresponding bit
positions that differ. This can be found by using XOR on corresponding bits or equivalently, by adding
corresponding bits (base 2) without a carry. For example, in the two bit strings that follow:
|     |     |     |     |     | A       | 0 1   | 0 0 1 | 0 1 | 0 0 0 |
| --- | --- | --- | --- | --- | ------- | ----- | ----- | --- | ----- |
|     |     |     |     |     | B       | 1 1   | 0 1 0 | 1 0 | 1 0 0 |
|     |     |     |     |     | A XOR B | = 1 0 | 0 1 1 | 1 1 | 1 0 0 |
The Hamming distance (H) between these 10-bit strings is 6, the number of 1’s in the XOR string.
Input
Input consists of several datasets. The first line of the input contains the number of datasets, and it’s
followed by a blank line. Each dataset contains N, the length of the bit strings and H, the Hamming
| distance, | on the | same | line. | There | is a blank | line between |     | test | cases. |
| --------- | ------ | ---- | ----- | ----- | ---------- | ------------ | --- | ---- | ------ |
Output
For each dataset print a list of all possible bit strings of length N that are Hamming distance H from
the bit string containing all 0’s (origin). That is, all bit strings of length N with exactly H 1’s printed
| in ascending | lexicographical |     |     | order. |     |     |     |     |     |
| ------------ | --------------- | --- | --- | ------ | --- | --- | --- | --- | --- |
The number of such bit strings is equal to the combinatorial symbol C(N;H). This is the number
(cid:0)H
| of possible | combinations |     | of  | N   | zeros and | H ones. | It  | is equal | to  |
| ----------- | ------------ | --- | --- | --- | --------- | ------- | --- | -------- | --- |
N!
(cid:0)H)!H!
(N
This number can be very large. The program should work for 1 (cid:20) H (cid:20) N (cid:20) 16.
| Print  | a blank | line | between | datasets. |     |     |     |     |     |
| ------ | ------- | ---- | ------- | --------- | --- | --- | --- | --- | --- |
| Sample | Input   |      |         |           |     |     |     |     |     |
1
4 2
| Sample | Output |     |     |     |     |     |     |     |     |
| ------ | ------ | --- | --- | --- | --- | --- | --- | --- | --- |
0011
0101
0110
1001
1010
1100