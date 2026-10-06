| 10800 | Not That | Kind | of  | Graph      |               |                  |              |
| ----- | -------- | ---- | --- | ---------- | ------------- | ---------------- | ------------ |
|       |          |      |     | “You know, | it’s all very | sweet, stealing  | from the     |
|       |          |      |     |            |               | rich, selling to | the poor...” |
|       |          |      |     |            | Jose          | Molina,          | "Firefly."   |
Your task is to graph the price of a stock over time. In one unit of time, the stock can either Rise,
Fall or stay Constant. The stock’s price will be given to you as a string of R’s, F’s and C’s. You need
to graph it using the characters ’/’ (slash), ’\’ (backslash) and ’_’ (underscore).
Input
The first line of input gives the number of cases, N. N test cases follow. Each one contains a string of
| at least 1 | and at most | 50 upper case | characters | (R, F or C). |     |     |     |
| ---------- | ----------- | ------------- | ---------- | ------------ | --- | --- | --- |
Output
For each test case, output the line ‘Case #x:’, where x is the number of the test case. Then print the
graph, as shown in the sample output, including the x- and y-axes. The x-axis should be one character
longer than the graph, and there should be one space between the y-axis and the start of the graph.
There should be no trailing spaces on any line. Do not print unnecessary lines. The x-axis should
always appear directly below the graph. Finally, print an empty line after each test case.
| Sample Input |     |     |     |     |     |     |     |
| ------------ | --- | --- | --- | --- | --- | --- | --- |
1
RCRFCRFFCCRRC
| Sample Output |     |     |     |     |     |     |     |
| ------------- | --- | --- | --- | --- | --- | --- | --- |
Case #1:
| |        | _    |     |     |     |     |     |     |
| -------- | ---- | --- | --- | --- | --- | --- | --- |
| | _/\_/\ | /    |     |     |     |     |     |     |
| | /      | \__/ |     |     |     |     |     |     |
+---------------