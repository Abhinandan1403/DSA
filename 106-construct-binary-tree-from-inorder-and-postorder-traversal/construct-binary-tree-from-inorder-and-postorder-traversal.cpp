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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        unordered_map<int, int>mpp;
        for(int i = 0 ; i<inorder.size() ; i++){
            mpp[inorder[i]]=i;
        }
        int idx = 0;
        return solve(postorder, idx, 0, inorder.size()-1, mpp); //pre, idx, left, right, mpp
    }

    TreeNode* solve(vector<int>& postorder, int& idx, int l, int r, unordered_map<int, int>& mpp){
        if(l>r)return NULL;

        int val = postorder[idx];
        int curr = mpp[val];
        TreeNode* root = new TreeNode(0) ;
        if(curr>=l && curr<=r){
            root->val = postorder[idx];
            idx++;
        }

        root->right = solve(postorder, idx, curr+1, r, mpp);
        root->left = solve(postorder, idx, l, curr-1, mpp);



        return root;
    }
};