//undirected
//key point : if the node is already visited might be cylce
//BUT :  we need to consider the case that already visited node can also be the previous node
// cycle detected will only be true if next node is already visited 
	
 bool cycleDetect(int node, int parent , vector<int> &vis , vector<int> adj[]){
 	vis[node] = 1;
 	
 	for(auto it: adj[node]){
 		if(!vis[it]){
 			if(cycleDetect(it,node,vis,adj)) return true;
 		}else if(it != parent) return true;  // node visited but not the parent node
 	}
 	return false;
 }
 
 
 bool isCycle(int v , vector<int> adj[]){
 	
 	vector<int> vis(v+1 , 0);
 	
 	for(int i=1 ; i<=v ; i++){
 		
 		if(!vis[i]){
 			if(cycleDetect(i , -1 , vis , adj)){  //here for root node parent node -1 is considered
 				return true;
 			}
 		}
 	}
 	
 	return false;
 }



//directed graph
//maintain a path visited array , which takes care of what path we traveling in present
//a cycle in directed graph is different , draw and know

//if a node is visited again on the same path , then cycle exist

bool dfs(int node , vector<int>&vis , vector<int>&path , vector<int> adj[]){
	
	vis[node] = 1;
	paht[node] = 1;
	
	for(auto it: adj[node]){
		if( !vis[it]){
			dfs(it,vis,path,adj);
		}
		else if(path[it]) return true;
	}
	path[node] = 0;
	return false;
}
