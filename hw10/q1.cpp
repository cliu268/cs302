// A. Binary Tree Traversal 
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=12599&fragments=30285&problemId=8801&pattern=0
/*
Description：
Given a binary tree whose root is 1, output its pre-order traversal.

Input：
The first line contains a positive integer n --- number of vertices
The next n lines: the two positive integers are left and right children of vertex 1. If there is no child, output -1.

Output：
A single line, output n positive integers, which is the answer

Sample input 1：
3
2 3
-1 -1
-1 -1

Sample output 1：
1 2 3

Note：1<=n<=100
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree(101);
void pre(int x) {
	cout<<x<<" ";
    if (tree[x].first!=-1) {
        pre(tree[x].first);
    }
    if (tree[x].second!=-1) {
        pre(tree[x].second);
    }
}
int main() {
    int n; cin>>n;
    for (int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
		tree[i+1]={a, b};
    }
    pre(1);
}