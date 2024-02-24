
  https://geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
 
### recursion
```c++
 bool helper(int i, vector<int> &arr, int sum){
    
        if(sum==0) return true;
        if(i==0) return arr[0] == sum;
        
         
         bool notPick = helper(i-1 , arr, sum);
         
         bool pick = false;
         
         if(arr[i] <= sum){
             pick = helper(i-1 , arr, sum-arr[i]);
         }
         
         return notPick || pick;
    }

    bool isSubsetSum(vector<int>arr, int sum){
       
         return helper(arr.size()-1, arr, sum);
    }
```

### memoization
```c++
 
  bool helper(int i, vector<int> &arr, int sum, vector<vector<int>> & dp){
    
        if(sum==0) return true;
        if(i==0) return arr[0] == sum;
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
         
         bool notPick = helper(i-1 , arr, sum, dp);
         
         bool pick = false;
         
         if(arr[i] <= sum){
             pick = helper(i-1 , arr, sum-arr[i] , dp);
         }
         
         return dp[i][sum] = notPick || pick;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
       
         return helper(n-1, arr, sum , dp);
    }
}

// tc: O(n*sum)
//sc: O(n) + O(n*sum)
```

### tabulation
```c++
bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<vector<bool>> dp(n , vector<bool>(sum+1 , false));
        
        for(int i=0 ; i<n ; i++){
            dp[i][0] = true;
        }
        
        if(arr[0] <= sum){
            dp[0][arr[0]] = true;
        }
        
        
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<=sum ; j++){
                
                bool notPick = dp[i-1][j];
                bool pick = false;
                if(arr[i] <= j){
                    pick = dp[i-1][j-arr[i]];
                }
                
                
                dp[i][j] = notPick || pick;
                
            }
        }
       
       
         return dp[n-1][sum];
    }

// tc: O(n*sum)
// sc: O(n* sum)

```
