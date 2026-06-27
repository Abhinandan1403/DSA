class disjoint{
    public:
    vector<int>size;
    vector<int>parent;
    
    disjoint(int V){
        size.resize(V+1);
        parent.resize(V+1);
        
        for(int i = 0 ; i<V+1 ; i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    
    int findUPar(int u){
        if(parent[u] == u)return u;
        
        return parent[u] = findUPar(parent[u]);
    }
    
    void unionBySize(int u, int v){
        int ul_par_v = findUPar(v);
        int ul_par_u = findUPar(u);
        
        if(ul_par_v == ul_par_u){
            return;
        }
        
        if(size[ul_par_u]<size[ul_par_v]){
            parent[ul_par_u]=ul_par_v;
            size[ul_par_v]+=size[ul_par_u];
        }
        else{
            parent[ul_par_v]=ul_par_u;
            size[ul_par_u]+=size[ul_par_v];
        }
        return;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        disjoint ds(n);
        for(auto& it:connections){
            ds.unionBySize(it[0], it[1]);
        }
        int cnt = 0 ;
        for(int i = 0 ; i<n; i++){
            if(ds.parent[i]==i)cnt++;
        }
        return cnt-1;
    }
};