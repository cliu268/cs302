// https://www.xinyoudui.com/ac/contest/7770016590002E1011B50F/problem/14072
/*
3.  Investigation
XJOI - Problem ID: 14072 Bonus Problem 100pt(s)

Description
You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:
what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 10^9 + 7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?

Input
The first input line contains two integers n and m: the number of cities and the number of flights. 
The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.
After this, there are m lines describing the flights. Each line has three integers a,b, and c: there is a flight from city a to city b with 
price c. All flights are one-way flights.
You may assume that there is a route from Syrjälä to Lehmälä.

Output
Print four integers according to the problem statement.

Constraints
1 ≤ n ≤ 10^5
1 ≤ m ≤ 2⋅10^5 
1 ≤ a,b ≤ n
1 ≤ c ≤ 10^9
Time limit: 1.00 s
Memory limit: 512 MB

Example Input:
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3

Output:
5 2 1 2
*/