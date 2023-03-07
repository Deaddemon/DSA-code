https://codingninjas.com/codestudio/problems/minimum-path-sum_985349

##### min path sum (2D dp)

### recursion
```cpp
#include <bits/stdc++.h>

//TC: O(2^(m*n) )
//SC: recursive stack space: path length : O( (m-1) + (n-1) )
int helper(int i, int j, vector<vector<int>> &grid) {

  if (i == 0 && j == 0)
    return grid[i][j];
  // it has to return a big value
  // so that the path is not considered
  if (i < 0 || j < 0)
    return 1e9;

  int down = helper(i - 1, j, grid) + grid[i][j];
  int left = helper(i, j - 1, grid) + grid[i][j];

  return min(down, left);
}
int minSumPath(vector<vector<int>> &grid) {
  //
  int n = grid.size();
  int m = grid[0].size();

  return helper(n - 1, m - 1, grid);
}
```

### memoization
```cpp
#include <bits/stdc++.h>
//TC: O(m*n)
//SC: recursive stack space + dp array : path length  + dp array : O( (m-1) + (n-1) ) + O(m*n)


int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {

  if (i == 0 && j == 0)
    return grid[i][j];
  // it has to return a big value
  // so that the path is not considered
  if (i < 0 || j < 0)
    return 1e9;

  if (dp[i][j] != -1)
    return dp[i][j];

  int down = helper(i - 1, j, grid , dp) + grid[i][j];
  int left = helper(i, j - 1, grid, dp) + grid[i][j];

  return dp[i][j] = min(down, left);
}
int minSumPath(vector<vector<int>> &grid) {
  //
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<int>> dp(n, vector<int>(m, -1));
  return helper(n - 1, m - 1, grid, dp);
}
```

### tabulation
```cpp
#include <bits/stdc++.h>

//TC: O(m*n)
//SC: dp array :  O(m*n)

int minSumPath(vector<vector<int>> &grid) {
  // tabulation
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<int>> dp(n, vector<int>(m, -1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0)
        dp[i][j] = grid[i][j];
      else {

        int down = 1e9, left = 1e9;
        if (i > 0) {
          down = grid[i][j] + dp[i - 1][j];
        }
        if (j > 0) {
          left = grid[i][j] + dp[i][j - 1];
        }

        dp[i][j] = min(down, left);
      }
    }
  }
  return dp[n - 1][m - 1];
}
```

### space optimization
```cpp
#include <bits/stdc++.h>

//TC: O(m*n)
//SC: prev array : O(m)

int minSumPath(vector<vector<int>> &grid) {
  // tabulation
  int n = grid.size();
  int m = grid[0].size();

  vector<int> prev(m, 0);

  for (int i = 0; i < n; i++) {

    vector<int> temp(m, 0);

    for (int j = 0; j < m; j++) {

      if (i == 0 && j == 0)
        temp[j] = grid[i][j];
      else {

        int down = 1e9, left = 1e9;
        if (i > 0) {
          down = grid[i][j] + prev[j];
        }
        if (j > 0) {
          left = grid[i][j] + temp[j - 1];
        }

        temp[j] = min(down, left);
      }
    }
    // now this current completed temp becomes prev
    prev = temp;
  }
  return prev[m - 1];
}
```
