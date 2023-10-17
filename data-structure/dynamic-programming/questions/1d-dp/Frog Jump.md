https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

### memoization
```c++
#include <bits/stdc++.h> 

int res(int ind , vector<int> &heights , vector<int> &dp){
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];
    int left = res( ind -1  , heights , dp) + abs(heights[ind] - heights[ind-1]);
    int right =INT_MAX;
    if(ind > 1){
        right = res( ind -2  , heights , dp) + abs(heights[ind] - heights[ind-2]);
    }
    return dp[ind] = min(left , right);

}
int frogJump(int n, vector<int> &heights)
{
    //memoization
    vector<int> dp( n , -1);
    return res(n-1 , heights , dp);
 
}

```
### tabulation
```c++
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
     
    //tabulation
    vector<int> dp( n , -1);
    dp[0] = 0;
    int l , r = INT_MAX;
    for(int i=1; i<n ; i++){
        l =  dp[i-1] + abs(heights[i] - heights[i-1]);
        if(i > 1){
            r = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] =  min(l ,r);
    }
    return dp[n-1];

    
}
```

### space optimization
```c++
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    
    //space optimised
    int last= 0 , last_to_last =0;
    int curr =0;
    for(int i=1 ; i<n ; i++){
        int l = last + abs(heights[i] - heights[i-1]);
        int r = INT_MAX;
        if(i > 1){
            r = last_to_last + abs(heights[i] - heights[i-2]);
        }
        curr = min(l , r);
        last_to_last = last;
        last = curr;
    }
    return last;

}
```
