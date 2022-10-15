//SC : O(n*m);
 //preferred for small testcases
 
 int n,m;
 cin>>n>>m;
 
 //2d matrix to store nodes and its connected nodes
 //one based indexing
 int adj[n+1][m+1];
 
 for(int i=0 ; i<m ; i++){
 	int u,v;
 	
 	cin>>u>>v;
 	
 	
 	//considering undirected graph
 	adj[u][v] = 1;
 	adj[u][v] = 1;
 	
 }
