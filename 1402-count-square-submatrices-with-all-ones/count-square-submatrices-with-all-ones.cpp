class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int cnt = 0 ;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                int up = 0, d = 0, left = 0;
                if(i>0){
                    up = matrix[i-1][j];
                }
                if(j>0){
                    left = matrix[i][j-1];
                }
                if(i>0 && j>0){
                    d = matrix[i-1][j-1];
                }
                if(matrix[i][j]){
                    cnt += min({left, up, d})+1;
                    matrix[i][j] = min({left, up, d})+1;
                }
            }
        }
        return cnt;
    }
};