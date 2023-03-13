
https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

### recursion
```cpp
#include <bits/stdc++.h>
// TC: 3^N : paths discovering
// SC: O(N)

int mn = -1e9;
int helper(int i, int j, int m, vector<vector<int>> &matrix) {

  if (j < 0 || j >= m)
    return mn;

  if (i == 0)
    return matrix[0][j];

  int down = matrix[i][j] + helper(i - 1, j, m, matrix);
  int left_diagonal = matrix[i][j] + helper(i - 1, j - 1, m, matrix);
  int right_diagonal = matrix[i][j] + helper(i - 1, j + 1, m, matrix);

  return max(down, max(left_diagonal, right_diagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
  //
  int n = matrix.size();
  int m = matrix[0].size();

  int mx = INT_MIN;
  vector<vector<int>> dp(n, vector<int>(m, -1));

  for (int j = 0; j < m; j++) {
    int res = helper(n - 1, j, m, matrix);
    mx = max(mx, res);
  }

  return mx;
}
```

### memoization
```cpp
#include <bits/stdc++.h>

//TC: O(N*M)
//SC: O(N*M) + O(N)  : dp array + recursion stack

int mn = -1e9;
int helper(int i, int j, int m, vector<vector<int>> &matrix,
           vector<vector<int>> &dp) {

  if (j < 0 || j >= m)
    return mn;

  if (i == 0)
    return matrix[0][j];

  if (dp[i][j] != -1)
    return dp[i][j];

  int down = matrix[i][j] + helper(i - 1, j, m, matrix, dp);
  int left_diagonal = matrix[i][j] + helper(i - 1, j - 1, m, matrix, dp);
  int right_diagonal = matrix[i][j] + helper(i - 1, j + 1, m, matrix, dp);

  return dp[i][j] = max(down, max(left_diagonal, right_diagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
  //
  int n = matrix.size();
  int m = matrix[0].size();

  int mx = INT_MIN;
  vector<vector<int>> dp(n, vector<int>(m, -1));

  for (int j = 0; j < m; j++) {
    int res = helper(n - 1, j, m, matrix, dp);
    mx = max(mx, res);
  }

  return mx;
}
```

### tabulation
```cpp
#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix) {

  int n = matrix.size();
  int m = matrix[0].size();

  vector<vector<int>> dp(n, vector<int>(m, -1));

  int maxi = INT_MIN;

  for (int j = 0; j < m; j++) {
    dp[0][j] = matrix[0][j];
  }

  for (int i = 1; i < n; i++) {

    for (int j = 0; j < m; j++) {

      int mx = INT_MIN;
      int down = matrix[i][j] + dp[i - 1][j];
      int left_diagonal = -1e9;
      if (j - 1 >= 0) {
        left_diagonal = matrix[i][j] + dp[i - 1][j - 1];
      }

      int right_diagonal = -1e9;
      if (j + 1 < m) {
        right_diagonal = matrix[i][j] + dp[i - 1][j + 1];
      }

      mx = max(down, max(left_diagonal, right_diagonal));
      dp[i][j] = mx;
    }
  }

  // all the last rows now contain ans out of which we have to select max one

  int res = INT_MIN;
  for (int j = 0; j < m; j++) {
    res = max(res, dp[n - 1][j]);
  }
  return res;
}
```

### space optimization
```cpp
#include <bits/stdc++.h>

//TC: O(N*M)
//SC: O(M)
int getMaxPathSum(vector<vector<int>> &matrix) {

  int n = matrix.size();
  int m = matrix[0].size();

  vector<int> prev(m);

  int maxi = INT_MIN;

  for (int j = 0; j < m; j++) {
    prev[j] = matrix[0][j];
  }

  for (int i = 1; i < n; i++) {

    vector<int> temp(m);

    for (int j = 0; j < m; j++) {

      int mx = INT_MIN;
      int down = matrix[i][j] + prev[j];
      int left_diagonal = -1e9;
      if (j - 1 >= 0) {
        left_diagonal = matrix[i][j] + prev[j - 1];
      }

      int right_diagonal = -1e9;
      if (j + 1 < m) {
        right_diagonal = matrix[i][j] + prev[j + 1];
      }

      mx = max(down, max(left_diagonal, right_diagonal));

      temp[j] = mx;
    }

    prev = temp;
  }

  // all the last rows now contain ans out of which we have to select max one

  int res = INT_MIN;
  for (int j = 0; j < m; j++) {
    res = max(res, prev[j]);
  }
  return res;
}
```
