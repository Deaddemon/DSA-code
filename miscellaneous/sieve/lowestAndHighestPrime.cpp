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
	 
	 


//output:
    
// 0 0
// 0 0
// 2 2
// 3 3
// 2 2
// 5 5
// 2 3
// 7 7
// 2 2
// 3 3
// 2 5
// 11 11
// 2 3
// 13 13
// 2 7
// 3 5
// 2 2
// 17 17
// 2 3
// 19 19
// 2 5
// 3 7
// 2 11
// 23 23
// 2 3
// 5 5
// 2 13
// 3 3
// 2 7
// 29 29
// 2 5
// 31 31
// 2 2
// 3 11
// 2 17
// 5 7
// 2 3
// 37 37
// 2 19
// 3 13
// 2 5
// 41 41
// 2 7
// 43 43
// 2 11
// 3 5
// 2 23
// 47 47
// 2 3
// 7 7
	 
	 
	
 
