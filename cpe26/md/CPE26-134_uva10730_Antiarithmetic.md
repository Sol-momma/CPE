| 10730         | Antiarithmetic?    |                |             |       |
| ------------- | ------------------ | -------------- | ----------- | ----- |
| A permutation |                    | of n is        | a bijective |       |
| function      | of the             | initial        | n natural   |       |
| numbers:      | 0;1;:::;n(cid:0)1. |                | A permu-    |       |
| tation p      | is called          | antiarithmetic |             | if    |
| there is      | no subsequence     |                | of it       | form- |
| ing an        | arithmetic         | progression    |             | of    |
| length bigger | than               | 2,             | i.e. there  | are   |
| no three      | indices            | 0 (cid:20) i   | < j <       | k < n |
| suchthat(p    | ;p ;p              | )formsanarith- |             |       |
i j k
metic progression.
For example, the sequence (2, 0, 1, 4, 3) is an antiarithmetic permutation of 5. The sequence (0,
5, 4, 3, 1, 2) is not an antiarithmetic permutation as its first, fifth and sixth term (0, 1, 2) form an
arithmetic progression; and so do its second, forth and fifth term (5, 3, 1).
Your task is to check whether a given permutation of n is antiarithmetic.
Input
There are several test cases, followed by a line containing 0. Each test case is a line of the input file
|     |     |     |     | (cid:20) (cid:20) |
| --- | --- | --- | --- | ----------------- |
containinganaturalnumber3 n 10000followedbyacolonandthenfollowedbyndistinctnumbers
separated by whitespace. All n numbers are natural numbers smaller than n.
Output
For each test case output one line with ‘yes’ or ‘no’ stating whether the permutation is antiarithmetic
or not.
| Sample | Input   |     |     |     |
| ------ | ------- | --- | --- | --- |
| 3: 0 2 | 1       |     |     |     |
| 5: 2 0 | 1 3 4   |     |     |     |
| 6: 2 4 | 3 5 0 1 |     |     |     |
0
| Sample | Output |     |     |     |
| ------ | ------ | --- | --- | --- |
yes
no
yes