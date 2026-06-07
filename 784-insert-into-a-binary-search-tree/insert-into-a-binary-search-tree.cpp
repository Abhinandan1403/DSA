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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(!root){
            return new TreeNode(val);
        }

        TreeNode* curr = root ;
        TreeNode* par = NULL ;
        while(curr){
            if(curr->val<val){
                par = curr ;
                curr = curr->right;
            }
            else{
                par = curr ;
                curr = curr->left;
            }
        }
        if(par->val>val){
            par->left = new TreeNode(val);
        }
        else{
            par->right = new TreeNode(val);
        }
        return root;
    }
};