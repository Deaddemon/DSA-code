//initalize vis with -1
//make changes to this vis  only


//memset is used to initialise only for arrays
// fill is used for vectors


bool dfsBipartite(int node , vector<int> adj[] ,  vector<int> &vis){
 	
 	vis[node]=1;
 	
 	for(auto it: adj[node]){
 		if(vis[it]== -1){
 			vis[it] = 1-vis[node];
 			if(!dfsBipartite(it, adj, vis)){
 				return false;
 			}
 		}else if(vis[it] == vis[node]){
 			return false;
 		}
 	}
 	
 	return true;
 	
 }
 
 bool isBipartite(int v , vector<int> adj[]){
 	
 	vector<int> vis(v);
 	fill(vis.begin() , vis.end() , -1);
 	
 	for(int i=0 ; i<v;  i++){
 		if(vis[i] ==  -1){
 			if(dfsBipartite(i , adj , vis)){
 				return true;
 			}
 		}
 	}
 	
 	
 	return false;
 	
 }
 
