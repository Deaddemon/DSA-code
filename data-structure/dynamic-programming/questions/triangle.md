https://www.codingninjas.com/codestudio/problems/triangle_1229398

### recursion
```cpp
#include <bits/stdc++.h> 

TC: 1 + 2 + 3 + 4 + 5 _ _ n   everyone have 2 pos 
    approx: 2^(n*(n+1)/2)
SC: recursion stack : O(N)

int helper( int i , int j , int n  , vector<vector<int>>& triangle  ){
	//try to draw the recursion tree

	//at last row
	if(i == n-1) return triangle[i][j];
	//there will not be any base case for diagonal , it can never exceed diagonally

	int down =triangle[i][j] +  helper(i +1 , j , n , triangle);
	int diagonal = triangle[i][j] + helper(i+1, j+1 , n , triangle);

	return min(down , diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// fixed starting point , variable ending point example
	// we will write recursion from 0,0
	// that doesnot change the definitions and roles of recurrence , memoization and tabulation
	// recurrence : is still top-down , goes down the tree to get answer
	// memoization : is still top-down approach of dp implementaion
	// tabulation : is still bottom - up approach of dp implementaion
	//				calulates the base case 
	// and most imp - it is a 2D dp
	// remember to take i j

	return helper(0, 0 , n,triangle);

}
```



### memoization
```cpp
#include <bits/stdc++.h> 

TC: ON*N)  almost half of this
SC: recursion stack  + dp array : O(N) + O(N*N)

int helper( int i , int j , int n  , vector<vector<int>>& triangle , vector<vector<int>>& dp ){
	//try to draw the recursion tree

	//at last row
	if(i == n-1) return triangle[i][j];
	//there will not be any base case for diagonal , it can never exceed diagonally

	if(dp[i][j] != -1) return dp[i][j];
	
	int down = triangle[i][j] +  helper(i +1 , j , n , triangle , dp);
	int diagonal = triangle[i][j] + helper(i+1, j+1 , n , triangle , dp);

	return dp[i][j] = min(down , diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// fixed starting point , variable ending point example
	// we will write recursion from 0,0
	// that doesnot change the definitions and roles of recurrence , memoization and tabulation
	// recurrence : is still top-down , goes down the tree to get answer
	// memoization : is still top-down approach of dp implementaion
	// tabulation : is still bottom - up approach of dp implementaion
	//				calulates the base case 
	// and most imp - it is a 2D dp
	// remember to take i j

	vector<vector<int>> dp( n, vector<int>(n , -1));
	return helper(0, 0 , n,triangle , dp);

}
```

### tabulation
```cpp
#include <bits/stdc++.h> 
 
TC: O(n*n) half of this
SC: O(n*n) : dp array

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// fixed starting point , variable ending point example
	// we will write recursion from 0,0
	// that doesnot change the definitions and roles of recurrence , memoization and tabulation
	// recurrence : is still top-down , goes down the tree to get answer
	// memoization : is still top-down approach of dp implementaion
	// tabulation : is still bottom - up approach of dp implementaion
	//				calulates the base case 
	// and most imp - it is a 2D dp
	// remember to take i j

	vector<vector<int>> dp( n, vector<int>(n , -1));

	//for all the bottom row elements
	for(int j=0 ; j<n ; j++){
		dp[n-1][j] = triangle[n-1][j];
	}

	for(int i= n-2 ; i>=0 ; i--){
		for(int j=i ; j>=0 ; j--){
			int down = triangle[i][j] + dp[i+1][j];
			int diagonal = triangle[i][j] + dp[i+1][j+1];

			dp[i][j] = min(down , diagonal);
		}
	}

	//as the end point is our base case , coz it is varible point,
	//our ans will be stored at 0,0 
	return dp[0][0];

}
```

### space optimization
```cpp
#include <bits/stdc++.h> 
 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// fixed starting point , variable ending point example
	// we will write recursion from 0,0
	// that doesnot change the definitions and roles of recurrence , memoization and tabulation
	// recurrence : is still top-down , goes down the tree to get answer
	// memoization : is still top-down approach of dp implementaion
	// tabulation : is still bottom - up approach of dp implementaion
	//				calulates the base case 
	// and most imp - it is a 2D dp
	// remember to take i j

	vector<int> prev(n);

	//for all the bottom row elements
	for(int j=0 ; j<n ; j++){
		prev[j] = triangle[n-1][j];
	}

	for(int i= n-2 ; i>=0 ; i--){
		vector<int> temp(n);
		for(int j=i ; j>=0 ; j--){
			int down = triangle[i][j] + prev[j];
			int diagonal = triangle[i][j] + prev[j+1];

			temp[j] = min(down , diagonal);
		}
		prev = temp;
	}

	//as the end point is our base case , coz it is varible point,
	//our ans will be stored at 0,0 
	return prev[0];

}
```
