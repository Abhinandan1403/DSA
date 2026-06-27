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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>dirc = {0, 1, 0, -1, 0};
        disjoint ds(n*n);
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ;j++){
                if(grid[i][j]){
                    for(int k = 0 ; k<4 ; k++){
                        int newi = i + dirc[k], newj = j+dirc[k+1];
                        if(newi<n && newj<n && newi>=0 && newj>=0 && grid[newi][newj]==1){
                            ds.unionBySize(newi*n+newj, i*n+j);
                        }
                    }
                }
            }
        }

        int maxi = 1 ;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n; j++){
                unordered_set<int>st;
                if(!grid[i][j]){
                    for(int k = 0 ; k<4 ; k++){
                        int ans = 0 ;
                        int newi = i + dirc[k], newj = j+dirc[k+1];
                        if(newi<n && newj<n && newi>=0 && newj>=0 && grid[newi][newj]==1){
                            st.insert(ds.findUPar(newi*n+newj));
                        }
                        for(auto& it: st){
                            ans+=ds.size[it];
                        }
                        maxi = max(maxi, ans+1);
                    }
                }
            }
        }

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(ds.parent[i*n+j]==i*n+j){
                    maxi = max(maxi, ds.size[i*n+j]);
                }
            }
        }

        return maxi;
    }
};