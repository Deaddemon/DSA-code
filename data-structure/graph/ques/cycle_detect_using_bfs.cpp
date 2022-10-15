
 
 //cylce detection using bfs
 //no recursion  <----remember
 
 
 bool cycleDetect(int node , vector<int> &vis , vector<int> adj[]){
 	vis[node]=1;
 	
 	queue<pair<int,int>> q;
 	q.push({node,-1});
 	
 	while(!q.empty()){
 		int f= q.front().first;
 		int s= q.front().second; //the previous node or the parent node
 		
 		for(auto it: adj[node]){
 			
 			if(!vis[i]){
 				vis[i]=1;
 				q.push({i,node});
 				
 			}else if(s!=it) return true;
 		}
 	}
 	
 	
 	return false;
 }
 
 
 bool isCycle(int v ,vector<int> adj[]){
 	vector<int> vis(v+1 , 0);
 	
 	for(int i=1 ; i<=v ; i++){
 		if(!vis[i]){
 			if(cycleDetect(i,vis,adj)) return true;
 		}
 	}
 	
 	return false;
 }
 
 
