#include <bits/stdc++.h>

using namespace std;


  vector <int> nearlySorted(int arr[], int num, int k){
      
        priority_queue<int ,  vector<int> , greater<int> > pq;
        
        vector<int> v;
        
        for(int i=0 ;i <k+1 ;i++){
            pq.push(arr[i]);
             
        }
        
        for(int i=k+1 ; i<num ;i++){
             v.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
             
        }
        
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        
        return v;
        
        
    }
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    
    vector<int> ans;
    ans =  nearlySorted(arr, n,k );
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}
