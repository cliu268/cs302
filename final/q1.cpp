// A. Binary Tree
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9786&fragments=18047&problemId=8808&pattern=0
/*
Time limit：1s   Memory limit：256M

Description：
Given each node's father, please determine whether the tree is a binary tree. The one with smaller index is the left child. 

Input：
The first line contains a positive integer n --- number of vertices in the tree
Next, n positive integers --- father vertices

Output：
Output yes or no

Sample input 1：
3
-1 1 1

Sample output 1：
yes

Note：1 <= n <= 20
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> child(21);
bool ans=false;
void dfs(int x) {
    if (child[x].size()<=2) {
        for (auto i : child[x]) {
			dfs(i);
        }
    }
    else {
		ans=true;
    }
}
int main() {
	int n; cin>>n;
    for (int i=0; i<n; i++) {
		int a; cin>>a;
        if (a==-1) {
			continue;
        }
        child[a].push_back(i+1);
    }
    dfs(1);
    if (ans) {
        cout<<"no";
    }
    else {
		cout<<"yes";
    }
}