// A. Dijkstra's Algorithm
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9763&fragments=18043&problemId=9771&pattern=0
/*
Time Limit: 0.5s    Memory Limit: 64M

Problem description
Given a directed graph, please return the shortest path length from point 1 to all points.

Input
The first line contains two integers n,m, which respectively represent the number of points (numbered from 1 to n) and the number of 
directed edges.

Output
Output a line, a total of n integers separated by spaces, the ith number represents the shortest path from the starting point to the point i, 
if the point cannot be reached, output "inf".

Sample input
5 6
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

Sample output
0 2 4 3 inf

Data range
1≤n≤20, 1≤m≤50, 1≤w≤1000 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i=0; i<m; i++) {
		int a, b, c; cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }
    vector<int> dist(n+1, 100000);
    priority_queue<int> pq;
    pq.push(1);
    dist[1]=0;
    while (!pq.empty()) {
		int curr=pq.top();
        pq.pop();
        for (auto i : graph[curr]) {
            if (dist[i.first]>(dist[curr]+i.second)) {
                dist[i.first]=(dist[curr]+i.second);
                pq.push(i.first);
            }
        }
    }
    for (int i=1; i<=n; i++) {
		if (dist[i]==100000) {
            cout<<"inf ";
        }
        else {
			cout<<dist[i]<<" ";
        }
    }
}