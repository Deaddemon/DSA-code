https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

<!-- weight[] = {1, 1, 1}, W = 2, profit[] = {10, 20, 30}
starting at index 3, with given weight as 2

                                                     K(3, 2)  
                                          /                         \ 
                                       /                             \               
                          K(2, 2)                                K(2, 1)
                     /               \                           /               \ 
                  /                   \                       /                   \
          K(1, 2)               K(1, 1)            K(1, 1)       K(1, 0)
           /     \                  /       \                /                  \
        /         \              /           \            /                      \
K(0, 2)  K(0, 1)  K(0, 1)  K(0, 0)  K(0, 1)          K(0, 0) -->


### recursion

```cpp
#include <bits/stdc++.h>

TC: 
int helper(int i, int w, vector<int> weight, vector<int> value) {

  if (i == 0) {
    if (weight[0] <= w)
      return value[0];
    else
      return 0;
  }

  int notPick = helper(i - 1, w, weight, value);
  int pick = INT_MIN;
  if (weight[i] <= w) {
    pick = value[i] + helper(i - 1, w - weight[i], weight, value);
  }

  return max(notPick, pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // w=  1 2 4 5
  // v = 5 4 8 6

  return helper(n - 1, maxWeight, weight, value);
}
```

### memoization
```cpp
#include <bits/stdc++.h>

int helper(int i, int w, vector<int> &weight, vector<int> &value , vector<vector<int>> &dp) {

  if (i == 0) {
    if (weight[0] <= w)
      return value[0];
    else
      return 0;
  }

  if(dp[i][w]  != -1) return dp[i][w];

  int notPick = helper(i - 1, w, weight, value , dp);
  int pick = INT_MIN;
  if (weight[i] <= w) {
    pick = value[i] + helper(i - 1, w - weight[i], weight, value , dp);
  }

  return dp[i][w] = max(notPick, pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // w=  1 2 4 5
  // v = 5 4 8 6
  vector<vector<int>> dp( n, vector<int>(maxWeight+1, -1));
  return helper(n - 1, maxWeight, weight, value , dp);
}
```

### tabulation
```cpp
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // w=  1 2 4 5
  // v = 5 4 8 6
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

  for (int w = weight[0]; w < maxWeight + 1; w++) {
    dp[0][w] = value[0];
  }

  for (int i = 1; i < n; i++) {
    for (int w = 0; w < maxWeight + 1; w++) {
      int notPick = 0 + dp[i - 1][w];
      int pick = INT_MIN;
      if (weight[i] <= w) {
        pick = value[i] + dp[i - 1][w - weight[i]];
      }

      dp[i][w] = max(notPick, pick);
    }
  }

  return dp[n - 1][maxWeight];
}
```

### space optimization

```cpp
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // w=  1 2 4 5
  // v = 5 4 8 6
  vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);

  for (int w = weight[0]; w < maxWeight + 1; w++) {
    prev[w] = value[0];
  }

  for (int i = 1; i < n; i++) {
    for (int w = 0; w < maxWeight + 1; w++) {
      int notPick = 0 + prev[w];
      int pick = INT_MIN;
      if (weight[i] <= w) {
        pick = value[i] + prev[w - weight[i]];
      }

      curr[w] = max(notPick, pick);
    }

    prev = curr;
  }

  return prev[maxWeight];
}
```
