//only two colors assinged 
//they must be alternate position
//no two adjacent nodes should have same color
//odd loop length graphs can never be bipartite graph


//in other language there are two sets formed out of all nodes
//every node of set A is connected to every node of set B
//but nodes of A are not connected to A
//similarly
//




#include <bits/stdc++.h>
using namespace std;
 
  bool isBipartite(int v , vector<int> adj[]){
 vector<int> vis(v);
 fill(vis.begin() , vis.end() , -1);
  
 	
 	for(int i=0 ; i<v ; i++){
 		if(vis[i] == -1){
 			
 			
 			 
 			queue<int>q;
 			vis[i]= 1;
 			q.push(i);
 			
 		 
 			while(!q.empty()){
 				int node = q.front();
 				q.pop();
 				
 				for(auto it: adj[node] ){
 					if(vis[it] == -1){
 						vis[it]= 1 - vis[node];
 						q.push(it); 
 					}else if(vis[it] == vis[node]){ 
 					return false;}
 				}
 			}
 		}
 	}
 	
 	
  
 	return true;
 }
 
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(isBipartite(n,adj)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/

