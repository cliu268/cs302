// E. I Would Walk 500 Miles
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9786&fragments=18047&problemId=15399&pattern=0
/*
Farmer John wants to divide his N cows (N≤7500), conveniently numbered 1…N, into K non-empty groups (2≤K≤N) such that no two cows from two 
different groups can interact with each other without walking some number of miles. Cow x and Cow y (where 1≤x<y≤N) are willing to walk 
(2019201913x+2019201949y) mod 2019201997 miles to see each other.

Given a division of the N cows into K non-empty groups, let M be the minimum of the number of miles any two cows in two different groups 
are willing to walk to see each other. To test the cows' devotion to each other, Farmer John wants to optimally divide the N cows into K 
groups such that M is as large as possible.

The memory limit for this problem is set to 512MB, above the usual 256MB limit.

INPUT FORMAT (file walk.in):
The input is just one line, containing N and K, separated by a space.

OUTPUT FORMAT (file walk.out):
Print out M in an optimal solution.

SAMPLE INPUT:
3 2

SAMPLE OUTPUT:
2019201769

In this example, Cow 1 and Cow 2 are willing to walk 2019201817 miles to see each other. Cow 2 and Cow 3 are willing to walk 2019201685 miles. 
And Cow 1 and Cow 3 are willing to walk 2019201769 miles. Thus, by grouping the cows such that 1 is by herself and 2 and 3 are grouped 
together, M=min(2019201817,2019201769)=2019201769 (which is the best we can do here).

Problem credits: Brian Dean
*/