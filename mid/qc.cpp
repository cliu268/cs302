// https://www.xinyoudui.com/ac/contest/7770019F20002E1011A215/problem/9523
/*
3.  The distance between nodes
XJOI - Problem ID: 9523 Required Problem 100pt(s)

Description：
Given a tree with N nodes numbered from 1 to N, among which 1 is for the root. Please find out the distance between each two nodes.

Input Format:
The first line contains a number N. （1<=N<=1000）

The next N lines each contain N single-digit numbers (1 or 0 only). A '1' at column j and row i represents an edge between node i and j, 
and a '0' represents no edge between i and j.

Output Format:
An N x N space separated matrix where the output at row i and column j represents the distance from node i and j.

Sample Input:
10
0110000000
1001000000
1000110001
0100000000
0010000000
0010001000
0000010110
0000001000
0000001000
0010000000

Sample Output:
0 1 1 2 2 2 3 4 4 2 
1 0 2 1 3 3 4 5 5 3 
1 2 0 3 1 1 2 3 3 1 
2 1 3 0 4 4 5 6 6 4 
2 3 1 4 0 2 3 4 4 2 
2 3 1 4 2 0 1 2 2 2 
3 4 2 5 3 1 0 1 1 3 
4 5 3 6 4 2 1 0 2 4 
4 5 3 6 4 2 1 2 0 4 
2 3 1 4 2 2 3 4 4 0 
*/