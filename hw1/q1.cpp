// A. Tree Depth
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9735&fragments=18204&problemId=9520&pattern=0
/*
Description：
Given a tree with N nodes numbered from 1 to N, among which 1 is the number for the root. Please find out the depth of the tree.

Input：
The first line contains a number N. （1<=N<=1000）
In the next N lines, each line contains N single-digit numbers (each could be 1 or 0 only). When the value at j-th column and i-th row is 1, 
it means node i and j have an edge in between. Otherwise, there is no edge. 

Output：
The depth of the tree.

Sample Input：
10
0110000000
1001000000
1000110001
0100000000
0010000000
0010001000
0000010110
0000001000
0000001000
0010000000 

Sample Output：
4
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> child(1001);
int ans=0;
void dfs(int x, int prev, int count) {
  for (int i : child[x]) {
    if (i==prev) {
      continue;
    }
    dfs(i, x, count+1);
  }
  ans=max(ans, count);
}
int main() {
  int n; cin>>n;
  for (int i=0; i<n; i++) {
    string s; cin>>s;
    for (int j=0; j<n; j++) {
      if (s[j]=='1') {
        child[i].push_back(j);
      }
    }
  }
  dfs(0, -1, 0);
  cout<<ans<<"\n";
}