// A. Shortest Routes II
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9768&fragments=18044&problemId=14122&pattern=0
/*
Time limit: 1.00 s Memory limit: 512 MB
There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest 
route between two given cities.

Input
The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose 
length is c. All roads are two-way roads.
Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between 
cities a and b.

Output
Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1≤n≤500
1≤m≤n^2
1≤q≤10^5
1≤a,b≤n
1≤c≤10^9

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
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LONG_LONG_MAX));
  for (ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[a][b], c);
  }
  for (ll i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (dist[i][j] == LONG_LONG_MAX) {
        continue;
      }
      for (ll k = 1; k <= n; k++) {
        if (dist[i][k] == LONG_LONG_MAX) {
          continue;
        }
        dist[j][k] = min(dist[j][k], dist[i][j] + dist[i][k]);
      }
    }
  }
  for (ll i = 0; i < q; i++) {
    ll a, b;
    cin >> a >> b;
    if (dist[a][b] == LONG_LONG_MAX) {
      cout << -1 << "\n";
      continue;
    }
    cout << dist[a][b] << "\n";
  }
}