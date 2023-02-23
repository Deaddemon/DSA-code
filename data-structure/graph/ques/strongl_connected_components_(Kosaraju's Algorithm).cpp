
class Solution
{
    private:
    void dfs(int node , stack<int>&st , vector<int>&vis , vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it , st , vis,  adj);
            }
        }
        st.push(node);
    }
    void dfs_scc(int node  , vector<int>&vis ,  vector<int> rev[]){
        vis[node] = 1;
        for(auto it : rev[node]){
            if(!vis[it]){
                dfs_scc(it, vis , rev);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        //code here
        
        //sort based on fetching time
        
        //vis array for dfs
        vector<int> vis(v , 0);
        //stack for storing that sorted nodes based on fetching time
        stack<int> st;
        
        for(int i=0 ; i<v ; i++){
            if( !vis[i]){
                dfs(i , st , vis , adj);
            }
        }
        
        //reversing the edges
        vector<int> rev[v];
        for(int i=0 ; i<v ; i++){
            //to use vis in step 3
            //mark it as unvisited
            vis[i] = 0;
            for(auto it:  adj[i]){
                rev[it].push_back(i);
            }
        }
        
        //performing dfs on each node to find out strongly connected component
        // we will take the stack from above to traverse
        
        int scc =0 ;
        while(!st.empty()){
            
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs_scc(node , vis , rev);
            }
        }
        return scc;
        
    }
};
 
