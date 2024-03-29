https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405
<br>
https://www.codingninjas.com/codestudio/problems/selling-stock_630282
<br>
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
<br>
https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698
<br>
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
<br>
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
<br>


#### theory
```cpp
- must do space optimisation in interview
```

https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405
```
calculating the minimum for every index , start from 0th index doesn't make sense
using mn , which is remembering the past
```
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n= prices.size();
        int mn = INT_MAX;
        //int mn = prices[0];
        int mx = 0;
        
        //for(int i=1 ; i<n ;i++)
        for(int i=0 ; i<n ; i++)
        {
            if(prices[i] < mn){
                mn = prices[i];

            }
            else if(prices[i] - mn > mx){
                mx = prices[i] - mn;
            }
        }
        return mx;
        
    }
};
```

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
```cpp
//we have to know if we bought previously or not
//acc to that we will be  selling/buying 
// storing min like we did in prev ques wont work , coz here we have to 
// explore all paths
//selling must before buying

//algo: every element have only two possibility , can buy or cannot buy(can sell)

```
### recursion
```cpp
class Solution {
public:
//take or not take concept
int helper(int i , int take ,vector<int>& prices ){

    if(i == prices.size()) return 0;

    if(take){
        return max(-prices[i] + helper(i+1 , 0 , prices) , helper(i+1 , 1, prices));
    } else{
        return max( prices[i] + helper(i+1 , 1 , prices) , helper(i+1 , 0 , prices));
    }    
}
    int maxProfit(vector<int>& prices) {


        return helper(0, 1 , prices);
        
    }
};
```

### memoization
```cpp
class Solution {
public:
//take or not take concept
int helper(int i , int take ,vector<int>& prices, vector<vector<int>>&dp ){

    if(i == prices.size()) return 0;

    if(dp[i][take] != -1) return dp[i][take];

    if(take){
        return dp[i][take] =  max(-prices[i] + helper(i+1 , 0 , prices , dp) , helper(i+1 , 1, prices, dp));
    } else{
        return dp[i][take] = max( prices[i] + helper(i+1 , 1 , prices, dp) , helper(i+1 , 0 , prices, dp));
    }     
}
    int maxProfit(vector<int>& prices) {

        int n= prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2, -1));
 
        return helper(0, 1 , prices);
        
    }
};
```
### tabulation
```cpp
class Solution {
public:
//take or not take concept

    int maxProfit(vector<int>& prices) {

        int n= prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2, -1));

        for(int take =0 ; take <2 ; take++){
            dp[n][take] =0;
        }

        for(int i = n-1 ; i>=0 ; i-- ){
            for(int take= 0; take<2 ; take++){
                if(take){
                    dp[i][take] = max(-prices[i] + dp[i+1][0] , 0 + dp[i+1][1] );
                }else{
                    dp[i][take] = max(prices[i] + dp[i+1][1] , 0 + dp[i+1][0] );
                }
            }
        }
        return dp[0][1];
        
    }
};

```
### space optimisation
```cpp
class Solution {
public:
//take or not take concept
 
    int maxProfit(vector<int>& prices) {

        int n= prices.size();
       // vector<vector<int>> dp(n+1 , vector<int>(2, -1));

        vector<int> next(2, 0);

        for(int take =0 ; take <2 ; take++){
            next[take] =0;
        }

        for(int i = n-1 ; i>=0 ; i-- ){
            vector<int> curr(2, 0);
            for(int take= 0; take<2 ; take++){
                if(take){
                    curr[take] = max(-prices[i] + next[0] , 0 + next[1] );
                }else{
                   curr[take] = max(prices[i] + next[1] , 0 + next[0] );
                }
            }

            next = curr;
        }
        return next[1];
        
    }
};
```

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
```cpp
//general intutive is of 3d dp (not so visually appealing)
// try doing it with dp[n+][4]
// some also do it with 4 variables
```
### recursion
```cpp
class Solution {
public:

int helper(int i , int buy , int cap , vector<int>& prices, int n ){
    
    if(cap == 0) return 0; 
    if( i== n) return 0;

    if( buy ){
        return max( -prices[i] + helper(i+1 , 0 , cap , prices , n) , 
         0 + helper(i+1 , 1 , cap , prices , n));
    }else{
        return max( prices[i] + helper(i+1 , 1 , cap-1 , prices , n) ,
        helper(i+1 , 0, cap , prices , n));
    }

}
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        return helper(0 , 1 , 2, prices , n);
        
    }
};
```
### memoization
```cpp
class Solution {
public:

int helper(int i , int buy , int cap , vector<int>& prices, int n , vector<vector<vector<int>>> &dp){
    
    if(cap == 0) return 0; 
    if( i== n) return 0;

    if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

    if( buy ){
        return dp[i][buy][cap]= max( -prices[i] + helper(i+1 , 0 , cap , prices , n, dp) , 
         0 + helper(i+1 , 1 , cap , prices , n, dp));
    }else{
        return dp[i][buy][cap] = max( prices[i] + helper(i+1 , 1 , cap-1 , prices , n , dp) ,
        helper(i+1 , 0, cap , prices , n , dp));
    }

}
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp( n, vector<vector<int>>(2 , vector<int>(3 , -1)));

         
        return helper(0 , 1 , 2, prices , n , dp);
        
    }
};
```
### tabulation
```cpp
class Solution {
public:
 
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp( n+1, vector<vector<int>>(2 , vector<int>(3 , 0)));
        // for(int buy =0 ; buy <2 ; buy++){
        //     for(int cap =0 ; cap<3 ; cap++){
        //         dp[n][buy][cap] = 0;
        //     }
        // }
        // // cap == 0
        // for(int i=0  ; i<n ; i++){
        //     for(int buy =0 ; buy <2 ; buy++){
        //             dp[i][buy][0]= 0;
        //     }
        // }
        
        // all loops start from opposite
        for(int i= n-1 ; i>=0 ; i--){
            for( int buy =0 ; buy<2 ;buy++ ){
            //starting from cap=1
                for(int cap =1 ; cap <3 ; cap++){
                    if( buy==0 ){
                         dp[i][buy][cap]= max( -prices[i] + dp[i+1][1][cap] ,
                        0 +dp[i+1][0][cap]  );
                    }else{
                         dp[i][buy][cap] = max( prices[i] + dp[i+1][0][cap-1]   , dp[i+1][1][cap]
                        );
                    }
                }
            }
        }
         
        return dp[0][0][2];
        
    }
};
```
### space optmisation
```cpp
class Solution {
public:
 
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
         vector<vector<int>> ahead(  2 , vector<int>(3 , 0));
        
        // all loops start from opposite
        for(int i= n-1 ; i>=0 ; i--){
             vector<vector<int>> curr(  2 , vector<int>(3 , 0));

            for( int buy =0 ; buy<2 ;buy++ ){
                for(int cap =1 ; cap <3 ; cap++){
                    if( buy==0 ){
                         curr[buy][cap]= max( -prices[i] + ahead[1][cap] ,
                        0 + ahead[0][cap]  );
                    }else{
                         curr[buy][cap] = max( prices[i] + ahead[0][cap-1]   , ahead[1][cap]
                        );
                    }
                }
            }
            ahead = curr;
        }
         
        return ahead[0][2];
        
    }
};
```

https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698
```cpp
//very similar to at most 2 transaction in III prblm of dp on stacks
```

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
```
in cooldown can;t buy just after sell. (just next day cant buy)
```

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
