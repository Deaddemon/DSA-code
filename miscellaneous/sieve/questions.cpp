//=====index:   11:find lowest and highest prime factorisation of a nums in the vec
//=====index:   91:prime factorisation
//=====index:   171:divisors or the sum of divisors
//=====index:    






//find lowest and highest prime factorisation of a nums in the vec
//-------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
// #define all(x) (x).begin(),(x).end()
 #define loop(i,n) for(int i=0; i<n ;i++)
  
// typedef pair<int,int> ppi;
// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;

 
 
 vector<bool> isPrime(50,true);
 
 vector<int> lprime(50,false) , hprime(50,false);
 
 
 
signed main(){
	FastIO
	 
	 //cout<<fixed<<setprecision(10); 
	 
	 
	 isPrime[0] = isPrime[1] = false;
	 for(int i=2 ; i<50 ; i++){
	 	if(isPrime[i] == true){
	 		
	 		lprime[i] = hprime[i] = i;
	 		 
	 		for(int j= 2*i ; j< 50 ; j+=i){
	 			isPrime[j] = false;
	 			hprime[j] = i;
	 			if(lprime[j] == 0){
	 				lprime[j] = i;
	 			}
	 		}
	 	}
	 }
	 
	 
	 for(int i =0 ; i<50 ; i++){
	 	 
	 	 cout<<lprime[i]<<" "<<hprime[i]<<endl;
	 }
	 
	 
	  
     
      
   cout<<endl;
    	 
    
    
    	
  
 	 
 
  return 0;
	 }
	 
	 

 
 
 
 
 
 
 
	 
	
	

//prime factorisation
//---------------------------------------------------------


//hint: either lowest prime or the highest prime
#include <bits/stdc++.h>
using namespace std;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
// #define all(x) (x).begin(),(x).end()
 #define loop(i,n) for(int i=0; i<n ;i++)
  
// typedef pair<int,int> ppi;
// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;

 
 
 vector<bool> isPrime(50,true);
 
 vector<int> lprime(50,false) , hprime(50,false);
 
 
 
signed main(){
	FastIO
	 
	 //cout<<fixed<<setprecision(10); 
	 
	 
	 isPrime[0] = isPrime[1] = false;
	 for(int i=2 ; i<50 ; i++){
	 	if(isPrime[i] == true){
	 		
	 		lprime[i] = hprime[i] = i;
	 		 
	 		for(int j= 2*i ; j< 50 ; j+=i){
	 			isPrime[j] = false;
	 			hprime[j] = i;
	 			if(lprime[j] == 0){
	 				lprime[j] = i;
	 			}
	 		}
	 	}
	 }
 
	 int num = 30;
	 vector<int> ans;
	 
	 while(num> 1){
	 	int prime_factor = hprime[num];
	 	while(num%prime_factor == 0){
	 		num/= prime_factor;
	 		ans.push_back(prime_factor);
	 	}
	 }
	 
	 for(auto ans : ans){
	 	cout<<ans<<endl;
	 }
	 
	 //if u want to find power of prime factors
	 //just use a map instead of ans;
	 
 
   cout<<endl; 
  return 0;
	 }
	 
	 
	 
	 







//divisors or the sum of divisors
//---------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
// #define all(x) (x).begin(),(x).end()
 #define loop(i,n) for(int i=0; i<n ;i++)
  
// typedef pair<int,int> ppi;
// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;

 
 
signed main(){
	FastIO
	 
	 //cout<<fixed<<setprecision(10); 
	 
	 vector<int> divisors[50];
	 int sum[50];
	  
	 for(int i=2 ; i<50 ; i++){ 
	              
		      for(int j= i ; j< 50 ; j+=i){
	 			
	 			divisors[j].push_back(i);
	 			sum[j] += i;
	 			
	 			 
	 		}
	 	}
	 }
	 
	 
	 
	 //here divisors[i] will store all the 
	 //divisor of i;
	 
	 //sum array stores the sum
	 //sum[i] stores sum of divisors of i
 
     
      
   cout<<endl; 
  return 0;
	 }
	 
	 
	 
	 
	
 
	 
	 
	 
	
 
	
 
