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
 
 
 
signed main(){
	FastIO
	 
	 //cout<<fixed<<setprecision(10); 
	 
	 
	 isPrime[0] = isPrime[1] = false;
	 for(int i=2 ; i<50 ; i++){
	 	if(isPrime[i] == true){
	 		//multiples of the prime number found
	 		//are marked as false
	 		//bcz they cannot be prime
	 		for(int j= 2*i ; j< 50 ; j+=i){
	 			isPrime[j] = false;
	 		}
	 	}
	 }
	 
	 
	 for(int i =0 ; i<50 ; i++){
	 	if(isPrime[i] == true){
	 		cout<<i<<endl;
	 	}
	 	
	 	//cout<<isPrime[i]<<endl;
	 }
	 
	 
	  
     
      
   cout<<endl;
    	 
    
    
    	
  
 	 
 
  return 0;
	 }
	 
	 
	 
	 
	
 
