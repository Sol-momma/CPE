| 12820 | Cool Word |     |     |
| ----- | --------- | --- | --- |
A word is a string of lower-case letters. A cool word has at least 2 different letters and the number of
| occurrences | of each different | letter is different. |     |
| ----------- | ----------------- | -------------------- | --- |
Here is a formal de(cid:12)nition. Let w be a word and S be the set of letters in word w, then w is
cool if and only if all f(c) (for each character c in S) is all different. Here f(c) means the number of
| occurrences | of c in w. |     |     |
| ----------- | ---------- | --- | --- |
For example, the word \ada" is cool because f(a) = 2, f(d) = 1, and they’re different. \banana"
is also cool because f(a) = 3, f(n) = 2, f(b) = 1. But the word \bbacccd" is not cool because
f(a) = f(d) = 1. Some other interesting cool words include: mammal, needed, papaya, referee,
senselessness.
| Read | a list of words and | count the number | of cool words. |
| ---- | ------------------- | ---------------- | -------------- |
Input
There will be at most 30 test cases. Each case begins with an integer n (1 (cid:20) n (cid:20) 10000), the number
of words to check. Each of the following n lines contains a word containing at least one and at most 30
letters.
Output
For each test case, print the case number and the number of cool words.
| Sample | Input |     |     |
| ------ | ----- | --- | --- |
2
ada
bbacccd
2
illness
a
| Sample  | Output |     |     |
| ------- | ------ | --- | --- |
| Case 1: | 1      |     |     |
| Case 2: | 0      |     |     |