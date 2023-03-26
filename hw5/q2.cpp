// B. Negative Circle Detection
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9755&fragments=18042&problemId=1071&pattern=0
/*
Given case weighted directed graphs with a heavy self-loop edge  to determine if they have a negative loop. Please print YES if there's 
negative circle; otherwise please print NO.

Input
A number Case indicates the number of test cases.
For each case, the first line n, m represent the number of vertices and number of edges in this graph.
After that it's m lines, and for the i-th line, three numbers per line, xi, yi, zi represent an edge from xi to yi with cost zi.

Output
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
Case<=20
N<=100
M<=500

Time Limit 1000
Memory Limit 65536
*/
// ********* ONLY GOT 90 points. not perfect score.. **********
#include <iostream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ll t; cin>>t;
    while (t--) {
		ll n, m; cin>>n>>m;
        vector<vector<ll>> adj(10000);
        map<pair<ll, ll>, ll> weight;
        for (ll i=0; i<m; i++) {
			ll a, b, c; cin>>a>>b>>c;
            adj[a].push_back(b);
            weight[{a, b}]=c;
        }
        for (ll i=1; i<=n; i++) {
            adj[0].push_back(i);
            adj[i].push_back(0);
            weight[{0, i}]=0;
        }
        vector<ll> dist(10000, 10000);
        dist[0]=0;
        for (ll k=0; k<n-1; k++) {
            for (ll i=0; i<=n; i++) {
                if (dist[i]==10000) {
                    continue;
                }
                for (ll j : adj[i]) {
                    dist[j]=min(dist[j], dist[i]+weight[{i, j}]);
                }
            }
        }
        bool change=false;
        for (ll i=0; i<=n; i++) {
            if (dist[i]==10000) {
                    continue;
            }
            for (ll j : adj[i]) {
                if (dist[j]>(dist[i]+weight[{i, j}])) {
                    change=true;
					break;
                }
            }
            if (change) {
                break;
            }
        }
        if (change) {
            cout<<"YES\n";
        }
        else {
			cout<<"NO\n";
        }
    }
}