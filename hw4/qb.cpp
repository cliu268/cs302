// https://www.xinyoudui.com/ac/contest/77700141B0002E1011A278/problem/1029
/*
2.  Heap Sorting
XJOI - Problem ID: 1029Required Problem100pt(s)

Problem Description:
Given n numbers, output them from least to greatest using heap sorting.

Input:
The first line is a positive integer n
The second line has n integers
n < 1000,000

Output:
The sorted series

Sample input:
5
3 4 8 4 7

Sample output:
3 4 4 7 8
*/
// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> tree(n, 0);
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        cin >> tree[i];
        pq.push(tree[i]);
    }

    for(int i=0; i<n; i++){
        tree[i] = pq.top();
        pq.pop();
    }
    for(int i=n-1; i>=0; i--){
        cout << tree[i] << " ";
    }
}