https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

### recursion

```cpp

//TC: greater than O(2^n)
//SC: greater than O(n)
//it is saying greater becuase we are standing at same index also

#include <bits/stdc++.h>

int helper(int i, int x, vector<int> &num) {

  if (i == 0) {
    if (x % num[0] == 0)
      return x / num[0];
    return 1e9;
  }

  int notPick = helper(i - 1, x, num);
  int pick = INT_MAX;
  if (num[i] <= x) {
    pick = 1 + helper(i, x - num[i], num);
  }

  return min(notPick, pick);
}
int minimumElements(vector<int> &num, int x) {
  // greedy wont work here
  // ex : 4 1 3 x= 7
  // through greedy 3 -2times 1 - 1time
  // but min possible are 3 - 1time 4 - 1time

  int n = num.size();
  int res = helper(n - 1, x, num);
  if (res >= 1e9) {
    return -1;
  } else {
    return res;
  }
}
```

### memoization
 ```cpp
 #include <bits/stdc++.h>

int helper(int i, int x, vector<int> &num, vector<vector<int>> &dp) {

  if (i == 0) {
    if (x % num[0] == 0)
      return x / num[0];
    return 1e9;
  }

  if (dp[i][x] != -1)
    return dp[i][x];

  int notPick = helper(i - 1, x, num, dp);
  int pick = INT_MAX;
  if (num[i] <= x) {
    pick = 1 + helper(i, x - num[i], num, dp);
  }

  return dp[i][x] = min(notPick, pick);
}
int minimumElements(vector<int> &num, int x) {
  // greedy wont work here
  // ex : 4 1 3 x= 7
  // through greedy 3 -2times 1 - 1time
  // but min possible are 3 - 1time 4 - 1time

  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(x + 1, -1));
  int res = helper(n - 1, x, num, dp);
  if (res >= 1e9) {
    return -1;
  } else {
    return res;
  }
}
```

### tabulation
```cpp
//TC: O(N*T)
//SC: O(N*T) : dp array
#include <bits/stdc++.h>

int minimumElements(vector<int> &num, int x) {
  // greedy wont work here
  // ex : 4 1 3 x= 7
  // through greedy 3 -2times 1 - 1time
  // but min possible are 3 - 1time 4 - 1time

  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(x + 1, -1));

  for (int k = 0; k < x + 1; k++) {
    if (k % num[0] == 0)
      dp[0][k] = k / num[0];
    else
      dp[0][k] = 1e9;
  }

  for (int i = 1; i < n; i++) {
    for (int k = 0; k < x + 1; k++) {

      int notPick = dp[i - 1][k];
      int pick = INT_MAX;
      if (num[i] <= k) {
        pick = 1 + dp[i][k - num[i]];
      }

      dp[i][k] = min(notPick, pick);
    }
  }
  int res = dp[n - 1][x];
  if (res >= 1e9) {
    return -1;
  } else {
    return res;
  }
}

```


### space optimisation

```cpp

//SC: O(x)

#include <bits/stdc++.h>

int minimumElements(vector<int> &num, int x) {
  // greedy wont work here
  // ex : 4 1 3 x= 7
  // through greedy 3 -2times 1 - 1time
  // but min possible are 3 - 1time 4 - 1time

  int n = num.size();
  vector<int> prev(x + 1, 0), curr(x + 1, 0);

  for (int k = 0; k < x + 1; k++) {
    if (k % num[0] == 0)
      prev[k] = k / num[0];
    else
      prev[k] = 1e9;
  }

  for (int i = 1; i < n; i++) {
    for (int k = 0; k < x + 1; k++) {

      int notPick = prev[k];
      int pick = INT_MAX;
      if (num[i] <= k) {
        pick = 1 + curr[k - num[i]];
      }

      curr[k] = min(notPick, pick);
    }

    prev = curr;
  }
  int res = prev[x];
  if (res >= 1e9) {
    return -1;
  } else {
    return res;
  }
}
```
