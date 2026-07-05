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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mpp;
        for(int i = 0 ; i<inorder.size() ; i++){
            mpp[inorder[i]]=i;
        }
        int idx = 0;
        return solve(preorder, idx, 0, inorder.size()-1, mpp); //pre, idx, left, right, mpp
    }

    TreeNode* solve(vector<int>& preorder, int& idx, int l, int r, unordered_map<int, int>& mpp){
        if(l>r)return NULL;

        int val = preorder[idx];
        int curr = mpp[val];
        TreeNode* root = new TreeNode(0) ;
        if(curr>=l && curr<=r){
            root->val = preorder[idx];
            idx++;
        }

        root->left = solve(preorder, idx, l, curr-1, mpp);
        root->right = solve(preorder, idx, curr+1, r, mpp);



        return root;
    }
};