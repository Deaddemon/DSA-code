//sources :
// https://leetcode.com/problems/top-k-frequent-words/discuss/1274279/CPP-or-C%2B%2B-or-priority-queue-or-Custom-Comparator-and-Solution-Explain-oror-O(nLogk)-Solution
// https://www.youtube.com/watch?v=3pvZhwp0U9w

//ques:  https://leetcode.com/problems/top-k-frequent-words/

#define psi pair<int,string>


struct myComp{
    public:
    bool operator()(const psi &p1 , const psi &p2 ){
        if(p1.first == p2.first){
            return p1.second <p2.second ;
        }
        return p1.first > p2.first;
    }
};


class Solution {
public:
     
    
    vector<string> topKFrequent(vector<string>& w, int k) {
        int n= w.size();
        
        map<string,int> mp;
        
        
        for(int i=0 ; i<n ; i++){
            mp[w[i]]++;
        }
        
        
        
        priority_queue <psi , vector<psi> , myComp> pq;
        
        for(auto it : mp){
            pq.push({it.second , it.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        // while(pq.size() >0){
        //     cout<<pq.top().first << pq.top().second<<" ";
        //     pq.pop();
        // }
        
        //1leetcode 1coding 2love 2i 
        
        vector<string> ans(k);
        int m = k-1;
        
        while(pq.size() >0){
            ans[m--] = pq.top().second;
            pq.pop();
        }
        
        
        
        
       return ans;
 
                
        
        
        
    }
};
