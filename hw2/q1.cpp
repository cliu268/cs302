// A. The distance between nodes
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9740&fragments=18207&problemId=9523&pattern=0
/*
Description：
Given a tree with n nodes numbered from 1 to N, among which 1 is for the root. Please find out the distance between each two nodes.

Input：
The first line contains a number N
The next N lines, each line contains N numbers (each could be either 1 or 0). when the i-th row and j-th column is 1, it means 
nodes i and j have an edge. Otherwise, there is no edge.

Output：
The distance between each two nodes on the tree.

Sample Input:
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

Sample Output:
0 1 1 2 2 2 3 4 4 2 
1 0 2 1 3 3 4 5 5 3 
1 2 0 3 1 1 2 3 3 1 
2 1 3 0 4 4 5 6 6 4 
2 3 1 4 0 2 3 4 4 2 
2 3 1 4 2 0 1 2 2 2 
3 4 2 5 3 1 0 1 1 3 
4 5 3 6 4 2 1 0 2 4 
4 5 3 6 4 2 1 2 0 4 
2 3 1 4 2 2 3 4 4 0 
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> child(1000);
vector<vector<int>> path(1000);
vector<int> depth(1000);
int n;

void dfs(int x, vector<bool> &visited) {
  depth[x]=path[x].size()-1;
  for (int i : child[x]) {
    if (visited[i]) {
      continue;
    }
    path[i]=path[x];
    path[i].push_back(i);
    visited[i]=true;
    dfs(i, visited);
  }
}
int LCA(int x, int y) {
  for (int i=0; i<=min(depth[x], depth[y]); i++) {
    if (path[x][i]!=path[y][i]) {
      return path[x][i-1];
    }
  }
  return path[x][min(depth[x], depth[y])];
}
int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    string s; cin>>s;
    for (int j=0; j<n; j++) {
      if (s[j]=='1') {
        child[i].push_back(j);
        child[j].push_back(i);
      }
    }
  }
  path[0]={0};
  vector<bool> visited(n, false); visited[0]=true;
  dfs(0, visited);
  vector<vector<int>> ans(n, vector<int>(n, -1));
  for (int i=0; i<n; i++) {
    for (int j=i; j<n; j++) {
      int ancestor = LCA(i, j);
      ans[i][j] = depth[i] + depth[j] - 2*depth[ancestor];
    }
  }
  for (int i=1; i<n; i++) {
    for (int j=0; j<i; j++) {
      ans[i][j]=ans[j][i];
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}