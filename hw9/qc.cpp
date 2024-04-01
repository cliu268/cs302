// https://www.xinyoudui.com/ac/contest/7770016550002E1011A37E/problem/1541
/*
3.  Telephone Connection (dial)
XJOI - Problem ID: 1541 Required Problem 100pt(s)

Problem Description:
There are n cities in a country. There are telephone lines connecting several cities. Now we need to add m telephone lines so that any 
two cities can connect directly or indirectly with each other through telephone lines in other cities. Your program should be able to 
find a plan that connects all nodes and uses minimum total cost.

Input:
The first line of the input file is the value of n (n<=100).
The second row to the n+1th row is an n*n matrix, and if the number of the i-th row and the j-th column is 0, 
it indicates that the city i has a telephone line connecting with the city j, 
otherwise the the number refers to the connection fee between the two cities is (The range does not exceed 10,000).

Output:
The first line of the output file is the total number m of phone lines you connect to,
The second line is the total cost of connecting these lines.

Sample input:
5
0 15 27 6 0
15 0 33 19 11
27 33 0 0 17
6 19 0 0 9
0 11 17 9 0

Sample output:
2
17

Data range: n<=100
Time limit: 1000
Memory limit: 65536
*/