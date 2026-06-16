class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n, vector<int>(n, -1));
        for(auto &it : edges){
            int v = it[0], u = it[1], d = it[2] ;
            matrix[u][v] = d ;
            matrix[v][u] = d ;
        }

        for(int k = 0 ; k<n ; k++){
            for(int i = 0 ; i<n ; i++){
                for(int j = 0 ; j<n ; j++){
                    if(matrix[i][k] == -1 || matrix[k][j] == -1)continue ;
                    else if(matrix[i][j] == -1){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                    else{
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        int node = -1 ;
        int mini = INT_MAX ;
        for(int i = 0 ; i<n ; i++){
            int count = 0 ;
            for(int j = 0 ; j<n ; j++){
                if(i == j)continue ;
                else if(matrix[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mini){
                mini = count ;
                node = i ;
            }
        }
        return node ;
    }
};