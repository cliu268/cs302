// B. Single-Source Shortest Path
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9763&fragments=18043&problemId=9875&pattern=0
/*
Time Limit: 1s    Memory Limit: 64M

Problem description
Given an undirected graph with n(1≤n≤2500) points and m(1≤m≤6200) edges, find the shortest path from s to t.

Input
The first line contains four integers n, m, s, t separated by spaces.
In the next m lines, each line contains three positive integers si, ti, wi(1≤wi≤109), representing a side whose length is wi from si to ti.

Output
An integer representing the length of the shortest path from s to t. The data guarantees that at least one path exists.

Sample input
5 6 1 3
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

Sample output
4
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, t; cin>>n>>m>>s>>t;
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i=0; i<m; i++) {
		int a, b, c; cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<int> dist(n+1, 100000);
    priority_queue<int> pq;
    pq.push(s);
    dist[s]=0;
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
    cout<<dist[t];
}