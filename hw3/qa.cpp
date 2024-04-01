// https://www.xinyoudui.com/ac/contest/7770014000002E1011A18E/problem/8802
/*
1.  Inorder traversal of a Binary Tree
XJOI - Problem ID: 8802Required Problem100pt(s)

Description：
Given a binary tree whose root is 1, output its inorder traversal (LDR).
Please refer to the "input" section for the input format of the tree.

Input：
The 1st line: a positive integer n  which depicts the node number.
The next n lines: the i-th line contains two positive integers --- the left and right children of node i. If there is no child, output -1.

Output：
A single line containing n positive integers which is the answer (inorder traversal).

Sample Input 1：
3
2 3
-1 -1
-1 -1

Sample Output 1：
2 1 3

Note：
1<=n<=100
*/
// Ev
#include<bits/stdc++.h>
using namespace std;

struct node{
    int left = -1;
    int right = -1;
}tree[101];

void inorder(int a){
    if(a==-1){
        return;
    }
    inorder(tree[a].left);
    cout << a << " ";
    inorder(tree[a].right);
}

int main(){
    int n; cin >> n;
    for(int i=1; i<n+1; i++){
        cin >> tree[i].left >> tree[i].right;
    }
    inorder(1);
}