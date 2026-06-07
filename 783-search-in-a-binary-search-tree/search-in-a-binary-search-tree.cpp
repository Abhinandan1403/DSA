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
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root, val);
    }

    TreeNode* solve(TreeNode* root, int val){
        if(!root){
            return NULL ;
        }
        if(root->val == val){
            return root ;
        }

        if(val > root->val){
            return solve(root->right, val);
        }
        else{
            return solve(root->left, val);
        }

        return NULL ;
    }
};