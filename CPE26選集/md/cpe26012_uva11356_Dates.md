| 11356 | Dates |     |     |        |           |                |           |     |
| ----- | ----- | --- | --- | ------ | --------- | -------------- | --------- | --- |
|       |       |     |     |        | 30 days   | has September, |           |     |
|       |       |     |     | April, | June      | and November   |           |     |
|       |       |     |     |        | All the   | rest have      | 31        |     |
|       |       |     |     | And    | Februarys | great          | with 28   |     |
|       |       |     | And | Leap   | Years     | Februarys      | fine with | 29  |
The Gregorian calendar, the current standard calendar in most part of the world, adds a 29-th day
to February in all years evenly divisible by 4, except for centennial years (those ending in -00) which
are not evenly divisible by 400. Thus 1600, 2000 and 2400 are leap years but 1700, 1800, 1900, 2100,
| 2200 and | 2300 are | not. |     |     |     |     |     |     |
| -------- | -------- | ---- | --- | --- | --- | --- | --- | --- |
In this problem, we are concerned with dates. You will be given a date and an integer K. You have
| to find | the date in | the calendar |     | after | K days | from the given | date. |     |
| ------- | ----------- | ------------ | --- | ----- | ------ | -------------- | ----- | --- |
Input
The first line of input is an integer T (T < 50) that represents the number of test cases. Each case
contains two lines. The first line is a date in the format ‘yyyy-month-dd’. year is an integer in the
range [1900, 3000], month is a string from the set {January, February, March, April, May, June,
July, August, September, October, November and December} and dd is an integer in the range
| [01,31]. | The second | line    | contains | an   | integer K | (0 < K < | 10000). |     |
| -------- | ---------- | ------- | -------- | ---- | --------- | -------- | ------- | --- |
| The      | input date | will be | a valid  | one. |           |          |         |     |
Output
For each input, output the case number followed by the date after K days in the same format as that
| of input. | Look at the | sample | for | exact | format. |     |     |     |
| --------- | ----------- | ------ | --- | ----- | ------- | --- | --- | --- |
| Sample    | Input       |        |     |       |         |     |     |     |
2
1984-December-30
2
1984-October-12
318
| Sample  | Output          |     |     |     |     |     |     |     |
| ------- | --------------- | --- | --- | --- | --- | --- | --- | --- |
| Case 1: | 1985-January-01 |     |     |     |     |     |     |     |
| Case 2: | 1985-August-26  |     |     |     |     |     |     |     |