	 
//TC: O(n+e)
//SC: O(n+e)+O(n)+O(n)
//dfs is a recursive alogorithm


void dfs(int node, vector<int> adj[] , vector<int> &vis , vector<int> &ans ){
	ans.push_back(node);
	vis[node]=1;
	
	for(auto it : adj[node]){
		if(!vis[it]){
			dfs(it , adj, vis , ans);
		}
		
	}
}

vector<int> dfs_vec(int v , vector<int>adj[]){
	vector<int> ans;
	vector<int> vis(v+1,0);
	
	for(int i=1 ; i<=v ; i++){
		if(!vis[i]){
			dfs(i, adj , vis , ans); //perform dfs at every node that is not yet visited
		}
	}
	
	return ans;
}
	
 
