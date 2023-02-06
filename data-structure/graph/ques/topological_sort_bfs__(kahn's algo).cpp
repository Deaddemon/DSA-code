//ques :  https://practice.geeksforgeeks.org/problems/topological-sort/1

vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    //kahns algo
	    
	    vector<int> indegree(v);
	    queue<int> q;
	    vector<int>res;
	    for(int i=0 ; i<v ; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0  ; i<v ; i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        
	        int temp =  q.front();
	        q.pop();
	        res.push_back(temp);
	        for(auto it: adj[temp]){
	            indegree[it]--;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return res;
	}
