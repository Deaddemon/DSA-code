##### lcs based
https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879
<br>
https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207
<br>
 https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293
<br>
https://www.codingninjas.com/codestudio/problems/can-you-make_4244510
<br>
https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493
<br>
##### string matching
https://leetcode.com/problems/distinct-subsequences/
<br>
https://www.codingninjas.com/codestudio/problems/edit-distance_630420
<br>
https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650
<br>
##### theory
```
- a subsequence can be consecutive or cannot be consecutive but it always maintain the order

```

https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879<br>
```
-brute force : generate all subseq and compare one by one : exponential in nature
-genrate and compare on the way
-tabulation includes shifting of index
-try to print the dp array and learn how it got filled by looking at the code
-additional ques: also print the lcs subsequence
-additional ques: find longest palindromic subsequence
 

```
### recursion
```cpp
#include<bits/stdc++.h>

int helper(int i, int j , string s, string t ){
	if(i <0 || j<0) return 0;
	
	if( s[i] == t[j]){
		return 1 + helper(i-1 , j-1 , s, t);
	}else{
		return 0 + max(helper(i-1, j,  s, t) , helper(i, j-1 ,  s, t));
	}
}
int lcs(string s, string t)
{
	//
	int m = s.size() ;
	int n = t.size();
	return helper(m -1 , n-1 , s, t);
}
```
### memoization
```cpp
#include <bits/stdc++.h>

int helper(int i, int j, string s, string t, vector<vector<int>> &dp) {
  // if(i <0 || j<0) return 0;
  // shifting i and j right so tabulation can be implemented
  if (i == 0 || j == 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  // if( s[i] == t[j]){
  // shifting i and j right so tabulation can be implemented
  if (s[i - 1] == t[j - 1]) {
    return dp[i][j] = 1 + helper(i - 1, j - 1, s, t, dp);
  } else {
    return dp[i][j] =
               0 + max(helper(i - 1, j, s, t, dp), helper(i, j - 1, s, t, dp));
  }
}
int lcs(string s, string t) {
  //
  int m = s.size();
  int n = t.size();

  // vector<vector<int>> dp( m , vector<int>(n, -1));
  // shifting i and j right so tabulation can be implemented
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

  // return helper(m -1 , n-1 , s, t , dp);
  // shifting i and j right so tabulation can be implemented
  return helper(m, n, s, t, dp);
}
```
### tabulation
```cpp
#include <bits/stdc++.h>


int lcs(string s, string t) {
  //
  int m = s.size();
  int n = t.size();

  // vector<vector<int>> dp( m , vector<int>(n, -1));
  // shifting i and j right so tabulation can be implemented
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

  for(int i=0 ; i<m+1 ; i++) dp[i][0] = 0;
  for(int j=0 ; j<n+1 ; j++) dp[0][j] = 0;

  for(int i=1 ; i<m+1; i++){
	  for(int j=1 ; j<n+1 ; j++){
		  if(s[i-1] == t[j-1]){
			  dp[i][j] = 1 + dp[i-1][j-1];
		  }else{
			  dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		  }
	  }
  }

  
  return dp[m][n];
}
```
### space optimized
```cpp
#include <bits/stdc++.h>


int lcs(string s, string t) {
  //
  int m = s.size();
  int n = t.size();

  // vector<vector<int>> dp( m , vector<int>(n, -1));
  // shifting i and j right so tabulation can be implemented
  //vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
	vector<int> prev(n+1 , 0) , curr(n+1 , 0);

//   for(int i=0 ; i<m+1 ; i++) dp[i][0] = 0;
//   for(int j=0 ; j<n+1 ; j++) dp[0][j] = 0;
//resolves as we already initialized with 0

  for(int i=1 ; i<m+1; i++){
	  for(int j=1 ; j<n+1 ; j++){
		  if(s[i-1] == t[j-1]){
			  curr[j] = 1 + prev[j-1];
		  }else{
			  curr[j] = max(prev[j] , curr[j-1]);
		  }
	  }

	  prev= curr;
  }

  
  return prev[n];
}
```
##### for printing the lcs
```cpp
//add the below code in tabulation

 // for(int i=0 ; i<m+1; i++){
  //   for(int j=0 ; j<n+1 ; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  
string a ="";
  
  int i=m , j = n;
  while(i>0 && j>0) {
       if(s[i-1] == t[j-1]){
         a.push_back(s[i-1]);
         //cout<<s[i-1]<<" ";
         i = i-1;
         j= j-1;
       }else{
         if(dp[i-1][j] > dp[i][j-1]){
           i = i-1;
         }else{
           j = j-1;
         }
       }
    }
    cout<<a<<endl;
    reverse(a.begin(), a.end());
    cout<<a<<endl;
   ```
##### longest palindromic subsequence
```
given a string s
reverse the string , and lets call it t
now find the lcs of s and t
the res will give us longest palindromic subsequence
```
https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207
```cpp
//ex : acd axd
#include <bits/stdc++.h>
//  abcjklp acjkp , dp table:
// different from subseq , the way table is filled
// 0 0 0 0 0 0 
// 0 1 0 0 0 0 
// 0 0 0 0 0 0 
// 0 0 1 0 0 0 
// 0 0 0 2 0 0 
// 0 0 0 0 3 0 
// 0 0 0 0 0 0 
// 0 0 0 0 0 1 

int lcs(string &s, string &t) {
  int m = s.size();
  int n = t.size();

  // shifting i and j right so tabulation can be implemented
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  int ans = 0;

  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }
    //  for(int i=0 ; i<m+1; i++){
    //   for(int j=0 ; j<n+1 ; j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
 

  return ans;
}
``` 

https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293 
```cpp
// n - longest palindromic subseq
#include <bits/stdc++.h>
int minInsertion(string &str) {
  // catch: n - longest common palindrome(str)
  // longest common palindrome = lcs(str , rev_str);

  int n = str.size();
  string rev_str = str;
  reverse(rev_str.begin(), rev_str.end());

  // finding lcs through lcs
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

  for (int i = 0; i < n + 1; i++)
    dp[i][0] = 0;
  for (int j = 0; j < n + 1; j++)
    dp[0][j] = 0;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (str[i - 1] == rev_str[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return n - dp[n][n];
}
```

https://www.codingninjas.com/codestudio/problems/can-you-make_4244510
```cpp
//ex: a b c d  and  a n c
//catch : n + m - 2*lcs(str1 , str2)
#include <bits/stdc++.h>
int canYouMake(string &str, string &ptr) {
  //
  int n = str.size();
  int m = ptr.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

  for (int i = 0; i < n + 1; i++)
    dp[i][0] = 0;
  for (int j = 0; j < m + 1; j++)
    dp[0][j] = 0;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (str[i - 1] == ptr[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // cout<<dp[n][m]<<endl;
  // cout<<"----";
  return n- dp[n][m]  + m - dp[n][m];
}
```
 

https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493
```cpp
// common char are taken once - way to make it min
// follow up ques -  printing the shortest common superseq

#include <bits/stdc++.h> 

 
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	int n = a.size();
	int m = b.size();

	vector<vector<int>> dp( n+1 , vector<int>(m+1 , -1));

	for(int i=0 ; i<n+1 ; i++) dp[i][0] = 0;
	for(int j=0 ; j<m+1 ; j++) dp[0][j] = 0;

	//lcs k jaisa hi h thoda thoda
	// len: m +n - lcs(a , b)
	for(int i=1 ; i<n+1 ; i++){
		for(int j=1 ; j<m+1 ; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}
		}
	}

	//there is going to be out flow of one of the string and other string's char will be remained
	string ans = "";
	int i = n , j =m;
	while(i >0 && j> 0){

		if(a[i-1] == b[j-1]){
			ans += a[i-1];
			i--;
			j--;
			 
		}else if( dp[i-1][j] > dp[i][j-1]){
			ans += a[i-1];
			i--;
		}else{
			ans += b[j-1];
			j--;
		}

	}

// brute
// groot
	while(i>0){
		ans+= a[i-1];
		i--;
	}
	while(j > 0){
		ans+= b[j-1];
		j--;
	}
//cout<<ans<<endl;
	reverse(ans.begin() , ans.end());
	//cout<<ans<<endl;
	return ans;
}

```

## string matching

https://leetcode.com/problems/distinct-subsequences/
```cpp
// f(n-1 , m-1) no. of distinct suseq  of s2(from 0 to j) in s1(from 0 to i)
//   i   ,   j
```
### recursive 
```cpp
class Solution {
public:
int helper(int i , int j , string s , string t){

    //exhausting of string t
    if(j<0) return 1;
    //exhausting of string s
    if(i<0) return 0;

    //if matched
    if(s[i] == t[j]){

        //taking the curr char of s + not taking the curr char , in order to take from other place
        return helper(i-1 , j-1 , s, t) + helper(i-1 , j , s , t);

    }else{
        return helper(i-1 , j , s, t);
    }
}
    int numDistinct(string s, string t) {
        
        int n = s.size() ;
        int m = t.size();
        return helper(n-1 , m-1,  s, t);

        
    }
};
```
### memoization
```cpp
//code commented part shows 1-based implementation
class Solution {
public:
int helper(int i , int j , string s , string t , vector<vector<int>> &dp){

    //exhausting of string t
    //if(j==0) return 1;
    if(j<0) return 1;
    //exhausting of string s
    //if(i==0) return 0;
    if(i<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //if matched
    //if(s[i-1] == t[j-1]){
    if(s[i] == t[j]){

        //taking the curr char of s + not taking the curr char , in order to take from other place
        return dp[i][j] =  helper(i-1 , j-1 , s, t, dp) + helper(i-1 , j , s , t ,dp);

    }else{
        return dp[i][j] = helper(i-1 , j , s, t , dp);
    }
}
    int numDistinct(string s, string t) {
        
        int n = s.size() ;
        int m = t.size();
	// vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));
        // return helper(n , m,  s, t , dp);
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return helper(n-1 , m-1,  s, t , dp);

        
    }
};
```
### tabulation
```cpp
class Solution {
public:
int helper(int i , int j , string s , string t , vector<vector<int>> &dp){

    //exhausting of string t
    if(j==0) return 1;
    //exhausting of string s
    if(i==0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //if matched
    if(s[i-1] == t[j-1]){

        //taking the curr char of s + not taking the curr char , in order to take from other place
        return dp[i][j] =  helper(i-1 , j-1 , s, t, dp) + helper(i-1 , j , s , t ,dp);

    }else{ 
        return dp[i][j] = helper(i-1 , j , s, t , dp);
    }
}
    int numDistinct(string s, string t) {
        
        int n = s.size() ;
        int m = t.size();
        vector<vector<double>> dp(n+1 , vector<double>(m+1, 0));

        for(int i=0 ; i<n+1  ; i++){
            dp[i][0] = 1;
        }
        //already written for j=0
        for(int j=1 ; j<m+1 ; j++){
            dp[0][j] = 0;
        }

        for(int i=1 ; i<n+1 ; i++){
            for(int j=1 ; j<m+1 ; j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }


        return (int)dp[n][m];

        
    }
};
```
https://www.codingninjas.com/codestudio/problems/edit-distance_630420
 
 
https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650

