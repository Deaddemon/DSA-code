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

 
 //https://codeforces.com/problemset/problem/1352/C
signed main(){
	FastIO
	 
	 //cout<<fixed<<setprecision(10); 
	 	
    int z;
    cin>>z;
    
    while(z--){
    	
   int n,k;
   cin>>n>>k;
   
   
    if(k <n ){
    	cout<<k<<endl;
    	continue;
    }
    
    int l=0, h =  2*k;
    int res;
    while(l<=h){
    	int mid = l+ (h-l)/2;
    	
    	if((mid - mid/n ) >= k){
    		
    		if(mid%n !=0){
    			res = mid;
    		}
    		h = mid-1;
    	}else{
    		l = mid+1;
    	}
    	
    }
    
    cout<<res;
   
   
   
   
    
   
    	 
   
   cout<<endl;
    	 
    
    
    	
    }
      
 	 
 
  return 0;
	 }
	 
	 
	 
	 
	
 
