// https://www.xinyoudui.com/ac/contest/77700162A0002E1011A2EE/problem/9771
/*
3.  Dijkstra's algorithm
XJOI - Problem ID: 9771 Required Problem 100pt(s)
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
https://usaco.guide/CPH.pdf#page=136 - read Dijkstra
https://visualgo.net/en/sssp?slide=1 - select Dijkstra and click original

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
// Ev
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    int dist;
};

bool operator > (node a, node b){
    return a.dist > b.dist;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> distances(n+1, INT_MAX);
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<vector<pair<int, int>>> cost(n+1);

    for(int i=0; i<m; i++){
        int s, t, w;
        cin >> s >> t >> w;
        cost[s].push_back(make_pair(t, w));
    }

    distances[1] = 0;
    pq.push({1, 0});

    while(!pq.empty()){
        int curr_node = pq.top().val;
        int curr_dist = pq.top().dist;
        pq.pop();
        if(distances[curr_node] != curr_dist){
            continue;
        }
        for(int i=0; i<cost[curr_node].size(); i++){
            int next_node = cost[curr_node][i].first;
            int next_dist = cost[curr_node][i].second;
            int new_dist = curr_dist + next_dist;
            if(new_dist < distances[next_node]){
                distances[next_node] = new_dist;
                pq.push({next_node, new_dist});
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(distances[i]==INT_MAX){
            cout << "inf ";
        }
        else{
            cout << distances[i] << " ";
        }
    }
}