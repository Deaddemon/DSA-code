//prblm link:     https://leetcode.com/problems/max-area-of-island/
//sol       :     https://leetcode.com/submissions/detail/748212697/

//other resources:
//https://www.geeksforgeeks.org/comparison-between-adjacency-list-and-adjacency-matrix-representation-of-graph/
//https://www.youtube.com/watch?v=TOwcZYkJ2ys

//this prblm can be seen as finding longest path

//Applications of DFS algorithm -
// can be used to implement the topological sorting.
//It can be used to find the paths between two vertices.
//It can also be used to detect cycles in the graph.
//is also used for one solution puzzles.
//used to determine if a graph is bipartite or not.

//Difference bw dfs bfs
//dfs uses stack ,bfs used stack
//dfs builds the tree sub-tree by sub-tree, bfs builds the tree level by level
//dfs uses backtracking
//for both: 
//time complexity:: adjacency list: O(v+u) :: adjacency matrix: O(v^2)

 


#include <bits/stdc++.h>
using namespace std;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 #define int long long
 
 
class graph{
	int n;
	vector<vector<int>> m_adj;
	
	void dfs_rec(int s , vector<bool>& visited){
		visited[s]=true;
		cout<<s<<" ";
		for(int u : m_adj[s]){
			if(!visited[u]){
				dfs_rec(u,visited);
			}
		}
	}
	void dfs_it(int s  , vector<bool>& visited){
		stack<int>S;
		S.push(s);
		visited[s]=true;
		
		while(!S.empty()){
			int u = S.top();
			S.pop();
			cout<<u<<" ";
			for(int v : m_adj[u])
				if(!visited[v]){
					S.push(v);
					visited[v]=true;
					
				}
			}
		}
		
	
	
	
	public:
	 graph(int n): n(n) ,m_adj(n){}
	 
	 void addEdge(int u, int v){
	 	m_adj[u].push_back(v);
	 }
	 
	 void dfs_call_rec(){
	 	vector<bool> visited(n, false);
	 	for(int i=0 ;i<n ; i++){
	 		if(!visited[i]){
	 			dfs_rec(i,visited);
	 		}
	 	}
	 }
	 
	 void dfs_call_it(){
	 	vector<bool> visited(n, false);
	 	for(int i=0 ;i<n ; i++){
	 		if(!visited[i]){
	 			dfs_it(i,visited);
	 		}
	 	}
	 }
}; 
signed main(){
	FastIO
	 
	// cout<<fixed<<setprecision(10);  
	graph G(5);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(3,2);
    G.addEdge(3,4);
    cout<<"recursive : ";
    G.dfs_call_rec();
    cout<<endl;
     cout<<"iterative : ";
    G.dfs_call_it();
 	 
 	 
 	 
  
   
 
  return 0;
	 }
	 
	 
	 
	 
	
 
