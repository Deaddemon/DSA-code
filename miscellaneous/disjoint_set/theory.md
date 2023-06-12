https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46

```
Time complexity:

For regular union and find, each operation takes O(logn) in average, and O(n) in worst case.
For union by rank, it takes at most O(logn) time since the height of tree-like structure is restricted in O(logn).
For path compression, the time complexity is reduced to O(1) in average and worst case, since the structure is flattened.
So the total time complexity can be reduced from O(n^2)(worst case), O(nlogn)(average case) to O(n) in both cases.

Is this a correct analysis?
```


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
