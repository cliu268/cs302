// https://www.xinyoudui.com/ac/contest/7770016200002E1011A224/problem/3331
/*
1.  shortest path
XJOI - Problem ID: 3331Required Problem100pt(s)

Description:
Given an undirected graph that may not be connected where each edge length is 1, find the shortest path between two points on the graph.

Input:
The first line:  two integers n,m, representing the number of points and edges, respectively.
The m lines: two integers a,b per line, representing an edge between a and b.
The last line: two integers s,t indicating the start and end points in the last line.

Output:
Output the shortest path between s,t, if s,t is unreachable, output -1

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
// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> tree(n+1);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int start, end; 
    cin >> start >> end;

    vector<int> distances(n+1, INT_MAX);
    distances[start]=0;

    for(int k=0; k<n-1; k++){ //repeat n-1 times
        for(int i=1; i<n+1; i++){ //for all nodes 
            for(int j=0; j<tree[i].size(); j++){ //for all their edges
                if(distances[i]==INT_MAX){
                    continue;
                }
                else{
                    distances[tree[i][j]] = min(distances[tree[i][j]], distances[i] + 1);
                }
            }
        }
    }

    // for(int i=1; i<n+1; i++){
    //     if(distances[i]==INT_MAX){
    //         cout << "-1 ";
    //     }
    //     else{
    //         cout << distances[i] << " ";
    //     }
    // }


    if(distances[end]==INT_MAX){
        cout << -1;
    }
    else{
        cout << distances[end];
    }
}