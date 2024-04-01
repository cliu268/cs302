// https://www.xinyoudui.com/ac/contest/7770014000002E1011A18E/problem/8818
/*
3.  The Rank of Binary Search Tree
XJOI - Problem ID: 8818Bonus Problem100pt(s)

Description：
You have to write a data structure to maintain some data. The following operations should be provided:
1. Insert number x
2. Delete x（If there are several identical numbers, only delete one of them）
3. Find the rank of x（if there are several identical numbers, print the rank with the smallest value）
4. Find the number whose rank is x
5. Find the predecessor of x （defined as the largest number that is less than x）
6. Find the successor of x（defined as the smallest number which is greater than x）

Input：
The first line contains an integer n，which is the number of operations. 
The next n lines each contain two numbers opt and x. opt is the number of the operation（1 ≤ opt ≤ 6）.

Output：
For operations 3、4、5、6, print the answer to the operation.

Sample input 1：
10
1 92
1 91
3 91
4 1
1 50
4 2
1 100
1 64
1 64
6 59

Sample output 1：
1
91
91
64

Note：
1 <= n <= 500
Rank of node x: the number of the nodes whose values are ≤x .
*/