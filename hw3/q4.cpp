// D. The rank of binary search tree
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=9745&fragments=17996&problemId=8818&pattern=0
/*
Time limit：1s   Memory limit：256M

Description：
You have to write a data structure to maintain some data. The following operation should be provided:
1. Insert number x ；
2. Delete x（If there are several same numbers, only delete one of them）;
3. Inquiry about the rank of x（if there are several same numbers, print the highest rank）；
4. Find the number whose rank is x
5. Find the precedence of x（defined as the maximum number which is smaller than x）；
6. Find the successor of x （defined as the minimum number which is bigger than x）.

Input：
The first line contains the number n，which is the number of operations. The next n lines each contains two numbers opt and x. 
opt is the order number of operations（1≤opt≤6）.

Output：
For operations 3、4、5、6, print a number in each line, which is the answer.

Sample input 1：
10
1 92
1 91
3 91
4 1
1 50
4 2
1 100
1 64
1 64
6 59

Sample output 1：
1
91
91
64

Note： 1 <= n <= 500
*/
// Solution by XC220298(Alex Wu)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> arr;
  int a, b;
  for (int i=0; i<n; i++) {
    cin >> a >> b;
    if (a == 1) {
      auto index = lower_bound(arr.begin(), arr.end(), b);
      arr.insert(index, b);
    }
    else if (a == 2) {
      auto index = lower_bound(arr.begin(), arr.end(), b);
      arr.erase(index);
    }
    else if (a == 3) {
      auto index = lower_bound(arr.begin(), arr.end(), b);
      cout << index - arr.begin() + 1 << "\n";
    }
    else if (a == 4) {
      cout << arr[b-1] << "\n";
    }
    else if (a == 5) {
      auto index = lower_bound(arr.begin(), arr.end(), b);
      cout << arr[index-arr.begin()-1] << "\n";
    }
    else {
      auto index = upper_bound(arr.begin(), arr.end(), b);
      cout << arr[index-arr.begin()] << "\n";
    }
  }
}
 