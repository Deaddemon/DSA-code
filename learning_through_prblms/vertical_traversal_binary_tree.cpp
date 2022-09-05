//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int , map<int, multiset<int> > > mp;
        queue< pair< TreeNode* , pair<int , int> > > q;
        
         
        q.push({root , {0,0}});
        
        while(!q.empty()){
            auto temp = q.front();
            int v =temp.second.first, h= temp.second.second;
            mp[v][h].insert(temp.first->val) ;
            q.pop();
            if(temp.first->left){
                q.push({temp.first->left , {v-1 , h+1}});
            }
            
            if(temp.first->right){
                q.push({temp.first->right , {v+1 , h+1}});
            }
            
        }
        
        vector<vector<int>> ans;
        for(auto it: mp){
            vector<int> temp;
            for(auto i : it.second){
                temp.insert(temp.end() , i.second.begin() , i.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};
