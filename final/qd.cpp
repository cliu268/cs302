// https://www.xinyoudui.com/ac/contest/7770016630002E1011A334/problem/14069
/*
4.  Flight Discount
XJOI - Problem ID: 14069Bonus Problem100pt(s)

Description
Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price 
of any single flight during the route. However, you can only use the coupon once.

Input
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,…,n. 
City 1 is Syrjälä, and city n is Metsälä.

After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, 
and its price is c. Each flight is unidirectional.

You can assume that it is always possible to get from Syrjälä to Metsälä.

Output
Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
When you use the discount coupon for a flight whose price is x, its price becomes ⌊x/2⌋ (it is rounded down to an integer).

Constraints
2 ≤ n ≤ 10^5
1 ≤ m ≤ 2⋅10^5
1 ≤ a,b ≤ n
1 ≤ c ≤ 10^9
 
Example Input:
3 4
1 2 3
2 3 1
1 3 7
2 1 5

Example Output:
2
*/