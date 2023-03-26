// C. Weights of Subtrees
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9740&fragments=18207&problemId=9501&pattern=0
/*
Description:
With a tree whose root is 1, output the weight of each node. Weight of a node is defined as the total number of nodes of the subtree 
that take the node as the root.

Input format：
First number in the first line represents number of nodes.
Following N-1 lines have 2 integers respectively, x, y, represents that x and y are connected.
It's guaranteed that the input is a valid tree.

Input：
First line has one integer n. This is the number of the nodes of the tree.
Then there are n-1 more lines. Each of these lines has 2 integers x and y denoting the edge connecting node x and y. 
This ensures the input data can form a tree.

Output:
Output n lines. Each line has one integer. the i-th line represents the weight of the i-th node.

Sample Input：
6
2 1
2 3
2 4
2 5
6 5

Sample Output：
6
5
1
1
2
1

Notes： 1<=n<=100000
*/
// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> adj(100000);
// vector<int> parent(100000);
// vector<pair<int, int>> to_leaf(100000, {-1, -1});
// vector<int> to_parent(100000);
// int n;
// void dfs(int x, vector<bool> &visited, int curr) {
//   bool found=false;
//   for (int i : adj[x]) {
//     if (visited[i]) {
//       continue;
//     }
//     found=true;
//     visited[i]=true;
//     parent[i]=x;
//     dfs(i, visited, curr+1);
//     if (to_leaf[i].first+1 > to_leaf[x].first) {
//       to_leaf[x].first=to_leaf[i].first+1;
//     }
//     else if (to_leaf[i].first+1 > to_leaf[x].second) {
//       to_leaf[x].second=to_leaf[i].first+1;
//     }
//     else if (to_leaf[i].second+1 > to_leaf[x].first) {
//       to_leaf[x].first=to_leaf[i].second+1;
//     }
//     else if (to_leaf[i].second+1 > to_leaf[x].second) {
//       to_leaf[x].second=to_leaf[i].second+1;
//     }
//     parent[i]=x;
//   }
//   if (!found) {
//     to_leaf[x]={0, 0};
//   }
// }
// void fill(int x, vector<bool> &visited) {
//   for (int i : adj[x]) {
//     if (visited[i]) {
//       continue;
//     }
//     visited[i]=true;
//     fill(i, visited);
//     to_parent[x]=max(to_parent[parent[x]], to_leaf[parent[x]].second);
//   }
// }
// int main() {
//   cin>>n;
//   for (int i=0; i<n-1; i++) {
//     int a, b; cin>>a>>b;
//     adj[a].push_back(b);
//   }
//   vector<bool> visited(n, false); visited[0]=true;
//   parent[0]=0;
//   dfs(0, visited, 0);

// }
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> child(100001);
vector<int> parent(100001);
vector<int> ans(100001, 1);
void dfs(int x, int prev, int count) {
    bool found=false;
    for (int i : child[x]) {
		if (i==prev) {
            continue;
        }
        found=true;
        parent[i]=x;
        dfs(i, x, count+1);
        ans[x]+=ans[i];
    }
}
int main() {
    int n; cin>>n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    parent[1]=1;
    dfs(1, -1, 0);
    for (int i=1; i<=n; i++) {
        cout<<ans[i]<<"\n";
    }
}