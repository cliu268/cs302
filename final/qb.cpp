// https://www.xinyoudui.com/ac/contest/7770016630002E1011A334/problem/14021
/*
2.  Concert Tickets
XJOI - Problem ID: 14021 Required Problem 100pt(s)

Description
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest 
possible price such that it does not exceed the maximum price.

Input
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers ℎ1,ℎ2,…,ℎn: the price of each ticket.
The last line contains m integers t1,t2,…,tm: the maximum price for each customer in the order they arrive.

Output
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print −1.

Constraints
1 ≤ n,m ≤ 2⋅10^5
1 ≤ hi,ti ≤ 10^9
 
Example Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1
*/