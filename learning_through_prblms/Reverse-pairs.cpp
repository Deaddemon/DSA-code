// based on divide conquer 
// the subproblems dont have any relation like that of 
// in dynamic programming we have relation between subproblems
// 
//you can do this using temporary array or taking two different arrays for left and right subarray
//  
// Time complexity: nlogn
// (of all cases)
// number of steps are logn because at every stage it is n/2 partition
 

// similar ques:
// 
// https://leetcode.com/problems/reverse-pairs/
// https://www.geeksforgeeks.org/counting-inversions/
// 
// reference videos:
// merge sort
// https://www.youtube.com/watch?v=aDX3MFL0tYs
// counting-inversion
// https://www.youtube.com/watch?v=kQ1mJlwW-c0&t=0s
// reverse-pair
// https://www.youtube.com/watch?v=S6rsAlj_iB4
// 



#include <bits/stdc++.h>
using namespace std;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
 
  
int merge(vector<int>& v , int low , int mid , int high){
	
	// for the respective question
	int ans =0;

	int j= mid+1;
	
	for(int i=low ; i<mid+1 ; i++){
		while(j<=high && v[i] > 2*v[j]){
			j++;
		}
		ans += j- (mid+1);
	}
	
	//for merge sort
	vector<int> temp;
	int l= low , r = mid+1;
	while(l<mid+1 && r<=high){
		if(v[l] <= v[r]){
			temp.push_back(v[l]);
		    l++;
		}else{
			temp.push_back(v[r]);
			r++;
		}
	}
	
	while(l<mid+1){
		temp.push_back(v[l]);
		    l++;
	}
	while(r<=high){
		temp.push_back(v[r]);
			r++;
	}
	
	
	for(int i=  low ; i<=high ; i++){
		v[i] = temp[i-low];
	}
	
	return ans;
	
	
	
	
}
int mergesort(vector<int>&v, int low , int high){
	if(low> high) return 0;
	int mid = high+ ( high - low )/2;
	int ans=0;
	ans += mergesort(v , low , mid);
	ans += mergesort(v, mid+1 , high);
	ans += merge(v , low , mid , high);
	return ans;
}
 
signed main(){
	FastIO
	
	vector<int> v =  {1,3,2,3,1};
	
	cout<<mergesort(v , 0 , v.size()-1 );
	 
 
 
  return 0;
	 }
