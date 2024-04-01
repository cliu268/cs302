// https://www.xinyoudui.com/ac/contest/77700164C0002E1011A282/problem/1566
/*
3.  Base Price - use Prim's Algo
XJOI - Problem ID: 1566 Required Problem 100pt(s)
https://en.wikipedia.org/wiki/Prim%27s_algorithm
https://usaco.guide/CPH.pdf#page=157 - read section 15.3

Description:
In digital construction, a certain number of LANs must be established in a certain area. Each point is included in one LAN and there 
may be multiple LANs. Given the cost of connecting certain points, you need to minimize the cost of connecting each point to a LAN. 
Connecting two points means they belong to the same LAN. 
In other words, write a program to find the minimum cost of including each point in a LAN (see Explanation for more details).

LAN: local area network.

Input：
The first line N, M. N represents the number of points, M represents the number of edges, 1<=N, M<=1000
The following M lines: the first two numbers indicate two points, and the third number is the cost on the side

Output：
A number indicating the base price

Sample input：
7  9
1  2  1
1  3  2
2  3  3
4  5  1
4  7  3
5  6  2
6  7  4
4  6  5
5  7  8

Sample output：
9

Explanation:
We have 2 LANs in total. The LANs are as follows:
a) 1 - 2 - 3
b) 7 - 4 - 5 - 6
We can connect points (1,2) and points (2,3). This creates a LAN. The cost is 1 + 2 = 3.
We can also connect points (7,4), (4,5), and (5,6). This also creates a LAN. The total cost is 3 + 1 + 2 = 6.
The total cost of including every point in a LAN is 3 + 6 = 9.
https://staticw.turingstar.com.cn/202311201232/0ae214c405ecaf9e7f011f04ff2f6ffe/bd7e6386-a279-4a4d-8962-20e85ec89acb

Data range： 1<=N,M<=1000
Time limit： 1000
Memory limit： 65536
*/