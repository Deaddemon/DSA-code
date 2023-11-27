https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?

### recursion
```c++

int helper(int i, int last, vector<vector<int>> &points) {
  int mx = 0;
  if (i == 0) {

    for (int j = 0; j < 3; j++) {
      if (j != last) {
        mx = max(mx, points[0][j]);
      }
    }
    
    return mx;
  }
  mx = 0;
  for (int j = 0; j < 3; j++) {
    if (j != last) {
      int total = points[i][j] + helper(i - 1, j, points);
      mx = max(mx, total);
    }
  }

  return mx;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
  // we will take index as days
  // 0 1 2 represents col, so take 3 or some other number
  int last = 3;
  return helper(n - 1, last, points);
}
```

### memoization
```c++

int helper(int i, int last, vector<vector<int>> &points ,vector<vector<int>>&dp) {
  int mx = 0;
  if (i == 0) {

    for (int j = 0; j < 3; j++) {
      if (j != last) {
        mx = max(mx, points[0][j]);
      }
    }
    
    return mx;
  }

  if(dp[i][last] != -1) return dp[i][last];

  mx = 0;
  for (int j = 0; j < 3; j++) {
    if (j != last) {
      int total = points[i][j] + helper(i - 1, j, points, dp);
      mx = max(mx, total);
    }
  }

  return dp[i][last] = mx;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
  // we will take index as days
  // 0 1 2 represents col, so take 3 or some other number
  int last = 3;
  //note this 4 here
  vector<vector<int>> dp( n , vector<int>(4 , -1));
  return helper(n - 1, last, points , dp);
}
```

### tabulation
```c++

//TC: O(n*4*3)
//SC: O(n*4)
int ninjaTraining(int n, vector<vector<int>> &points) {
  // we will take index as days
  // 0 1 2 represents col, so take 3 or some other number
  int last = 3;
  vector<vector<int>> dp(n, vector<int>(4, -1));

  for (int i = 0; i < 4; i++) {
    int mx = 0;
    for (int j = 0; j < 3; j++) {
      if (j != i) {
        mx = max(mx, points[0][j]);
      }
    }
    dp[0][i] = mx;
  }

  for (int i = 1; i < n; i++) {
    // notice this loop of "last"
    for (int last = 0; last < 4; last++) {
      int mx = 0;
      for (int j = 0; j < 3; j++) {
        if (j != last) {
          int total = points[i][j] + dp[i - 1][j];
          mx = max(mx, total);
        }
      }
      dp[i][last] = mx;
    }
  }

  return dp[n - 1][3];
}
```
