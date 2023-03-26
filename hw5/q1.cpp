// A. Shortest Path
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9755&fragments=18042&problemId=3331&pattern=0
/*
Time Limit: 1s Memory Limit: 32M

Description :
Give you an undirected graph, may not be connected, find the shortest path between two points on the graph, the length of each edge is 1

Input :
The first line entered with two integers n,m, representing the number of points and edges, respectively.
Next, the m lines enter two integers a,b per line, representing an edge.
Enter two integers s,t to indicate the start and end points in the last line.

Output :
Output shortest path between s,t, if s,t is unreachable, output -1

Sample input:
4 4
1 2
1 3
2 4
3 4
1 4

Sample output:
2

Appointment:
1<=n<=5000,1<=m<=8000
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(10000);
    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s, t; cin>>s>>t;
    vector<int> dist(10000, 10000);
    dist[s]=0;
    for (int k=0; k<n-1; k++) {
        for (int j=1; j<=n; j++) {
            if (dist[j]==10000) {
                continue;
            }
            for (int i : adj[j]) {
                dist[i]=min(dist[i], dist[j]+1);
            }
        }
    }
    if (dist[t]==10000) {
        dist[t]=-1;
    }
    cout<<dist[t];
}