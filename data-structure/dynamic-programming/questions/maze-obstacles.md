https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=0

##### dp on grids with obstacle
### recursion
```cpp

TC: O( 2^(n*m) )
SC: path length  == recursive stack space  : O( (n-1) + (m-1) )

int mod = (int)(1e9 + 7);

int helper(int i, int j, vector<vector<int>> &mat) {
  if (i >= 0 && j >= 0 && mat[i][j] == -1)
    return 0;
  if (i == 0 && j == 0)
    return 1;

  if (i < 0 || j < 0)
    return 0;

  int up = 0;
  int left = 0;
  up = helper(i - 1, j, mat);
  left = helper(i, j - 1, mat);
  // either u use this if statements
  // or use a extra base case
  // option 1:
  // if( i>=0 && mat[i][j] == -1) return 0;
  // option 2:
  //   if (i - 1 >= 0 && mat[i - 1][j] != -1) {
  //     up = helper(i - 1, j, mat, dp);
  //   }
  //   if (j - 1 >= 0 && mat[i][j - 1] != -1) {
  //     left = helper(i, j - 1, mat, dp);
  //   }

  return (up + left) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {

  return helper(n - 1, m - 1, mat);
}
```

### memoization
```cpp

TC: O( n*m)
SC: path length == recursive stack space  + dp array : O( (n-1) + (m-1) ) + O( n*m)

int mod = (int)(1e9 + 7);

int helper(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
  if (i >= 0 && j >= 0 && mat[i][j] == -1)
    return 0;
  if (i == 0 && j == 0)
    return 1;

  if (i < 0 || j < 0)
    return 0;
  // means a pre-computed value found
  if (dp[i][j] != -1)
    return dp[i][j] % mod;

  int up = 0;
  int left = 0;
  up = helper(i - 1, j, mat, dp);
  left = helper(i, j - 1, mat, dp);
  // either u use this if statements
  // or use a extra base case
  // option 1:
  // if( i>=0 && mat[i][j] == -1) return 0;
  // option 2:
  //   if (i - 1 >= 0 && mat[i - 1][j] != -1) {
  //     up = helper(i - 1, j, mat, dp);
  //   }
  //   if (j - 1 >= 0 && mat[i][j - 1] != -1) {
  //     left = helper(i, j - 1, mat, dp);
  //   }

  return dp[i][j] = (up + left) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {

  // memoization
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return helper(n - 1, m - 1, mat, dp);
}
```

### tabulation
 ```cpp
 
TC: O( n*m)
SC:  dp array : O( n*m)

int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  vector<vector<int>> dp(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // mat[i][j] == -1 is a hurdle, skip it
      if (mat[i][j] == -1)
        dp[i][j] = 0;
      else if (i == 0 && j == 0)
        dp[i][j] = 1;
      else {
        // left up are the counts of path
        int left = 0, up = 0;
        if (i > 0) {
          up = dp[i - 1][j] % mod;
        }
        if (j > 0) {
          left = dp[i][j - 1] % mod;
        }
        dp[i][j] = (up + left) % mod;
      }
    }
  }

  return (dp[n - 1][m - 1]) % mod;
}
```

### space optimization
```cpp

TC: O( n*m)
SC:  prev array : O( m)

int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {

  // refer dp on grids for better understanding
  vector<int> prev(m, 0);

  for (int i = 0; i < n; i++) {

    vector<int> temp(m, 0);
    for (int j = 0; j < m; j++) {
      // mat[i][j] == -1 is a hurdle, skip it
      if (mat[i][j] == -1)
        temp[j] = 0;
      else if (i == 0 && j == 0)
        temp[j] = 1;
      else {
        // left up are the counts of path
        int left = 0, up = 0;
        if (i > 0) {
          up = prev[j] % mod;
        }
        if (j > 0) {
          left = temp[j - 1] % mod;
        }
        temp[j] = (up + left) % mod;
      }
    }

    prev = temp;
  }

  return (prev[m - 1]) % mod;
}
```
