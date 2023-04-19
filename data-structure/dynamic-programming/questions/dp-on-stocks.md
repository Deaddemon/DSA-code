https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405
<br>
https://www.codingninjas.com/codestudio/problems/selling-stock_630282
<br>
https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012
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

https://www.codingninjas.com/codestudio/problems/selling-stock_630282
```cpp
//we have to know if we bought previously or not
//acc to that we will be  selling/buying 
// storing min like we did in prev ques wont work , coz here we have to 
// explore all paths
//selling must before buying
```

https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012
```cpp
//general intutive is of 3d dp (not so visually appealing)
// try doing it with dp[n+][4]
// some also do it with 4 variables
```
https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698
```cpp
//very similar to at most 2 transaction in III prblm of dp on stacks
```

