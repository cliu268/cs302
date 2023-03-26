// B. Tree Width
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9735&fragments=18204&problemId=9521&pattern=0
/*
Description：
Given a tree with n nodes numbered from 1 to N, among which 1 means the root. Please find out the width of the tree.

Input：
The first line contains a number N (1<=N<=1000).
The next N lines, each line contains N single digit numbers (each could be either 1 or 0). When the i-th row and j-th column is 1, 
it means nodes i and j have an edge. Otherwise, there is no edge. 

Output：
the width of the tree

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

Sample output：
4
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> child(1001);
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
  vector<int> store(1001, 0);
  queue<vector<int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    vector<int> curr=q.front();
    store[curr[1]]++;
    q.pop();
    for (int i : child[curr[0]]) {
      if (i==curr[2]) {
        continue;
      }
      q.push({i, curr[1]+1, curr[0]});
    }
  }
  int ans=0;
  for (int i : store) {
    ans=max(i, ans);
  }
  cout<<ans<<"\n";
}