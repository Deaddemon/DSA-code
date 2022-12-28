https://codeforces.com/contest/1731/problem/C

number of total subarrays: (n*(n+1))/2
A number has odd number of divisors if it is a perfect square
the maximum possible XOR sum of any subarray will be less than  2n
there are only sqrt(n) perfect square from 1 to n 

it uses:
Count Subarrays with Xor as K
https://www.youtube.com/watch?v=lO9R5CaGRPY
y = xr ^ k

1.prefix xor , store in map with count
2.check if prefix xor == k
3. if 2nd true  cnt++
4. y = xr * k 
5. check if y is in prerix map
6. if true cnt+= mp[y]
