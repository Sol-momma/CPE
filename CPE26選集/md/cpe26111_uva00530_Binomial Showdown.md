| 530 | Binomial | Showdown |     |     |
| --- | -------- | -------- | --- | --- |
In how many ways can you choose k elements out of n elements, not taking order into account?
| Write | a program | to compute | this | number. |
| ----- | --------- | ---------- | ---- | ------- |
Input
| The input | file will | contain one | or more | test cases. |
| --------- | --------- | ----------- | ------- | ----------- |
Each test case consists of one line containing two integers n (n (cid:21) 1) and k (0 (cid:20) k (cid:20) n).
| Input | is terminated | by two | zeroes | for n and k. |
| ----- | ------------- | ------ | ------ | ------------ |
Output
For each test case, print one line containing the required number. This number will always fit into an
| integer, | i.e. it will | be less than | 231. |     |
| -------- | ------------ | ------------ | ---- | --- |
Warning: Don’tunderestimatetheproblem. Theresultwillfitintoaninteger—butifallintermediate
results arising during the computation will also fit into an integer depends on your algorithm. The test
| cases will | go to the | limit. |     |     |
| ---------- | --------- | ------ | --- | --- |
| Sample     | Input     |        |     |     |
4 2
10 5
49 6
0 0
| Sample | Output |     |     |     |
| ------ | ------ | --- | --- | --- |
6
252
13983816