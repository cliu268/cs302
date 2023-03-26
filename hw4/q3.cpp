// C. Median
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9750&fragments=18041&problemId=7450&pattern=0
/*
Description：
Given a non-negative integer array Ai whose length is N, for all 1≤k≤(N+1)/2，print the median of A1,A3,…,A2k−1​. That is the median of 
the first 1,3,5,… numbers. 

Input：
The first line contains the number N(1<=N<=1e6).
The second line contains N integers. The i-th number is Ai (1<=Ai<=1e9).

Output：
Output several lines. For each odd number's i, print a line which contains the median of A1，A2，A3...Ai.

Sample input：
7
1 3 5 7 9 11 6

Sample output：
1
3
5
6

Time and memory limit：1s，512MB
Source：yn
*/
// Solution from XC210448DL (David Li)
#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater <int>> min_heap;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (max_heap.empty() || x <= max_heap.top()) max_heap.push(x);
        else min_heap.push(x);
        if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (min_heap.size() + 1 < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (i % 2) printf("%d\n", max_heap.top());
    }
}