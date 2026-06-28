class disjoint{
    public:
    vector<int>parent;
    vector<int>size;
    disjoint(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0 ; i<n ; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int u){
        if(parent[u] == u)return u;
        return parent[u]=findUPar(parent[u]);
    }

    void unionBySize(int u, int v){
        int up_u=findUPar(u);
        int up_v=findUPar(v);

        if(up_u == up_v)return;

        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int>mpp;
        int n = accounts.size();
        disjoint ds(n);
        for(int i = 0 ; i<n ; i++){
            for(int j = 1 ; j<accounts[i].size() ; j++){
                if(mpp.find(accounts[i][j]) != mpp.end()){
                    ds.unionBySize(i, mpp[accounts[i][j]]);
                }
                else{
                    mpp[accounts[i][j]]=i;
                }
            }
        }
        vector<vector<string>>v(n);
        for(auto& it: mpp){
            string mail = it.first;
            int par = ds.findUPar(it.second);
            v[par].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i = 0;i<n ; i++){
            if(v[i].size()==0)continue;
            vector<string>smallAns;
            smallAns.push_back(accounts[i][0]);
            sort(v[i].begin(), v[i].end());
            for(auto& it:v[i]){
                smallAns.push_back(it);
            }
            ans.push_back(smallAns);
        }
        return ans;
    }
};