 
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
