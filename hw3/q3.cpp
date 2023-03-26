// C. Binary tree traverse
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9745&fragments=17996&problemId=1041&pattern=0
/*
Time Limit：1s   Memory Limit：256M
Description
Given a binary tree, please output the preorder traversal, inorder traversal, postorder traversal. N<=100

Input
A binary tree:
the first line is an integer representing the number of nodes.
From the second line,each line contains three numbers,the first is the node number,second is the left child of this node,third is the 
right child of this node.

Output
The first line is the preorder traversal,
the second line is the inorder traversal,
the third line is the postorder traversal.
Each number is separated with a space.

Sample Input
5
1 2 3
2 4 5
3 0 0
4 0 0
5 0 0

Sample Output
1 2 4 5 3
4 2 5 1 3
4 5 2 3 1
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree(101);
void InOrder(int x) {
  if (tree[x].first!=0) {
    InOrder(tree[x].first);
  }
  cout<<x<<" ";
  if (tree[x].second!=0) {
    InOrder(tree[x].second);
  }
}
void preOrder(int x) {
  cout<<x<<" ";
  if (tree[x].first!=0) {
    preOrder(tree[x].first);
  }
  if (tree[x].second!=0) {
    preOrder(tree[x].second);
  }
}
void postOrder(int x) {
  if (tree[x].first!=0) {
    postOrder(tree[x].first);
  }
  if (tree[x].second!=0) {
    postOrder(tree[x].second);
  }
  cout<<x<<" ";
}
int main() {
  int n; cin>>n;
  for (int i=0; i<n; i++) {
    int a, b, c; cin>>a>>b>>c;
    tree[a]={b, c};
  }
  preOrder(1);
  cout<<"\n";
  InOrder(1);
  cout<<"\n";
  postOrder(1);
}