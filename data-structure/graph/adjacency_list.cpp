
 //SC : O(n+2*e);
 //preferred for large testcases
 
 //understandin adjacency list
 //int arr[]  is array of integers
 //similarly
 //vector<int> arr[] is array of vector as element
 //similarly
 //pair<int,int> arr[] is array of pairs
 
 
 //for weighted graph consider pair of vectors
 
 
 
 int n,m;
 cin>>n>>m;
 
 vector<int> adj[n+1];
 
 for(int i=0 ; i<m ; i++){
 	int u,v;
 	cin>>u>>v;
 	
 	
 	//considering undirected graph
 	adj[u].push_back(v);
 	adj[v].push_back(u);
 	
 }



//generic code to convert adj matrix to adj list
        //given 
        // vector<vector<int>> adj
        //int v
        vector<int> adjL[v];
        for(int i=0 ; i<v ; i++){
            for(int j =0 ; j<v ; j++){
                if(adjM[i][j] == 1&& i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
