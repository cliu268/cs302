// A. Inorder traversal of a Binary Tree
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9745&fragments=17996&problemId=8802&pattern=0
/*
Time limit：0.2   Memory limit：32M

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
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree(101);
void traverse(int x) {
  if (tree[x].first!=-1) {
    traverse(tree[x].first);
  }
  cout<<x<<" ";
  if (tree[x].second!=-1) {
    traverse(tree[x].second);
  }
}
int main() {
  int n; cin>>n;
  for (int i=0; i<n; i++) {
    int a, b; cin>>a>>b;
    tree[i+1]={a, b};
  }
  traverse(1);
}