// https://www.xinyoudui.com/ac/contest/77700162A0002E1011A2EE/problem/9875
/*
1.  Single-Source Shortest Path
XJOI - Problem ID: 9875 Required Problem 100pt(s)

Problem description
Given an undirected graph with n(1≤n≤2500) points and m(1≤m≤6200) edges, find the shortest path from s to t.

Input
The first line contains four integers n, m, s, t separated by spaces.
In the next m lines, each line contains three positive integers si, ti, wi(1≤ wi ≤109), representing an edge whose length is wi from si to ti.

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

    int start, end;
    cin >> start >> end;

    vector<int> distances(n+1, INT_MAX);
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<vector<pair<int, int>>> cost(n+1);

    for(int i=0; i<m; i++){
        int s, t, w;
        cin >> s >> t >> w;
        cost[s].push_back(make_pair(t, w));
        cost[t].push_back(make_pair(s, w));
    }

    distances[start] = 0;
    pq.push({start, 0});

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

    cout << distances[end];
}