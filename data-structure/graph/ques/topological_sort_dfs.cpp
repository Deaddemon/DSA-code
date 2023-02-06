 //ques: https://practice.geeksforgeeks.org/problems/topological-sort/1
 
	void dfs(int node , vector<int> &vis , stack<int>&st, vector<int>adj[] ){
	    vis[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it , vis , st , adj);
	            
	        }
	    }
	    
	    st.push(node);
	    
	}
	
 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(v,0);
	    vector<int> res;
	    stack<int> st;
	    
	    for(int i=0 ; i<v ; i++){
	        if(!vis[i]){
	            dfs(i , vis , st , adj);
	        }
	    }
	    
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
 
    
         
