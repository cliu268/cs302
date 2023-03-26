// B. All-pairs Shortest Path Problem
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9768&fragments=18044&problemId=7500&pattern=0
/*
Time limit: 2s
Space limit: 128M

Problem Description
You are given a directed graph with n nodes and edge weights, represented as an adjacency matrix. It is guaranteed that the weight of the 
edge from a node to itself is 0.

Please output a n by n matrix representing shortest paths between nodes. i-th row and j-th column would represent the shortest path from 
i to j in the graph. If there exists a negative cycle in the graph, output "No Solution" instead.

Input Format
The first line contains a single integer n, indicating the number of nodes in the graph.
The next n lines contain n integers each. The jth integer on the ith line represents the weight of the edge from node i to node j.

Output Format
Output n lines, each containing n integers. The jth integer on the ith line represents the length of the shortest path from node i to node j. 
If there is no path from i to j, output "inf". If there exists a negative cycle in the graph, output "No Solution".

Input Example 1:
3
0 1 2
-1 0 0
2 1 0

Output Example 1:
0 1 1
-1 0 0
0 1 0

Input Example 2:
2
0 1
-2 0

Output Example 2:
No Solution

Constraints
For 10% of the test cases, n ≤ 5 and all edge weights are non-negative.
For 100% of the test cases, n ≤ 500 and the edge weights are integers between -65536 and 65536.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<vector<int>> dist(n, vector<int>(n, 1000000));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>dist[i][j];
        }
    }
    for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (dist[i][j]==1000000) {
                continue;
            }
            for (int k=0; k<n; k++) {
				if (dist[k][i]==1000000) {
					continue;
                }
                dist[k][j]=min(dist[k][i]+dist[i][j], dist[k][j]);
            }
        }
    }
    bool broke=false;
    for (int i=0; i<n; i++) {
        if (dist[i][i]!=0) {
            cout<<"No Solution";
            broke=true;
            break;
        }
    }
    if (!broke) {
        for (auto i : dist) {
            for (auto j : i) {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
}