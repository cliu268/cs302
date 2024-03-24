// C. Diameter of a Tree
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9735&fragments=18204&problemId=9502&pattern=0
// https://www.xinyoudui.com/ac/contest/7740019EF0002E10119FCE/problem/9502
/*
Description：
Given a tree rooted with node 1, output the tree's diameter
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.

Input Format：
First line contains an integer N, which is the number of nodes.
The following n-1 lines, every line contains two integer x and y, which means there is an edge connecting x and y.
It's guaranteed that the input is a tree.

Output Format：
One integer, the diameter

Sample Input 1：
6
2 1
2 3
2 4
2 5
6 5

Sample Output 1：
3

Limitation：1<=n<=100000
*/
// Etaw
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> child(100001);
int node1=0;
int count1=0;
void dfs(int x, int prev, int count) {
  for (int i : child[x]) {
    if (i==prev) {
      continue;
    }
    dfs(i, x, count+1);
  }
  if (count>count1) {
    count1=count;
    node1=x;
  }
}
int main() {
  int n; cin>>n;
  for (int i=0; i<n-1; i++) {
    int x, y; cin>>x>>y;
    child[x].push_back(y);
    child[y].push_back(x);
  }
  int count=0;
  dfs(1, -1, count);
  count=0;
  dfs(node1, -1, count);
  cout<<count1<<"\n";
}

// Ev
// #include<bits/stdc++.h>
// using namespace std;

// const int N_MAX = 1e5 + 1; 
// vector<vector<int>> tree(N_MAX);
// vector<int> visited(N_MAX, 0);

// int ans=0; int furthest = 0;

// void dfs(int distance, int node){
//     if(distance > ans){
//         ans = distance;
//         // cout << ans << " ";
//         furthest = node;
//         // cout << furthest << endl;
//     }
//     for(int i=0; i<tree[node].size(); i++){
//         if(visited[tree[node][i]] == 0){
//             visited[tree[node][i]] = 1;
//             dfs(distance + 1, tree[node][i]);
//         }
//     }
// }

// int main(){
//     int n; cin >> n;
//     for(int i=0; i<n-1; i++){
//         int a, b; 
//         cin >> a >> b;
//         tree[a].push_back(b);
//         tree[b].push_back(a);
//     }

//     // cout << "mark " << endl;

//     dfs(0, 1);
//     int z = furthest;
//     ans = 0; furthest = 0;
//     for(int i=0; i<n+1; i++){
//         visited[i]=0;
//     }
//     dfs(0, z);

//     cout << ans;
// }