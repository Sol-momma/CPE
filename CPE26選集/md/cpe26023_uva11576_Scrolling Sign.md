11576 Scrolling Sign

Electric scrolling signs are often used for advertising. A given sign displays exactly k characters. When
the sign is switched on, all of the character positions are initially empty (showing spaces). In each time
interval, all of the characters on the sign are shifted to the left by one position, and a new character is
added at the right-most position. The character that was in the left-most position moves off the sign.
For certain sequences of words, it is possible to reuse characters from one word to form a subsequent
word. For example, on a sign with three character positions, the sign can display the message CAT
ATE TED by scrolling in the five characters CATED.

The advertiser has a specific message to show using the sign. The faster the message is displayed,
the more people will be able to see the whole message. Therefore, your job is to find a way to display all
the words of the message by scrolling in the smallest number of letters. In between showing the words
of the message, the sign may display other words that are not considered part of the message. However,
the words of the message must be shown in the order in which they are given. If a word appears two
or more times consecutively in the message, the sign only needs to show it once.

Input

The first line of input contains a single integer n, the number of test cases to follow. Each test case
starts with a line containing a two integers, k, the number of character positions on the sign, and w,
the number of words in the message. Each of the two integers is between 1 and 100, inclusive. The
following w lines each contain a word of the message comprising exactly k uppercase letters.

Output

For each test case, output a line containing a single integer, the minimum number of letters that must
be scrolled into the sign so that it displays all the words of the message.

Sample Input

2
3 2
CAT
TED
3 3
CAT
ATE
TEA

Sample Output

5
5

