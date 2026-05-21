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
    bool isBalanced(TreeNode* root) {
        int h = findh(root);

        return h != -1 ? true : false ;
    }

    int findh(TreeNode* root){
        if(root == NULL)return 0 ;

        int lh = findh(root->left);
        int rh = findh(root->right);

        if(lh == -1 || rh == -1)return -1;

        if(abs(lh-rh)>1)return -1 ;

        return 1+max(lh, rh);
    }
};