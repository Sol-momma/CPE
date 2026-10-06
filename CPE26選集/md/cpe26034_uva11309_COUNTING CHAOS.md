| 11309 | Counting | Chaos |     |     |
| ----- | -------- | ----- | --- | --- |
WolfgangPuck’srival,EmerilLagasse(“BAM!”),recentlysettheworld
culinaryrecordinthecategoryofsmallestsoufflémeasuringinatamere
2cm! Wolfgang,nottobeoutdone,decidedthathewouldsetaculinary
record of his own: the most symmetric marble cake in the world. This
| is clearly | not an easy feat!        |             |            |              |
| ---------- | ------------------------ | ----------- | ---------- | ------------ |
| As we      | all know from Wolfgang’s | bestselling | biography, | he is a very |
superstitious chef. In his attempts to create the symmetric cake, he has
vowedtoremovethecakefromtheovenonlyatapalindromictime,i.e.,
a time that reads the same when read from left-to-right as right-to-left.
Not including the current time, when is the next opportunity for Wolfgang to remove his cake?
Input
On the first line of the input you are given n, the number of attempts Wolfgang makes to make his
symmetric cake. The following n lines contain a string formatted as ‘HH:MM’ indicating the current
|     |     | (cid:20) | (cid:20) | (cid:20) (cid:20) |
| --- | --- | -------- | -------- | ----------------- |
time on a twenty-four hour clock. (So 0 HH 23 and 0 MM 59 and ‘00:00’ follows “23:59”)
Output
For each attempt, output a string indicating the next palindromic time (not including the current time)
on a single line formatted as ‘HH:MM’. When determining if HH : MM is palindromic, ignore all
leading zeroes in HH. If HH is zero then ignore all leading zeroes in MM.
| Sample Input |     |     |     |     |
| ------------ | --- | --- | --- | --- |
3
00:00
23:30
14:59
| Sample Output |     |     |     |     |
| ------------- | --- | --- | --- | --- |
00:01
23:32
15:51