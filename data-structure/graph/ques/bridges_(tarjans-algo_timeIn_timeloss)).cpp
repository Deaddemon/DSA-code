//https://leetcode.com/problems/critical-connections-in-a-network/description/
class Solution {
public:
    int counter =1;
    
    void dfs(int node , int parent , vector<int>&vis , int tin[] , int low[] , vector<int> adj[] , 
     vector<vector<int>>& bridge){

        vis[node] = 1;
        tin[node] = low[node] = counter;
        counter++;

        //go to adjacent nodes
        for(auto it: adj[node]){

            if(it == parent) continue;

             
             

            if(vis[it]==0){

                dfs(it , node ,vis, tin , low , adj, bridge);

                //compare with every adj node of the current node
                //low[node] = min( low[node] , low[it]);

                // path access of "it"  is low[it]
                if(low[it] > tin[node]){
                    //means the edge is a bridge
                    
                    bridge.push_back({it, node});
                }

            }

            //gave wrong ans when i added this line before if statement
            //compare with every adj node of the current node
            low[node] = min( low[node] , low[it]);

            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        //create a graph
        //connections only include edges

        vector<int> adj[n];
        for(auto i: connections){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //based on bridges , have to return bridges 
        // tarjans algo , with time-in => tin and time-low => low

        vector<int> vis(n , 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridge;

        dfs(0 , -1 , vis , tin , low , adj , bridge);

        return bridge;
        
    }
};
