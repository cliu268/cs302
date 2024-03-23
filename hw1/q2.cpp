// B. Tree Width
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9735&fragments=18204&problemId=9521&pattern=0
// https://www.xinyoudui.com/ac/contest/7740019EE0002E10119DCD/problem/9521
/*
Description：
Given a tree with N nodes numbered from 1 to N, where the node numbered 1 is the root, find the width of the tree. 
The width of the tree at a level/layer is the number of nodes in that layer, and the width of the entire tree is the width of the largest 
level/layer.

Input：
The first line contains a number N (1<=N<=1000).
The next N lines each contain N single-digit numbers (1 or 0 only). A '1' at column j and row i represents an edge between 
node i and j and a '0' represents no edge between i and j.

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
// Etaw
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

// Ev
// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> tree;

// int main(){
//     int n; cin >> n;

//     queue<int> q;
//     int ans=0;
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

//     q.push(0);
//     vector<int> visited(n, 0);
//     visited[0]=1;

//     while(!q.empty()){
//         int temp = q.size();
//         ans = max(ans, temp);

//         while(temp--){
//             int a = q.front();
//             q.pop();
//             for(int i=0; i<n; i++){
//                 if(tree[a][i]==1 && visited[i]==0){
//                     q.push(i);
//                     visited[i]=1;
//                 }
//             }
//         }
//     }

//     cout << ans;
// }