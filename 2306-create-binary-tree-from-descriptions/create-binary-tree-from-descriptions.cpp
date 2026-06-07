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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mpp;
        unordered_map<TreeNode*, bool>parent;
        for(auto& it : descriptions){
            int nodeVal = it[0];
            int childVal = it[1];
            int isLeft = it[2];

            if(mpp.find(nodeVal) == mpp.end()){
                TreeNode* node = new TreeNode(nodeVal);
                mpp[nodeVal] = node ;
            }
            if(mpp.find(childVal) == mpp.end()){
                TreeNode* childNode = new TreeNode(childVal);
                mpp[childVal] = childNode ;
            }
            if(isLeft == 1){
                mpp[nodeVal]->left=mpp[childVal];
            }
            else{
                mpp[nodeVal]->right=mpp[childVal];
            }

            if(parent[mpp[nodeVal]] != true){
                parent[mpp[nodeVal]] = false ;
            }
            parent[mpp[childVal]] = true;
        }
        
        for(auto& it : parent){
            if(it.second == false){
                return it.first;
            }
        }

        return NULL ;

    }
};