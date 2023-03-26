// A. Kruskal
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9778&fragments=18046&problemId=1060&pattern=0
/*
Use the Kruskal algorithm to find the minimum spanning tree of the graph.

Input :
The first two integers n, m (n<=100000, m<=200000)
The following m lines have three integers a, b, and c for each line, indicating that there is an edge between a and b, and the weight 
of the edge is c.

Output :
Minimum spanning tree edge weight

Sample input:
5 7
1 2 17
1 4 5
1 5 23
2 3 30
2 4 10
3 4 24
3 5 7

Sample output:
45

time limit: 1000
Memory Limit: 65536
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> parent(100001);
vector<ll> height(100001, 0);
ll get(ll x, ll count) {
    if (parent[x]==x) {
        height[x]=max(height[x], count);
        return x;
    }
    return parent[x]=get(parent[x], count+1);
}
void unite(ll x, ll y) {
    if (height[x]==height[y]) {
        parent[x]=y;
        height[y]++;
    }
    else if (height[x]<height[y]) {
        parent[x]=y;
    }
    else {
        parent[y]=x;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll n, m; cin>>n>>m;
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    for (ll i=0; i<m; i++) {
        ll a, b, c; cin>>a>>b>>c;
        pq.push({c, {a, b}});
    }
    for (ll i=0; i<100001; i++) {
        parent[i]=i;
    }
    ll edges=0;
    ll ans=0;
    while (edges<n-1 && !pq.empty()) {
        auto curr=pq.top();
        pq.pop();
        ll x=get(curr.second.first, 0);
        ll y=get(curr.second.second, 0);
        // cout<<x<<" "<<y<<"\n";
        if (x==y) {
            continue;
        }
        edges++;
        ans+=curr.first;
        unite(x, y);
        // cout<<ans<<" ";
    }
    cout<<ans;
}