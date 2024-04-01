// https://www.xinyoudui.com/ac/contest/77700141B0002E1011A278/problem/7450
/*
3.  Median
XJOI - Problem ID: 7450 Bonus Problem 100pt(s)

Description：
Given a  non-negative integer array Ai whose length is N, for all 1≤k≤(N+1)/2，print the median of A1,A3,…,A2k−1​. 
That is the median of the first 1,3,5,… numbers. 
Median: The middle number of a sorted array. The median of array Ai is the middle number of the sorted Ai.

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

Explanation:
For each Ai we have
Sorted A1 = 1. The median is 1.
Sorted A3 = 1 3 5. The median is 3.
Sorted A5 = 1 3 5 7 9. The median is 5.
Sorted A7 = 1 3 5 6 7 9 11. The median is 6.

Time and memory limit：1s，512MB
Source：yn
*/