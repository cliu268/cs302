// A. Subtree Nodes
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9758&fragments=18065&problemId=3333&pattern=0
/*
Time Limit: 0.2s Memory Limit: 32M

Description
Give you a tree rooted with node 1, please compute the total number of nodes in the subtree of that is rooted at every single node. 
All nodes of the tree are noted with a number from 1 to n.

Input
The first line enters an integer n to indicate the total number of nodes in the tree.
In the second line, enters n−1 numbers, and the ith number indicates the parent node number of i+1.

Output
The output line contains n integers, and the i-th number represents the number of points in the subtree of point i, including itself.

Sample Input
10
8 4 8 10 1 1 1 3 8

Sample Output
10 1 2 3 1 1 1 7 1 2

Appointment
$1 <= n <= 1000$
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> child(1001);
vector<int> ans(1001, 0);
void dfs(int x, int count) {
    ans[x]=1;
	for (auto i : child[x]) {
		if (ans[i]==0) {
			dfs(i, count+1);
        }
        ans[x]+=ans[i];
    }
}
int main() {
	cin>>n;
    for (int i=0; i<n-1; i++) {
		int x; cin>>x;
        child[x].push_back(i+2);
    }
    dfs(1, 0);
    for (int i=1; i<=n; i++) {
		cout<<ans[i]<<" ";
    }
}