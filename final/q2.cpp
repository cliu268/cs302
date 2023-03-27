// B. Binary tree traverse
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9786&fragments=18047&problemId=1041&pattern=0
/*
Time Limit：1s   Memory Limit：256M
 
Description
Given a binary tree, please output the preorder traversal, inorder traversal, postorder traversal. N<=100

Input
A binary tree:
the first line is an integer representing the number of nodes.
From the second line,each line contains three numbers,the first is the node number,second is the left child of this node,third is the 
right child of this node.

Output
The first line is the preorder traversal,
the second line is the inorder traversal,
the third line is the postorder traversal.
Each number is separated with a space.

Sample Input
5
1 2 3
2 4 5
3 0 0
4 0 0
5 0 0

Sample Output
1 2 4 5 3
4 2 5 1 3
4 5 2 3 1
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vect(101);
void pre(int x) {
	cout<<x<<" ";
    if (vect[x].first) {
        pre(vect[x].first);
    }
    if (vect[x].second) {
		pre(vect[x].second);
    }
}
void in(int x) {
    if (vect[x].first) {
        in(vect[x].first);
    }
    cout<<x<<" ";
    if (vect[x].second) {
		in(vect[x].second);
    }
}
void post(int x) {
    if (vect[x].first) {
        post(vect[x].first);
    }
    if (vect[x].second) {
		post(vect[x].second);
    }
    cout<<x<<" ";
}
int main() {
	int n; cin>>n;
    for (int i=0; i<n; i++) {
		int a, b, c; cin>>a>>b>>c;
        vect[a]={b, c};
    }
    pre(1);
    cout<<"\n";
    in(1);
    cout<<"\n";
    post(1);
}