// C. Flight Discount
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9786&fragments=18047&problemId=14069&pattern=0
/*
Time limit: 1.00 s
Memory limit: 512 MB
Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the 
price of any single flight during the route. However, you can only use the coupon once.

Input
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,…,n. 
City 1 is Syrjälä, and city n is Metsälä.

After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, 
and its price is c. Each flight is unidirectional.

You can assume that it is always possible to get from Syrjälä to Metsälä.

Output
Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
When you use the discount coupon for a flight whose price is x, its price becomes ⌊x/2⌋ (it is rounded down to an integer).

Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9

Example Input:
3 4
1 2 3
2 3 1
1 3 7
2 1 5

Output:
2
*/
// This answer is NOT correct yet..
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
    float n, m; cin>>n>>m;
    vector<vector<pair<float, float>>> graph(n+1);
    for (float i=0; i<m; i++) {
		float a, b, c; cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }
    vector<float> dist(n+1, 1000000001);
    dist[1]=0;
    priority_queue<pair<float, float>, vector<pair<float, float>>, greater<pair<float, float>>> pq;
    pq.push({0, 1});
    float maxi=0;
    vector<bool> visited(n+1, false);
    while (!pq.empty()) {
		    auto curr=pq.top();
        pq.pop();
        // cout<<curr.second<<" ";
        if (visited[curr.second]) {
          continue;
        }
        visited[curr.second]=true;
        maxi=max(maxi, curr.first);
       	for (auto i : graph[curr.second]) {
          if (dist[i.first]>(dist[curr.second]+i.second/2)) {
            dist[i.first]=dist[curr.second]+i.second/2;
            pq.push({i.second/2, i.first});
          }
        }
    }
    dist[0]=0;
    bool broke=false;
    ll ans=(ll)dist[n]*2;
    // cout<<maxi<<" ";
    ans-=maxi*2;
    ans+=floor(maxi);
    cout<<ans;
}

// Sample correct answer from XC2000311DT(Derek Tang)
// #include <bits/stdc++.h>

// using namespace std;

// vector<long long> mincs(int from, const vector<vector<pair<int, int>>> &neighbors) {
  
//   vector<long long> mincs(neighbors.size(), INT64_MAX);
//   mincs[from] = 0;
//   priority_queue<pair<long long, int>> f;
//   f.push({0, from});
  
//   while (!f.empty()) {
//     pair<long long, int> curr_state = f.top();
//     f.pop();
//     int curr = curr_state.second;
//     if (-curr_state.first != mincs[curr]) {
//       continue;
//     }

//     for (auto [n, nc] : neighbors[curr]) {
//       long long newcs = mincs[curr] + nc;
//       if (newcs < mincs[n]) {
//         mincs[n] = newcs;
//         f.push({-newcs, n});
//       }
//     }
//   }
//   return mincs;
// }

// int main() {
//   int city;
//   int flight;
//   cin >> city >> flight;
//   vector<vector<pair<int, int>>> neighbors(city);
//   vector<vector<pair<int, int>>> rneighbors(city);
  
//   for (int f = 0; f < flight; f++) {
//     int from;
//     int to;
//     int cost;
//     cin >> from >> to >> cost;
//     neighbors[--from].push_back({--to, cost});
//     rneighbors[to].push_back({from, cost});
//   }

//   vector<long long> startcs = mincs(0, neighbors);
//   vector<long long> endcs = mincs(city - 1, rneighbors);
  
//   long long total_min = INT64_MAX;
  
//   for (int c = 0; c < city; c++) {
//     for (auto [n, nc] : neighbors[c]) {
//       if (startcs[c] == INT64_MAX || endcs[n] == INT64_MAX) {
//         continue;
//       }
//       total_min = min(total_min, startcs[c] + (nc / 2) + endcs[n]);
//     }
//   }
  
//   cout << total_min << endl;
// }