class Solution {
public:
    vector<int>dirc={0, 1, 0, -1, 0};
    bool exist(vector<vector<char>>& board, string& word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>>vis(m, vector<int>(n, 0));
                    if(dfs(0, i, j, board, word, vis))return true;
                }
            }
        }
        return false;
    }

    bool dfs(int idx, int i, int j, vector<vector<char>>& board, string& word, vector<vector<int>>& vis){
        if(idx == word.size()-1 && word[idx]==board[i][j])return true;
        if(board[i][j]!=word[idx])return false;
        vis[i][j]=1;

        for(int x = 0 ; x<4 ; x++){
            int newi = i+dirc[x], newj = j+dirc[x+1];
            if(newi>=0 && newj>=0 && newi<board.size() && newj<board[0].size() && !vis[newi][newj]){
                if(dfs(idx+1, newi, newj, board, word, vis))return true;
            }
        }
        vis[i][j]=0;

        return false;
    }
};