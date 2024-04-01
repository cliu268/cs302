// https://www.xinyoudui.com/ac/contest/77700148C0002E1011A2DF/problem/1062
/*
3.  Floyd Warshall Algorithm
XJOI - Problem ID: 1062Bonus Problem100pt(s)
https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
https://usaco.guide/CPH.pdf#page=139 - read 13.3

Description:
Use the Floyd Warshall algorithm to find any two-point shortest path. Output the shortest path value for the two given pairs of nodes 
separately, and list the path nodes with the smallest lexicographic order.

i.e. If asked to find the path between 4 and 7 and we have two paths 4-1-3-7 and 4-3-7 with the same weights, the correct output is 4-1-3-7. 
The path 4-1-3-7 has smaller lexicographic order.

Input :
The first line has two integers s1, t1;
The second line has two integers s2, t2;
The third line has two integers n, m
The following m lines have three integers a, b, and c for each line, indicating that there is an undirected edge between a and b, 
and the weight of the edge is c.
Note: There may be multiple edges with the same a and b but different weights.

Output :
First line: the distance of the shortest path from s1 to t1.
Second line: list the node on the path from s1 to t1.
Third line: the distance of the shortest path from s2 to t2.
Fourth line: list the node on the path from s2 to t2.

Sample input:
1 3
2 5
5 7
1 2 6
1 4 2
1 5 23
2 3 4
2 4 3
3 4 20
3 5 7

Sample output:
9
1 4 2 3
11
2 3 5 

Data range: n<=200,m<=40000,c<=10^9
Time limit: 1000
Memory limit: 65536
*/