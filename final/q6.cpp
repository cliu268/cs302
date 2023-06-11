// E. Moo Network
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9786&fragments=18047&problemId=15507
/*
Farmer John's N cows (1≤N≤10^5) are spread far apart on his farm and would like to build a communication network so they can more easily 
exchange electronic text messages (all of which of course contain variations of "moo").

The ith cow is located at a distinct location (xi,yi) where 0≤xi≤10^6 and 0≤yi≤10. The cost of building a communication link between 
cows i and j is the squared distance between them: (xi−xj)^2+(yi−yj)^2.

Please calculate the minimum cost required to build a communication network across which all the cows can communicate. Two cows can 
communicate if they are directly connected by a link, or if there is a sequence of links along which their message can travel.

**Note: the time limit for this problem is 4s, twice the default.**

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains N, and the next N lines each describe the x and y coordinates of a cow, all integers.

OUTPUT FORMAT (print output to the terminal / stdout):
Please output the minimum cost of a network that will allow all cows to communicate. Note that this cost might be too large to fit into a 
32-bit integer and may require use of 64-bit integers (e.g., "long long" integers in C++).

SAMPLE INPUT:
10
83 10
77 2
93 4
86 6
49 1
62 7
90 3
63 4
40 10
72 0

SAMPLE OUTPUT:
660

SCORING:
Test cases 2-3 satisfy N≤1000.
Test cases 4-15 satisfy no additional constraints.
Problem credits: Brian Dean
*/
// Sample answer from Alexis Chen
// source: 
// http://usaco.org/index.php?page=viewproblem2&cpid=1211 
// sol: https://usaco.guide/problems/usaco-1211-moo-network/solution 
#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long 
#define plii pair<ll, pair<int,int>>
using namespace std; 
int MAX = 1e5+1; 

vector<pii> points;
vector<plii> edges;
vector<int> parent(MAX, -1);
vector<int> size(MAX, 1);
int n, x, y; 

// details: int x * int y => still int 
// calculate in int and then convert to ll
ll dist(int u, int v) {
  ll x_diff = points[u].first - points[v].first; 
  ll y_diff = points[u].second - points[v].second; 
  return x_diff * x_diff + y_diff * y_diff; 
}

int find(int u) {
  if(parent[u] == -1) return u;
  return parent[u] = find(parent[u]); 
}

void unite(int u, int v) {
  u = find(u);
  v = find(v);

  if(u != v) {
    if(size[u] < size[v]) swap(u, v); 
    parent[v] = u;
    size[u] += size[v]; 
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x >> y; 
    points.push_back({x,y}); 
  }
  sort(points.begin(), points.end()); 
  vector<int> last(11, -1); // vector of id from y = 0 to 10 

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= 10; j++) {
      if(last[j] != -1) {
        int u = i;
        int v = last[j]; 
        edges.push_back({dist(u,v), {u, v}}); 
      }
    }
    last[points[i].second] = i; 
  }

  sort(edges.begin(), edges.end()); 

  ll total = 0, count = 0; 
  for(auto edge: edges) {
    int u = edge.second.first, v = edge.second.second;
    ll weight = edge.first; 
    if(find(u) != find(v)) {
      unite(u, v); 
      total += weight; 
      count++; 
    }
    if(count == n-1) {
      break; 
    }
  }
  
  cout << total << endl; 
}