// B. Insert binary search tree
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9745&fragments=17996&problemId=8816&pattern=0
/*
Time limit：1s   Memory limit：256M
Description：
You have to write a data structure to maintain some data. The following operation should be provided:
1. Insert x ；
5. Find the precedence of x （defined as the maximum number which is smaller than x）；
6. Find the successor of x（defined as the minimum number which is bigger than x）。
Input：
The first line contains the number n，which is the number of operations. The next n lines each contains two numbers opt and x. 
opt is the order number of operations（1≤opt≤6）.

Output：
For operations 3、4、5、6, print a number in each line, which is the answer.

Sample input 1：
5
1 75
1 21
6 74
6 74
5 22

Sample output 1：
75
75
21

Note：1 <= n <= 500
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> tree(10000001, -1);
void fill(int ind, int x) {
  if (tree[ind]==x) {
    return;
  }
  if (tree[ind]==-1) {
    tree[ind]=x;
    return;
  }
  else {
    if (x>tree[ind]) {
      fill(ind*2+1, x);
    }
    else {
      fill(ind*2, x);
    }
  }
}
int maxi=0;
void pre(int ind, int x) {
  if (tree[ind]==-1) {
    return;
  }
  if (tree[ind]<x) {
    maxi=max(maxi, tree[ind]);
  }
  pre(ind*2+1, x);
  pre(ind*2, x);
}
int mini=INT_MAX;
void suc(int ind, int x) {
  if (tree[ind]==-1) {
    return;
  }
  if (tree[ind]>x) {
    mini=min(mini, tree[ind]);
  }
  suc(ind*2, x);
  suc(ind*2+1, x);
}
int main() {
  int n; cin>>n;
  vector<int> ans;
  for (int i=0; i<n; i++) {
    int a, b; cin>>a>>b;
    if (a==1) {
      fill(1, b);
    }
    else if (a==5) {
      pre(1, b);
      ans.push_back(maxi);
      maxi=0;
    }
    else {
      suc(1, b);
      ans.push_back(mini);
      mini=INT_MAX;
    }
  }
  // for (int i=1; i<=8; i++) {
  //   cout<<tree[i]<<" ";
  // }
  // cout<<"\n";
  for (auto i : ans) {
    cout<<i<<"\n";
  }
}