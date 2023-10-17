https://atcoder.jp/contests/dp/tasks/dp_b

### memoization
```c++
#include <bits/stdc++.h>
using namespace std;

#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int long long
//int mx = 1e7 + 1;

 
 
int helper(int i , int k , vector<int>&v , vector<int>&dp){
	if(i == 0) return 0;
	
	if(dp[i] != -1) return dp[i];
	
	int mn = INT_MAX;
	for(int j = 1 ; j<= k ;j++){
		int jump = INT_MAX;
		if(i - j >=0){
      //try doing with k=2 on notebook , it is a generalization for the previous frog jump prblm
      //https://github.com/Deaddemon/DSA-code/blob/main/data-structure/dynamic-programming/questions/Frog%20Jump.md
			jump = helper(i-j , k ,v , dp) + abs(v[i] - v[i-j]);
		}
		mn = min(mn , jump);
	}
	return dp[i] =  mn;
}
signed main(){
	FastIO
	  
	  
	  int n,k;
	  cin>>n>>k;
	  vector<int> v(n) ;
	  for(int i=0 ; i<n ; i++){
	  	cin>>v[i];
	  }
	  vector<int> dp( n , -1);
	  
	  cout<<helper( n-1 , k , v , dp);
	
  return 0;
	 }
	 

```

### tabulation 
```c++
#include <bits/stdc++.h>
using namespace std;

#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int long long
//int mx = 1e7 + 1;
 
signed main(){
	FastIO
	  
 
	  int n,k;
	  cin>>n>>k;
	  vector<int> v(n) ;
	  for(int i=0 ; i<n ; i++){
	  	cin>>v[i];
	  }
	  vector<int> dp( n , -1);
	  
	 //see memoization in parallel to clearly understand 
	  //tabulation is bottom- up approach , we start from 0 goes to destination
	  dp[0] = 0;
	  for(int i= 1; i <n ; i++){
	  	
	  	int val = INT_MAX , mn = INT_MAX;
	  	for(int j = 1; j<= k; j++){
	  		 
	  		if(i - j>=0){
	  			val = dp[i-j] +
	  			abs(v[i] - v[i-j]);
	  		}
	  		mn= min(mn, val);
	  		
	  	}
	  	
	  	dp[i] = mn;
	  }
	  
	  cout<<dp[n-1];
	
 
 
  return 0;
	 }
	 
 
 

```

### space optimzation
store that k elements in a slit
