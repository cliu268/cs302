// https://www.xinyoudui.com/ac/contest/7770016590002E1011B50F/problem/15507
/*
4.  Moo Network
XJOI - Problem ID: 15507 Bonus Problem 100pt(s)

Description
Farmer John's N cows (1≤N≤10^5) are spread far apart on his farm and would like to build a communication network so they can more 
easily exchange electronic text messages (all of which of course contain variations of "moo").

The ith cow is located at a distinct location (xi,yi) where 0 ≤ xi ≤ 10^6 and 0 ≤ yi ≤10. The cost of building a communication link between 
cows i and j is the squared distance between them: (xi - xj)^2 + (yi - yj)^2.

Please calculate the minimum cost required to build a communication network across which all the cows can communicate. 
Two cows can communicate if they are directly connected by a link, or if there is a sequence of links along which their message can travel.

**Note: the time limit for this problem is 4s, twice the default.**

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains N, and the next N lines each describe the x and y coordinates of a cow, all integers.

OUTPUT FORMAT (print output to the terminal / stdout):
Please output the minimum cost of a network that will allow all cows to communicate. Note that this cost might be too large to fit into a 
32-bit integer and may require use of 64-bit integers (e.g., "long long" integers in C++).

SAMPLE INPUT:
10
83 10
77 2
93 4
86 6
49 1
62 7
90 3
63 4
40 10
72 0

SAMPLE OUTPUT:
660

SCORING:
Test cases 2-3 satisfy N≤1000.
Test cases 4-15 satisfy no additional constraints.

Problem credits: Brian Dean
*/