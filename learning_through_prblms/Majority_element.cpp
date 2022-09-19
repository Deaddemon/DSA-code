//Boyer-Moore Majority Voting Algorithm
//optimal alogorithm to find majority element 
//in time complexity: O(n)
//in space complexity : O(1)

//main idea is to maintain two variables 
//for similar numbers in a row we keep on counting number of occurences
//decrement the counter once a different number appears



//ques:  https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size() ;
        
        int elem=-1 , cnt=0;
        
        for(int i=0 ; i<n ; i++){
            if(cnt ==0) {
                elem= nums[i];
                cnt=1;
            }
            
            else{
                if(elem == nums[i]){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
        
        
        if(cnt>=0) return elem;
        return -1;
        
    }
};
