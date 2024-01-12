 https://leetcode.com/problems/triangle/

### recursion
```c++

 
    int temp(int i , int j , int n, vector<vector<int>>& triangle  ){
        if(i== n-1){
            return triangle[i][j];
        }

        int move1 = triangle[i][j] + temp(i+1,j,n,triangle);
        int move2 = triangle[i][j] + temp(i+1,j+1,n,triangle);
        return   min(move1,move2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        int n= triangle.size(); 
        return temp(0,0,n, triangle );
         
          
        }
         
        
     
```

### memoization
```c++
//top down
// tc: O(n*n)
// sc: stack space + dp array

 
    int temp(int i , int j , int n, vector<vector<int>>& triangle , vector<vector<int>>& dp ){
        if(i== n-1){
            return triangle[i][j];
        }
        
        if(  dp[i][j] != -1) return dp[i][j];
        
         int move1 = triangle[i][j] + temp(i+1,j,n,triangle,dp);
        int move2 = triangle[i][j] + temp(i+1,j+1,n,triangle,dp);
        return dp[i][j] = min(move1,move2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        int n= triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return temp(0,0,n, triangle , dp);
         
          
        }
 
```

### tabulation
```c++
// tc: n*n
// sc: n*n
   
 int minimumTotal(vector<vector<int>>& triangle) {
        
        
        int n= triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int j=0 ; j<n ; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=  n-2  ;i >=0 ; i--){
            for(int j = i ; j>=0; j--){

                int move1 = triangle[i][j] + dp[i+1][j];
                int move2 = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(move1 , move2);
            }
        }
        return dp[0][0];
         
          
        }
         
```

### space-optmised
```c++
// space-optimised
    // sc: O(n)
     int minimumTotal(vector<vector<int>>& triangle) {
        
        
        int n= triangle.size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0); 

        for(int j=0 ; j<n ; j++){
            prev[j] = triangle[n-1][j];
        }

        for(int i=  n-2  ;i >=0 ; i--){
            for(int j = i ; j>=0; j--){

                int move1 = triangle[i][j] + prev[j];
                int move2 = triangle[i][j] + prev[j+1];

                curr[j] = min(move1 , move2);
            }

            prev = curr;
        }
        return prev[0];
         
          
        }
         
```
