// https://www.xinyoudui.com/ac/contest/7770016550002E1011A37E/problem/14126
/*
1.  Road Construction
XJOI - Problem ID: 14126 Required Problem 100pt(s)

Description:
There are n cities and initially no roads between them. However, every day a new road will be constructed, and eventually there will be 
a total of m roads.
A cluster is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the 
number of clusters and the size of the largest cluster.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.
Then, there are m lines describing the new roads. 
Each line has two integers a and b representing a new road being constructed between cities a and b.
You may assume that every road will be constructed between two different cities.

Output
Print m lines, each line containing two integers: the number of clusters and the size of the largest cluster after building the road.

Sample input:
5 3
1 2
1 3
4 5

Sample output:
4 2
3 3
2 3

Constraints
1 ≤ n ≤ 10^5
1 ≤ m ≤ 2⋅10^5
1 ≤ a,b ≤ n 
Time limit: 1.00 s
Memory limit: 256 MB
*/