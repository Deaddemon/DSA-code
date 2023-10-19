https://www.codingninjas.com/codestudio/problems/house-robber_839733

similar ques:
https://github.com/Deaddemon/DSA-code/blob/main/data-structure/dynamic-programming/questions/maximum-sum-of-non-adjacent-elements.md
### recursion
```c++
#include <bits/stdc++.h> 

int helper(int i , vector<int>& valueInHouse){
    if(i ==0 ) return valueInHouse[i];
    if(i == 1) return 0;

    int pick = valueInHouse[i] + helper(i-2, valueInHouse);
    int notPick = 0 + helper(i-1 , valueInHouse);

    return max(pick , notPick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // given that first and last house are neighbour
    //means they cant be robbed together
    int n= valueInHouse.size();

    vector<int> arr1, arr2;
    for(int i=1 ; i<n ; i++) arr1.push_back(valueInHouse[i]);
     
    for(int i=0 ; i<n-1 ; i++) arr1.push_back(valueInHouse[i]);

    n = n-1;
    int mx1 =  helper(n-1 , arr1);
    int mx2 =  helper(n-1 , arr2);

    return max(mx1 , mx2);

}
```

### memoization
```c++
#include <bits/stdc++.h> 

long long int helper(int i , vector<long long int>& valueInHouse , vector<long long int>&dp){
    if(i ==0 ) return valueInHouse[0];
    if(i < 0) return 0;

    if(dp[i] != -1) return dp[i];

    long long int pick = valueInHouse[i] + helper(i-2, valueInHouse , dp);
    long long int notPick = 0 + helper(i-1 , valueInHouse , dp);

    return dp[i] = max(pick , notPick);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // given that first and last house are neighbour
    //means they cant be robbed together
    int n= valueInHouse.size();
    if(n==1) return valueInHouse[0];

     
    vector<long long int> arr1, arr2;
      
    for(int i=1 ; i<n ; i++) arr1.push_back(valueInHouse[i]);
     
    for(int i=0 ; i<n-1 ; i++) arr2.push_back(valueInHouse[i]);

    n = n-1;

    vector<long long int> dp1(n , -1) , dp2(n , -1);


    long long int mx1 =  helper(n-1 , arr1 , dp1);
    long long int mx2 =  helper(n-1 , arr2, dp2);

    return max(mx1 , mx2);

}
```
