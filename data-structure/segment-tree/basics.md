resources: <br>
----------
 https://www.youtube.com/watch?v=Ic7OO3Uw6J0&t=80s <br>
 https://www.youtube.com/watch?v=2bSS8rtFym4&t=0s  <br>
 https://www.youtube.com/watch?v=DpSYj7t1sbQ <br>
 https://gist.github.com/SuryaPratapK/56f99cdb6a851573df64401651d0f9f3 <br>
 


 sample<br>
--------------------------------
TC:<br>
Accessing Elements- O(1)<br>
Insertion or removal of elements- O(N)<br>
Insertion or removal of elements at start or end- O(1)<br>
<br>

https://cses.fi/problemset/task/1647/<br>
```c++
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
//const int N = 1e7 + 10;
 
 int mx = INT_MAX;
int getMinUtil(vector<int>&st , int si, int sl , int sr , int l , int r){
	//overlapping structure comes handy
	
	//case1-total overlap
	if(l<= sl && r>= sr) return st[si];
	
	//no overlap
	if(l>sr || r<sl) return mx;
	
	//partial overlap
	int mid = sl+ (sr-sl)/2;
	
	return min(getMinUtil(st, 2*si+1 , sl , mid , l, r),
	getMinUtil(st , 2*si+2 , mid+1, sr , l ,r));
	
	
}


int getMin(vector<int> &st , int n , int l , int r){
	if(l<0 || r> n-1 || l>r){
		return -1;
	}
	//st vector , si index , sl , sr , l, r
	return getMinUtil(st, 0, 0, n-1 , l, r);
}
int constructSTUtil(vector<int> &st , int si , vector<int> &v , int l , int r){
	if(l== r){
		st[si] = v[l];
		return v[l];
	}
	int mid = l+ (r-l)/2;
	st[si] = min(constructSTUtil(st,2*si+1,v,l,mid),constructSTUtil(st,2*si+2,v,mid+1 , r));
	
	return st[si];
}
int getMaxSizeST(int n){
	int h= (int)(ceil(log2(n)));
	int nodesNumber = 2* (int)pow(2,h) -1; 
	return nodesNumber;
}
vector<int> constructST(vector<int> &v ){
	int n = v.size();
	int maxSize = getMaxSizeST(n);
	vector<int> st(maxSize,0);
	//parameters- st vector , si index of curr node, v vector , 0 is l starting  , n-1 is r ending
	constructSTUtil(st , 0, v , 0, n-1);
	return st;
	
} 


 void printSegmentTree(vector<int> st, int max_size)
{
	for (int i = 0; i < max_size; i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;
}
signed main(){
	FastIO
	 
	 //cout<<fixed<<setprecision(15); 
	 	
	int n,q;
	cin>>n>>q;
	
	vector<int> v(n);
	loop(i,n){
		cin>>v[i];
	}
	
	vector<int> st = constructST(v);
    printSegmentTree(st, getMaxSizeST(n) );
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<getMin(st , n, l-1 , r-1)<<endl;
	}
   
 	 	 
  
 
  return 0;
	 }
	 
 
 
````
 
