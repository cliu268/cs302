// B. heap sorting
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9750&fragments=18041&problemId=1029&pattern=0
/*
Heap sorting: Enter n numbers, output from small to large.

Input:
The first line is a positive integer n
The second line of n integers
n < 1000,000

Output:
Sorted series

Sample input:
5
3 4 8 4 7

Sample output:
3 4 4 7 8

time limit: 1000
Memory limit: 65536
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> heap={0};
void heapify(int ind) {
    int maxi=ind;
    int left=ind*2; int right=ind*2+1;
    if (left<heap.size() && heap[left]<heap[maxi]) {
        maxi=left;
    }
    if (right<heap.size() && heap[right]<heap[maxi]) {
        maxi=right;
    }
    if (maxi!=ind) {
        swap(heap[ind], heap[maxi]);
        heapify(maxi);
    }
}
int main() {
    int n; cin>>n;
    for (int i=0; i<n; i++) {
        int x; cin>>x;
        heap.push_back(x);
    }
    for (int i=(heap.size()-1)/2; i>=1; i--) {
        heapify(i);
    }
    while (heap.size()>1) {
        cout<<heap[1]<<" ";
        swap(heap[1], heap[heap.size()-1]);
        heap.pop_back();
        if (heap.size()==1) {
            break;
        }
        heapify(1);
    }
}