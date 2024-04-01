// https://www.xinyoudui.com/ac/contest/77700141B0002E1011A278/problem/7463
/*
1.  Heap
XJOI - Problem ID: 7463Required Problem100pt(s)

Description
（This is a problem concerning heap. If you haven't learned it before, please click here: https://baike.baidu.com/item/%E5%A0%86/20606834）

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
// Ev 20%
#include<bits/stdc++.h>
using namespace std;
int n;

vector<int> tree(0);

void downheap(int x){
    int s = tree.size();
    int left = 2*x + 1;
    int right = 2*x + 2;
    if(left >= s && right >= s){
        return;
    }
    if(tree[left] > tree[x] && tree[right] > tree[x]){
        return;
    }
    if(left < s && right < s){
        if(tree[left] < tree[right] && tree[left] < tree[x]){
            swap(tree[left], tree[x]);
            downheap(left);
        }
        else if(tree[right] < tree[left] && tree[right] < tree[x]){
            swap(tree[right], tree[x]);
            downheap(right);
        }
    }
    else if(right >= s && left < s){
        if(tree[left] < tree[x]){
            swap(tree[left], tree[x]);
            downheap(left);
        }
    }
}

int least(){
    return tree[0];
}

void remove(int x){
    swap(tree[x], tree[0]);
    vector<int>::iterator it = tree.end() - 1;
    tree.erase(it);
    downheap(0);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a==1){
            int b; cin >> b;
            tree.insert(tree.begin(), b);
            downheap(0);
        }
        else if(a==2){
            cout << least() << endl;
        }
        else{
            int z = tree.size();
            remove(z-1);
        }
    }
}