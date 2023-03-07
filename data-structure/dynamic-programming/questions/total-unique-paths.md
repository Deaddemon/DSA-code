https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

##### dp on grids

### recursion
```cpp

//TC: O(2^(m*n) )
//SC: recursive stack space: path length : O( (m-1) + (n-1) )
#include <bits/stdc++.h> 

int helper(int i , int j){
	if(i ==0 && j==0) return 1;
	if( i< 0 || j<0 ) return 0;

	//see we are doing top-down approach that why movement of direction are different 
	//from   i, j (m-1 , n-1)
	//go up
	int up = helper(i-1 , j);
	//go left
	int left = helper(i , j-1);

	//we have to return total ways , so add up and left
	return up + left;
}
int uniquePaths(int m, int n) {
	

	return helper(m-1 , n-1 );
}
```

### memoization
```cpp

//TC: O(m*n)
//SC: recursive stack space + dp array : path length  + dp array : O( (m-1) + (n-1) ) + O(m*n)

#include <bits/stdc++.h> 

int helper(int i , int j , vector<vector<int>> &dp){
	if(i ==0 && j==0) return 1;
	if( i< 0 || j<0 ) return 0;


	//dp
	if(dp[i][j] != -1) return dp[i][j];

	//see we are doing top-down approach that why movement of direction are different 
	//from   i, j (m-1 , n-1)
  //will go and come back
	//go up
	int up = helper(i-1 , j , dp);
	//go left
	int left = helper(i , j-1 , dp);


	//we have to return total ways , so add up and left
	return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) {
	
	//there exist a set of overlapping prblm
	//we are calculating various paths again and again
	// hence we can use dp here

	//memoization
	vector<vector<int>> dp(m , vector<int>(n , -1));
	return helper(m-1 , n-1, dp );
}
```
### tabulation
```cpp
//TC: O(m*n)
//SC: dp array :  O(m*n)

#include <bits/stdc++.h>

int uniquePaths(int m, int n) {

  // there exist a set of overlapping prblm
  // we are calculating various paths again and again
  //  hence we can use dp here

  // tabulation
  vector<vector<int>> dp(m, vector<int>(n, -1));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      if (i == 0 && j == 0) {
        // this step
        dp[i][j] = 1;
        continue;
      }
      // path coming from up
      // path coming from left
      int up = 0, left = 0;
      if (i > 0) {
        up = dp[i - 1][j];
      }
      if (j > 0) {
        left = dp[i][j - 1];
      }

      dp[i][j] = up + left;
    }
  }

  return dp[m - 1][n - 1];
}
```

### space optimised 
```cpp
#include <bits/stdc++.h>

//TC: O(m*n)
//SC: O(n)
int uniquePaths(int m, int n) {

  // there exist a set of overlapping prblm
  // we are calculating various paths again and again
  //  hence we can use dp here

  // space optimzation
  // length of prev array is equal to length of a row
  vector<int> prev(n, 0);

  for (int i = 0; i < m; i++) {

    // this vector keep adding every jth indexed element of ith row
    vector<int> temp(n, 0);

    for (int j = 0; j < n; j++) {

      if (i == 0 && j == 0) {
        // this step
        temp[j] = 1;
        continue;
      }
      // path coming from up
      // path coming from left
      int up = 0, left = 0;
      if (i > 0) {
        up = prev[j];
      }
      if (j > 0) {
        // element of left is inside temp[j-1];
        left = temp[j - 1];
      }

      temp[j] = up + left;
    }

    prev = temp;
  }

  return prev[n - 1];
}
```
