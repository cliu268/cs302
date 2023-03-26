// B. Telephone Connection (dial)
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9778&fragments=18046&problemId=1541&pattern=0
/*
There are n cities in a country. There are telephone lines connecting several cities. Now we need to add m telephone lines so that any 
two cities can connect directly or indirectly with each other through telephone lines in other cities. Your program should be able to 
find the minimum cost and relevant. Connection plan.

Input :
The first line of the input file is the value of n (n<=100).
The second row to the n+1th row is an n*n matrix, and if the number of the i-th row and the j-th column is 0, it indicates that the 
city i has a telephone line connecting with the city j, otherwise the the number refers to the connection fee between the two cities is 
(The range does not exceed 10,000).

Output :
The first line of the output file is the total number m of phone lines you connect to,
The second line is the total cost of connecting these lines.

Sample input:
5
0 15 27 6 0
15 0 33 19 11
27 33 0 0 17
6 19 0 0 9
0 11 17 9 0

Sample output:
2
17

data range: n<=100
time limit: 1000
memory limit: 65536
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
	ll n; cin>>n;
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<n; j++) {
            ll a; cin>>a;
            pq.push({a, {i, j}});
        }
    }
    for (ll i=0; i<100001; i++) {
        parent[i]=i;
    }
    ll edges=0;
    ll ans=0;
    ll used=0;
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
        if (curr.first>0) {
            used++;
        }
        unite(x, y);
        // cout<<ans<<" ";
    }
    cout<<used<<"\n";
    cout<<ans;
}