https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46




```cpp
class DisjointSet{
    public:
    vector<int> parent, rank , size;
    
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1 , 0);
        size.resize(n+1, 1);
        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
        }
    }
    
    int findPar(int node){
        if(node == parent[node]) return node;
        else return parent[node] = findPar(parent[node]);
    }
    
    void unionByRank(int u , int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if( rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else if( rank[pv] < rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    void unionBySize(int u , int v){

        int pu = parent[u];
        int pv =  parent[v];

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu]  = pv;
            size[pv] += size[pu];

        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }

    }
};
```
