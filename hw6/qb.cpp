// https://www.xinyoudui.com/ac/contest/77700162A0002E1011A2EE/problem/14121
/*
2.  Shortest Routes I
XJOI - Problem ID: 14121Required Problem100pt(s)

Description
Time limit: 1.00 s
Memory limit: 512 MB
There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.

Input
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,…,n, 
and city 1 is Syrjälä.
After that, there are m lines describing the flight connections. Each line has three integers a, b and c: a flight begins at city a, 
ends at city b, and its length is c. Each flight is a one-way flight.
You can assume that it is possible to travel from Syrjälä to all other cities.

Output
Print n integers: the shortest route lengths from Syrjälä to cities 1,2,…,n.

Constraints
1 ≤ n ≤ 10^5
1 ≤ m ≤ 2⋅10^5
1 ≤ a,b ≤ n 
1 ≤ c ≤ 10^9

Example Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2
*/
// Ev 70%
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll val;
    ll dist;
};

bool operator > (node a, node b){
    return a.dist > b.dist;
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> distances(n+1, INT_MAX);
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<vector<pair<ll, ll>>> cost(n+1);

    for(ll i=0; i<m; i++){
        ll s, t, w;
        cin >> s >> t >> w;
        cost[s].push_back(make_pair(t, w));
    }

    distances[1] = 0;
    pq.push({1, 0});

    while(!pq.empty()){
        ll curr_node = pq.top().val;
        ll curr_dist = pq.top().dist;
        pq.pop();
        if(distances[curr_node] != curr_dist){
            continue;
        }
        for(ll i=0; i<cost[curr_node].size(); i++){
            ll next_node = cost[curr_node][i].first;
            ll next_dist = cost[curr_node][i].second;
            ll new_dist = curr_dist + next_dist;
            if(new_dist < distances[next_node]){
                distances[next_node] = new_dist;
                pq.push({next_node, new_dist});
            }
        }
    }

    for(ll i=1; i<=n; i++){
        cout << distances[i] << " ";
    }
}