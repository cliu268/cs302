// A. Tree Depth
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9735&fragments=18204&problemId=9520&pattern=0
// https://www.xinyoudui.com/ac/contest/7740019EE0002E10119DCD/problem/9520
/*
Description：
Given a tree with N nodes numbered from 1 to N, where the node numbered 1 is the root, find the depth of the tree (distance from the root 
to the furthest leaf node).

Input：
The first line contains a number N. （1<=N<=1000）
The next N lines each contains N single-digit numbers (1 or 0 only). 
A '1' at column j and row i represents an edge between node i and j and a '0' represents no edge between i and j.

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
// Etaw
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

// Ev
// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> tree;
// int n;
// int ans;

// void dfs(int s, int temp, int p){
//     ans = max(ans, temp);
//     for(int i=0; i<tree[s].size(); i++){
//         if(tree[s][i]==1 && i!=p){
//             dfs(i, temp+1, s);
//         }
//     }
//     }
    

// int main(){
//     cin >> n;
//     for(int i=0; i<n; i++){
//         string s;
//         cin >> s;
//         vector<int> row(n);
//         for(int j=0; j<n; j++){
//             if(s[j] == '0'){
//                 row[j]=0;
//             } 
//             else{
//                 row[j]=1;
//             }
//         }
//         tree.push_back(row);
//     }
//     dfs(0, 0, -1);
//     cout << ans;
// }