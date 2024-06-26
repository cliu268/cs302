// C. Binary Tree of Xiao Yin
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9758&fragments=18065&problemId=7087&pattern=0
// https://www.xinyoudui.com/ac/contest/7740019EF0002E10119FCE/problem/7087 - cs302 hw2 qd.cpp
/*
Ivan has a binary tree, but he only remembers the tree's preorder traversal sequence and the inorder traversal sequence. 
Now he wants you to write a program to find the tree's post-traverse sequence.

Input Format
The input contains multiple sets of test data.
Each group of data is only one line and contains two strings consisting of only uppercase Latin letters, representing the preorder 
traverse sequence and the inorder traverse sequence.
String length is less than or equal to 26.
Read until the end of the file.

Output Format
For each set of data, a row of output is given, containing a string that represents the sequence of postorder traverses.

Sample Input
DBACEGF ABCDEFG
BCAD CBAD

Sample Output
ACBFGED
CDAB

Time and memory limit 1S, 256M
*/
// Hints viedeo: https://www.xinyoudui.com/courses/361#/pages/9758 ==> Problem Solution Button