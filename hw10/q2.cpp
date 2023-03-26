// B. (Floyd)
// https://www.xinyoudui.com/contest?courses=361&books=316&pages=12599&fragments=30285&problemId=1062&pattern=0
/*
Use the Floyed algorithm to find any two-point shortest path. Output the shortest path value for the two given pairs of nodes separately, 
and list the path nodes (the smallest one is output in lexicographic order).

input:
1 3
2 5
5 7
1 2 6
1 4 2
1 5 23
2 3 4
2 4 3
3 4 20
3 5 7

Output:
9
1 4 2 3
11
2 3 5

Input :
The first line has two integers s1, t1;
The second line has two integers s2, t2;
The third line has two integers n, m
The following m lines have three integers a, b, and c for each line, indicating that there is an edge between a and b, and the weight 
of the edge is c.

Output :
The shortest path from s1 to t1, and the output path (the smallest one is output in lexicographic order)
The shortest path from s2 to t2, and the output path (the smallest one is output in lexicographic order)

Sample input:
1 3
2 5
5 7
1 2 6
1 4 2
1 5 23
2 3 4
2 4 3
3 4 20
3 5 7

Sample output:
9
1 4 2 3
11
2 3 5

data range: n<=200,m<=40000,c<=10^9
time limit: 1000
memory limit: 65536
*/