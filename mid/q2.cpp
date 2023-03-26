// B. Distance between two points on the tree
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9758&fragments=18065&problemId=3329&pattern=0
/*
Time Limit: 0.2s Memory Limit: 32M

Description:
Give you a rootless tree and find the distance between two points on the tree.

Input format:
The first line enters an integer n to indicate the total number of points in the tree.
Next,  n−1 lines enter two integers per line to represent a tree edge.
Enter two points a,b on the last line

Output :
Output an integer representing the distance between aandb

Sample input:
4
1 2
2 3
3 4
1 4

Sample output:
3

Appointment: 1<=n<=1000
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
vector<vector<int>> adj(1001);
int ans=10000;
void dfs(int x, int count, vector<bool> &visited, int goal) {
    visited[x]=true;
    for (auto i : adj[x]) {
        if (visited[i]) {
            continue;
        }
        if (i==goal) {
            ans=min(ans, count+1);
            return;
        }
        dfs(i, count+1, visited, goal);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
    
    for (int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int a, b; cin>>a>>b;
    vector<bool> visited(1001, false);
    dfs(a, 0, visited, b);
    cout<<ans<<"\n";
}