https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?

##### theory
```
solve a prblm in pattern
certain rules:
1. start with entire block/array   
f(i,j)  start with i= starting point j = ending point
2. try all partitions
3. return the best possible 2 partition


```

https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?
```
-how many multiplication to be done in matrix chain multiplication
- given the matrix dimensions 
- []2x2   []2X1   
- ans 2 X 2(common) X 1
- for example : ABC
- A(BC)  or (AB)C
f(1,4) return the min multiplcation to multiply matrix1 -> matrix4
memoization: O(N^3)
```
