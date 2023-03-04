https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

### recursion

```c++
#include <bits/stdc++.h> 

int helper(int i , vector<int>&nums){

    if( i == 0) return nums[i];
    // take example with n-1 = 4 and understand
    
    if( i< 0) return 0;

    int pick = nums[i] + helper( i-2 , nums);
    int notPick =  0 + helper(i , nums);

    return max(pick , notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();

    return helper(n-1 , nums);
}
```

### memoization
```c++
#include <bits/stdc++.h> 

int helper(int i , vector<int>&nums , vector<int>&dp){

    if( i == 0) return nums[i];
    if( i< 0) return 0;

    if(dp[i] != -1) return dp[i];

    int pick = nums[i] + helper( i-2 , nums , dp);
    int notPick =  0 + helper(i , nums , dp);

    return dp[i] =  max(pick , notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // memoization - top down approach of dp
    int n = nums.size();

    vector<int> dp( n , -1);
    return helper(n-1 , nums , dp);

}
```

### tabulation
```c++
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // tabulation- bottom up approach
    int n = nums.size();

    vector<int> dp( n , -1);
     

    dp[0] = nums[0];
    dp[-1] = 0;

    for(int i=1 ; i<n ; i++){
        int pick = nums[i] + dp[i-2];
        int notPick = 0 + dp[i-1];
        dp[i] = max(pick , notPick);

    }
    return dp[n-1];
}
```

### space optimisation
```c++
#include <bits/stdc++.h> 
 
int maximumNonAdjacentSum(vector<int> &nums){
     
    int n = nums.size();
 

    int prev = nums[0] , prev2 =0;
     
    for(int i=1 ; i<n ; i++){
         
        int pick= nums[i] +prev2  ;
         
        int notPick = 0 + prev;
        int curr = max(pick  , notPick);
        prev2 = prev;
        prev= curr;

    }
    //if look ends at n , our ans will be in n-1,i.e prev
    return prev;
}
```

