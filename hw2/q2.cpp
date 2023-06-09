// B. Center of the Tree
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9740&fragments=18207&problemId=9503&pattern=0
/*
题目描述：
读入一棵无根的树。定义一个节点的权值为：去掉这个点后，所有树中最大的那棵树的大小。
请求出权值最小的点的权值。这样的点我们称为树的重心。
树的读入格式：第一行一个整数n表示节点数，之后n-1行每行两个整数x、y，表示一条连接x和y的边，保证输入的图形成一棵树。

输入格式：
如题目描述

输出格式：
权值最小的点的权值。

样例输入1：
6
2 1
2 3
2 4
2 5
6 5

样例输出1：
2

约定： 2<=n<=100000
*/