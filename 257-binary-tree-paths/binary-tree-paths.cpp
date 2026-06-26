/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string res = "";
        if(!root)return ans;
        solve(root, ans, res);
        return ans ;
    }

    void solve(TreeNode* root, vector<string>& ans, string& res){
        if(!root)return;

        if(!root->left && !root->right){
            string ch = to_string(root->val);
            res+=ch;
            ans.push_back(res);
            for(int i = 0 ; i<ch.length() ; i++){
                res.pop_back();
            }
            return;
        }

        string c = to_string(root->val);
        int s = c.length();
        res+=c;
        res+="->";
        solve(root->left, ans, res);
        solve(root->right, ans, res);
        for(int i = 0 ; i<s+2 ; i++){
            res.pop_back();
        }
    }
};