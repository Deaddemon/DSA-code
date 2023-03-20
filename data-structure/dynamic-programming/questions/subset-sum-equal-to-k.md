https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954


similar ques: <br>
https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980
<br>
https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
<br>
https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
<br>
https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628
<br>
https://www.codingninjas.com/codestudio/problems/target-sum_4127362?

### recursion
```cpp
#include <bits/stdc++.h> 

//TC: 2^(N) : every element can either be selected or not selected
//SC: O(N) : recursion stack

bool helper(int i, int k ,vector<int> &arr ){

    if(k == 0) return true;
    if(i == 0 ) return arr[i] == k;

    //if not taken k is not changed, but we try to get ans from previous index
    bool notPick = helper( i-1 , k , arr);
    //if decided to pick,
    //we first have to check if the value at that index 
    //is less than equal to k, then only go for further recursion
    bool pick =  false;
    if(arr[i] <=  k){
        pick = helper( i-1 , k-arr[i] , arr);
    }

    return pick || notPick;


}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    //
    return helper( n-1 , k, arr);
}
```
 
 
### memoization
```cpp
#include <bits/stdc++.h>

//TC: O(N*k) 
//SC: O(N*K) + O(N) : dp array + recursion stack

bool helper(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {

  if (k == 0)
    return true;
  if (i == 0)
    return arr[i] == k;

  if (dp[i][k] != -1)
    return dp[i][k];

  // if not taken k is not changed, but we try to get ans from previous index
  bool notPick = helper(i - 1, k, arr, dp);
  // if decided to pick,
  // we first have to check if the value at that index
  // is less than equal to k, then only go for further recursion
  bool pick = false;
  if (arr[i] <= k) {
    pick = helper(i - 1, k - arr[i], arr, dp);
  }

  return dp[i][k] = pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
  //
  // here for every index , every stage of need to be considered
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));

  return helper(n - 1, k, arr, dp);
}
```

### tabulation
```cpp
#include <bits/stdc++.h>

//TC: O(N*k) 
//SC: O(N*K)   : dp array  

bool subsetSumToK(int n, int k, vector<int> &arr) {
  //
  // here for every index , every stage of need to be considered
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }

  if (arr[0] <= k) {
    dp[0][arr[0]] = true;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {

      bool notPick = dp[i - 1][j];
      bool pick = false;
      if (arr[i] <= j) {
        pick = dp[i - 1][j - arr[i]];
      }

      dp[i][j] = pick || notPick;
    }
  }

  return dp[n - 1][k];
}
```



### space optimisation
```cpp
#include <bits/stdc++.h>

//TC: O(N*k) 
//SC: O(K)   

bool subsetSumToK(int n, int k, vector<int> &arr) {
  //
  // here for every index , every stage of need to be considered
  // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  vector<bool> prev(k + 1, false);

  prev[0] = true;

  if (arr[0] <= k) {
    prev[arr[0]] = true;
  }

  for (int i = 1; i < n; i++) {

    vector<bool> temp(k + 1, false);
    //this is very very conceptual
    //it means once we get  k== 0 , a subset exist
    temp[0] = true;
    for (int j = 1; j <= k; j++) {

      bool notPick = prev[j];
      bool pick = false;
      if (arr[i] <= j) {
        pick = prev[j - arr[i]];
      }

      temp[j] = pick || notPick;
    }
    prev = temp;
  }

  return prev[k];
}
```


##### similar ques

 
https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980
```cpp
#include<bits/stdc++.h>

bool helper(int i , int k , vector<int> &arr){

	if(k==0) return true;
	if(i==0) return arr[i]==k;

	bool notPick = helper(i-1 , k , arr);
	bool pick = false;

	if(arr[i] <= k){
		pick = helper(i-1, k-arr[i] , arr);
	}

	return notPick || pick;
}

bool canPartition(vector<int> &arr, int n)
{
	// if the sum of all numbers is odd, it cant be partitioned
	// other wise
	// the sum of both array is sum/2
	//  s1 + s2 = sum , s1==s2
	// so even if there exist a single subset with sum/2, the other will obviously exist
	// now it breaks down to subset with sum k problem

	int sum =0 ;
	sum = accumulate(arr.begin() ,arr.end() , sum);

	if(sum%2==1) return false;
	else
	return helper( n-1 , sum/2 , arr );
}

```


https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

```cpp
#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

int minSubsetSumDifference(vector<int> &arr, int n) {
  //
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];

  int k = sum;
  vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }

  if (arr[0] <= k) {
    dp[0][arr[0]] = true;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {

      bool notPick = dp[i - 1][j];
      bool pick = 0;
      if (arr[i] <= j) {
        pick = dp[i - 1][j - arr[i]];
      }

      dp[i][j] = pick || notPick;
    }
  }

  int res = 1e9;
  for (int i = 0; i <= sum / 2; i++) {

    bool sm = dp[n - 1][i];
    if (sm == 1) {
      res = min(res, abs((sum - i) - i));
    }
  }

  return res;
}
```

https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
```cpp
#include <bits/stdc++.h>

int findWays(vector<int> &arr, int tar) {
  //https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
  int n = arr.size();
  int k = tar;
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));

  for (int i = 0; i < n; i++)
    dp[i][0] = 1;
  // in memoization
  //   if(k== 0 && arr[0]==0) return 2;
  //   if( k==0 || arr[0] == k) return 1;

  if (arr[0] == 0) {
    // first parameter is index
    //  second parameter is k
    dp[0][0] = 2;
  }

  if (arr[0] != 0 && arr[0] <= k) {
    dp[0][arr[0]] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {

      int notPick = dp[i - 1][j];
      int pick = 0;
      if (arr[i] <= j) {
        pick = dp[i - 1][j - arr[i]];
      }

      dp[i][j] = pick + notPick;
    }
  }
  return dp[n - 1][k];
}
```
https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628
```cpp
#include <bits/stdc++.h>

int mod = 1e9 + 7;
int helper(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {

  if (i == 0) {
    if (k == 0 && arr[0] == 0)
      return 2;
    if (k == 0 || arr[0] == k)
      return 1;
    return 0;
  }

  if (dp[i][k] != -1)
    return dp[i][k];

  int notPick = helper(i - 1, k, arr, dp);
  int pick = 0;
  if (arr[i] <= k) {
    pick = helper(i - 1, k - arr[i], arr, dp);
  }

  return dp[i][k] = (pick + notPick) % mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
  //
  int sum = accumulate(arr.begin(), arr.end(), 0);

  int k = sum - d;
  if (k % 2 == 1 || k < 0)
    return 0;

  vector<vector<int>> dp(n, vector<int>((k / 2) + 1, -1));

  return helper(n - 1, k / 2, arr, dp);
}

```

https://www.codingninjas.com/codestudio/problems/target-sum_4127362
```cpp
#include <bits/stdc++.h>

int helper(int i, int k, vector<int> &arr) {

  if (i == 0) {
    if (k == 0 && arr[0] == 0)
      return 2;
    if (k == 0 || arr[0] == k)
      return 1;
    return 0;
  }

  int notPick = helper(i - 1, k, arr);
  int pick = 0;
  if (arr[i] <= k) {
    pick = helper(i - 1, k - arr[i], arr);
  }

  return notPick + pick;
}
int targetSum(int n, int target, vector<int> &arr) {
  //

  // s1 - s2 = target
  // s1 + s2 = sum

  int sum = accumulate(arr.begin(), arr.end(), 0);

  if (sum - target < 0 || (sum - target) % 2 == 1)
    return 0;

  int k = (sum - target) / 2;

  return helper(n - 1, k, arr);
}

```
