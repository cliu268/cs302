// https://www.xinyoudui.com/ac/contest/7770016200002E1011A224/problem/1071
/*
2.  Negative Cycle Detection
XJOI - Problem ID: 1071 Required Problem 100pt(s)

Description:
Given T weighted directed graphs that may have duplicated edges or self-loop edges. Please determine whether there is a negative loop. 
Print YES if there's negative circle; otherwise print NO.

Input
A number T indicates the number of test cases.
For each case, the first line N,M represent the number of vertices and number of edges in this graph.
After that there are M lines, and for the i-th line, three numbers per line, xi,yi,zi represent an edge from xi to yi with cost zi.

​Output
For each case, output one line, YES for negative circle detected, or NO otherwise.

Sample input
2
1 1
1 1 -1
4 4
1 2 1
2 1 1
3 4 -2
4 3 1

Sample output
YES
YES

Data range
T<=20
N<=100
M<=500
*/
// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        vector<vector<int>> tree(n+1);
        vector<int> distances(n+1, 0);
        vector<vector<int>> cost(n+1, vector<int>(n+1, 0));

        for(int i=0; i<m; i++){
            int a, b, c;
            cin >> a >> b >> c; //from a to b cost is c
            tree[a].push_back(b);
            cost[a][b] = c;
        }

        string answer="NO";

        for(int k=0; k<n-1; k++){ 
            for(int i=1; i<=n; i++){
                for(int j=0; j<tree[i].size(); j++){
                    distances[tree[i][j]] = min(distances[tree[i][j]], distances[i] + cost[i][tree[i][j]]);
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<tree[i].size(); j++){
                if(distances[i] + cost[i][tree[i][j]] < distances[tree[i][j]]){
                    answer="YES";
                }
            }
        }

        // for(int i=1; i<n+1; i++){
        //     if(distances[i]==INT_MAX){
        //         cout << "max ";
        //     }
        //     else{
        //         cout << distances[i] << " ";
        //     }
        // }

        cout << answer << endl;
    }
}