11541 Decoding

Encoding is the process of transforming information from one format into another. There exist several
diﬀerent types of encoding scheme. In this problem we will talk about a very simple encoding technique;
Run-Length Encoding.

Run-length encoding is a very simple and easy form of data compression in which consecutive
occurrences of the same characters are replaced by a single character followed by its frequency. As an
example, the string ‘AABBBBDAA’ would be encoded to ‘A2B4D1A2’, quotes for clarity.

In this problem, we are interested in decoding strings that were encoded using the above procedure.

Input

The (cid:12)rst line of input is an integer T (T < 50) that indicates the number of test cases. Each case is
a line consisting of an encoded string. The string will contain only digits [0-9] and letters [A-Z]. Every
inputted string will be valid. That is, every letter will be followed by 1 or more digits.

Output

For each case, output the case number followed by the decoded string. Adhere to the sample for exact
format.

You may assume the decoded string wont have a length greater than 200 and it will only consist of

upper case alphabets.

Sample Input

3
A2B4D1A2
A12
A1B1C1D1

Sample Output

Case 1: AABBBBDAA
Case 2: AAAAAAAAAAAA
Case 3: ABCD

