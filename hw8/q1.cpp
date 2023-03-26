// A. Road Reparation
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9773&fragments=18083&problemId=14125&pattern=0
/*
Time limit: 1.00 s Memory limit: 128 MB
There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to 
repair some of the roads so that there will be a decent route between any two cities.

For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, and its 
reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.

Output
Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9

Example Input:
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Output:
14
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll n, m; cin>>n>>m;
    vector<vector<pair<ll, ll>>> road(n+1);
    for (ll i=0; i<m; i++) {
		ll a, b, c; cin>>a>>b>>c;
        road[a].push_back({b, c});
        road[b].push_back({a, c});
    }
    vector<bool> visited(n+1, false);
    vector<ll> dist(n+1, 1000000001);
    dist[1]=0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        // cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        ll curr=pq.top().second;
        pq.pop();
        if (visited[curr]) {
            continue;
        }
        visited[curr]=true;
        for (auto i : road[curr]) {
            if (i.second<dist[i.first] && !visited[i.first]) {
                dist[i.first]=i.second;
                pq.push({i.second, i.first});
            }
        }
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) {
        if (!visited[i]) {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for (ll i=1; i<=n; i++) {
        ans+=dist[i];
        // cout<<dist[i]<<" ";
    }
    cout<<ans;
}