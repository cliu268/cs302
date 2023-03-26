// A. Heap
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9750&fragments=18041&problemId=7463&pattern=0
/*
（This is a problem concerning heap. If you haven't learned it before, please click here: 堆的学习教程）
Input：
You have to write a data structure to maintain a combination with repetition. The requirements are as follow:
The original set is an empty set. We have to support the following 3 operations: 
Operation 1： x means to insert x into the set
Operation 2： print the smallest number in the set
Operation 3： delete the smallest number in the set

Input：
The first line contains an integer N(1<=N<=1e5)，which is the number of operations.
The next N lines each contains 1 or 2 positive integers, which means 3 types of operations. The format is as follow:
Operation 1： 1 x(1<=x<=2e9)
Operation 2： 2
Operation 3： 3

Output：
Output several lines of positive integers. Each line is in response to the result of operation 2.

Sample input：
5
1 2
1 5
2
3
2

Sample output：
2
5

Time and memory limit：1s，512MB

Source：yn
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> heap={0};
void insert(int x, int ind) {
    if (x<heap[ind/2]) {
        swap(heap[ind], heap[ind/2]);
        // if (ind==1) {
        //     return;
        // }
        insert(x, ind/2);
    }
    else {
        return;
    }
}
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
        if (x==1) {
            int y; cin>>y;
            heap.push_back(y);
            insert(y, heap.size()-1);
        }
        else if (x==2) {
            cout<<heap[1]<<"\n";
        }
        else {
            swap(heap[1], heap[heap.size()-1]);
            heap.pop_back();
            heapify(1);
        }
    }
}