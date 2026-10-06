11039 Building designing

An architect wants to design a very high building. The building will consist of some floors, and each
floor has a certain size. The size of a floor must be greater than the size of the floor immediately
above it. In addition, the designer (who is a fan of a famous Spanish football team) wants to paint
the building in blue and red, each floor a colour, and in such a way that the colours of two consecutive
floors are different.

To design the building the architect has n available floors, with their associated sizes and colours.
All the available floors are of different sizes. The architect wants to design the highest possible building
with these restrictions, using the available floors.

Input

The input file consists of a first line with the number p of cases to solve. The first line of each case
contains the number of available floors. Then, the size and colour of each floor appear in one line. Each
floor is represented with an integer between -999999 and 999999. There is no floor with size 0. Negative
numbers represent red floors and positive numbers blue floors. The size of the floor is the absolute
value of the number. There are not two floors with the same size. The maximum number of floors for
a problem is 500000.

Output

For each case the output will consist of a line with the number of floors of the highest building with
the mentioned conditions.

Sample Input

2
5
7
-2
6
9
-3
8
11
-9
2
5
18
17
-15
4

Sample Output

2
5

