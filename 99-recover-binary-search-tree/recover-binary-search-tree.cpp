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
    void recoverTree(TreeNode* root) {
        vector<int>v;
        dfs1(root, v);
        sort(v.begin(), v.end());
        int idx = 0 ;
        dfs2(root, idx, v);
    }

    void dfs1(TreeNode* root, vector<int>&v){
        if(!root)return ;
        dfs1(root->left, v);
        v.push_back(root->val);
        dfs1(root->right, v);
    }

    void dfs2(TreeNode* root, int& idx, vector<int>&v){
        if(!root)return ;
        dfs2(root->left, idx, v);
        root->val = v[idx];
        idx++;
        dfs2(root->right, idx, v);
    }
};