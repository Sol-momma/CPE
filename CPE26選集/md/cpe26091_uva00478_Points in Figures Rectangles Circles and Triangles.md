| 478 | Points | in  | Figures: |     | Rectangles, |     | Circles, | and Triangles |
| --- | ------ | --- | -------- | --- | ----------- | --- | -------- | ------------- |
Given a list of figures (rectangles, circles, and triangles) and a list of points in the x-y plane, determine
| for each | point which | figures | (if | any) | contain | the point. |     |     |
| -------- | ----------- | ------- | --- | ---- | ------- | ---------- | --- | --- |
Input
There will be n( 10) figures descriptions, one per line. The first character will designate the type of
figure (“r”, “c”, “t” for rectangle, circle, or triangle, respectively). This character will be followed by
| values which | describe | that | figure. |     |     |     |     |     |
| ------------ | -------- | ---- | ------- | --- | --- | --- | --- | --- |
• For a rectangle, there will be four real values designating the x-y coordinates of the upper left
| and | lower right | corners. |     |     |     |     |     |     |
| --- | ----------- | -------- | --- | --- | --- | --- | --- | --- |
• For a circle, there will be three real values, designating the x-y coordinates of the center and the
radius.
• For a triangle, there will be six real values designating the x-y coordinates of the vertices.
The end of the list will be signalled by a line containing an asterisk in column one.
The remaining lines will contain the x-y coordinates, one per line, of the points to be tested. The
end of this list will be indicated by a point with coordinates 9999.9 9999.9; these values should not be
| included | in the output. |      |          |        |     |                    |         |     |
| -------- | -------------- | ---- | -------- | ------ | --- | ------------------ | ------- | --- |
| Points   | coinciding     | with | a figure | border |     | are not considered | inside. |     |
Output
| For each | point to     | be tested, | write     | a   | message | of the form: |     |     |
| -------- | ------------ | ---------- | --------- | --- | ------- | ------------ | --- | --- |
| Point i  | is contained |            | in figure |     | j       |              |     |     |
for each figure that contains that point. If the point is not contained in any figure, write a message of
the form:
i
| Point      | is not        | contained | in        | any      | figure |      |     |     |
| ---------- | ------------- | --------- | --------- | -------- | ------ | ---- | --- | --- |
| Points     | and figures   |           | should be | numbered |        | in   |     |     |
| the order  | in which      | they      | appear    | in the   | input. |      |     |     |
| Note: See  | the picture   |           | on the    | right    | for a  | dia- |     |     |
| gram of    | these figures | and       | data      | points.  |        |      |     |     |
| Sample     | Input         |           |           |          |        |      |     |     |
| r 8.5 17.0 | 25.5          | -8.5      |           |          |        |      |     |     |
| c 20.2     | 7.3 5.8       |           |           |          |        |      |     |     |
| t -1.0     | -1.0 10.1     | 2.2       | .4 1.4    |          |        |      |     |     |
| r 0.0 10.3 | 5.5           | 0.0       |           |          |        |      |     |     |
| c -5.0     | -5.0 3.7      |           |           |          |        |      |     |     |
| t 20.3     | 9.8 10.0      | -3.2      | 17.5      | -7.7     |        |      |     |     |
| r 2.5 12.5 | 12.5          | 2.5       |           |          |        |      |     |     |
| c 5.0 15.0 | 7.2           |           |           |          |        |      |     |     |

Universidad de Valladolid OJ: 478 – Points in Figures: Rectangles, Circles, and Triangles 2/2
| t -10.0 | -10.0 10.0 | 25.0 30.0 | -10.0 |
| ------- | ---------- | --------- | ----- |
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
| 9999.9 9999.9 |                  |           |            |
| ------------- | ---------------- | --------- | ---------- |
| Sample        | Output           |           |            |
| Point 1       | is contained     | in figure | 4          |
| Point 1       | is contained     | in figure | 9          |
| Point 2       | is contained     | in figure | 4          |
| Point 2       | is contained     | in figure | 7          |
| Point 2       | is contained     | in figure | 9          |
| Point 3       | is contained     | in figure | 7          |
| Point 3       | is contained     | in figure | 8          |
| Point 3       | is contained     | in figure | 9          |
| Point 4       | is not contained | in        | any figure |
| Point 5       | is contained     | in figure | 1          |
| Point 5       | is contained     | in figure | 2          |
| Point 5       | is contained     | in figure | 6          |
| Point 5       | is contained     | in figure | 9          |
| Point 6       | is contained     | in figure | 5          |
| Point 6       | is contained     | in figure | 9          |