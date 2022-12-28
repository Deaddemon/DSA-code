https://codeforces.com/contest/1731/problem/C<br>

https://codeforces.com/problemset/submission/1731/187066894<br>

number of total subarrays: (n*(n+1))/2<br>
A number has odd number of divisors if it is a perfect square<br>
the maximum possible XOR sum of any subarray will be less than  2n<br>
there are only sqrt(n) perfect square from 1 to n <br>

it uses:<br>
Count Subarrays with Xor as K<br>
https://www.youtube.com/watch?v=lO9R5CaGRPY<br>
y = xr ^ k<br>

1.prefix xor , store in map with count<br>
2.check if prefix xor == k<br>
3. if 2nd true  cnt++<br>
4. y = xr * k <br>
5. check if y is in prerix map<br>
6. if true cnt+= mp[y]<br>
