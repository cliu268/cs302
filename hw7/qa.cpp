// https://www.xinyoudui.com/ac/contest/77700148C0002E1011A2DF/problem/14122
/*
1.  Shortest Routes II
XJOI - Problem ID: 14122 Required Problem 100pt(s)

Description
There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route 
between two given cities.

Input
The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. 
All roads are two-way roads.
Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route 
between cities a and b.

Output
Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1 ≤ n ≤ 500
1 ≤ m ≤ n^2
1 ≤ q ≤ 10^5
1 ≤ a,b ≤ n 
1 ≤ c ≤ 10^9

Example Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3
*/
// Ev
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> distances(n+1, vector<ll>(n+1, 1e18));

    for(int i=0; i<m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        distances[a][b] = distances[b][a] = min(distances[a][b], c);
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

    for(int i=0; i<q; i++){
        int s, t; 
        cin >> s >> t;
        if(distances[s][t] == 1e18){
            cout << -1 << endl;
        }
        else{
            cout << distances[s][t] << endl;
        }
    }
}