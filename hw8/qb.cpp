// https://www.xinyoudui.com/ac/contest/77700164C0002E1011A282/problem/14125
/*
2.  Road Reparation
XJOI - Problem ID: 14125 Required Problem 100pt(s)

Description
Time limit: 1.00 s
Memory limit: 128 MB
There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. 
Your task is to repair some of the roads so that there will be a decent route between any two cities.

For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, 
and its reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.

Output
Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".

Constraints
1 ≤ n ≤ 10^5
1 ≤ m ≤ 2⋅10^5
1 ≤ a,b ≤ n 
1 ≤ c ≤ 10^9

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
// Ev
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> roads(n);

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        roads[a].push_back(make_pair(b, c));
        roads[b].push_back(make_pair(a, c));
    }

    ll ans=0;

    vector<bool> visited(n, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0,0)); //dist, node

    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;

        pq.pop();

        if(visited[curr_node]){
            continue;
        }

        visited[curr_node]=true;
        ans+=curr_dist;
        
        for(auto i : roads[curr_node]){
            pq.push(make_pair(i.second,i.first));
        }
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << ans;
}