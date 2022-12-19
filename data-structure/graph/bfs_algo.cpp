//TC : O(n+e)
//SC : O(n+e)+O(n)+O(n)


//we use queue
//maintain a visited vector


vector<int> bfs(int v, vector<int> adj[]){
	vector<int> ans;
	
	vector<int> vis(v+1 , 0);
	
	for(int i=1 ; i<=v ; i++){ //this loop is basically for multiple component graph
		if(!vis[i]){
			
			queue<int> q;  
			q.push(i);
			vis[i]=1;
			
			while(!q.empty()){
				
				int node =  q.front(); //first in first out
				q.pop();
				ans.push_back(node);
				
				for(auto it: adj[node]){ //finding the adjacent nodes of "node"
					
					if(!vis[i]){
              q.push(it);
              vis[it] = 1;
					}
          
				}
			}
		}
	}
	
	return ans;

}	 
	 
	 
