//monotonic queue 
//A monotonic Queue is a data structure the elements from the front to the end is strictly either increasing or decreasing.

//resources:
//https://abitofcs.blogspot.com/2014/11/data-structure-sliding-window-minimum.html
//https://www.youtube.com/watch?v=CZQGRp93K4k

//ques: https://leetcode.com/problems/sliding-window-maximum/
//more ques: https://leetcode.com/problems/max-value-of-equation/






class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        vector<int> ans;
        
        for(int i=0 ; i<nums.size() ; i++){
            
            
            if(!q.empty() && q.front() == i-k){
                q.pop_front();
            }
            
            while(!q.empty() && nums[q.back()]  < nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
            
            if(i>=k-1){
                ans.push_back(nums[q.front()]);
            }
    
        }
        
        return ans;
        
    }
};
