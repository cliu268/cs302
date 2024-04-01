// https://www.xinyoudui.com/ac/contest/77700148C0002E1011A2DF/problem/7500
/*
2.  All-pairs Shortest Path Problem
XJOI - Problem ID: 7500 Required Problem 100pt(s)

Description
You are given a directed graph with n nodes and edge weights, represented as an adjacency matrix. 
It is guaranteed that the weight of the edge from a node to itself is 0 and that there is an edge between every node.

Please output a n by n matrix representing shortest paths between nodes. i-th row and j-th column would represent the shortest path 
from i to j in the graph. If there exists a negative cycle in the graph, output "No Solution" instead.

Input Format
The first line contains a single integer n, indicating the number of nodes in the graph.
The next n lines contain n integers each. The jth integer on the ith line represents the weight of the edge from node i to node j.

Output Format
Output n lines, each containing n integers. The jth integer on the ith line represents the length of the shortest path from node i to node j. 
If there exists a negative cycle in the graph, output "No Solution".

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
// Ev
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    vector<vector<ll>> distances(n+1, vector<ll>(n+1, 1e18));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> distances[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        distances[i][i] = 0;
    }

    for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    bool negcycle = false;

    for(int i=1; i<=n; i++){
      if(distances[i][i] != 0){
        negcycle = true;
        break;
      }
    }

    if(negcycle){
      cout << "No Solution" << endl;
    }
    else{
      for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
          cout << distances[i][j] << " ";
        }
        cout << endl;
      }
    }
}