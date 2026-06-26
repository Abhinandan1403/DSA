/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root)return ans;
        unordered_map<TreeNode*, TreeNode*>mpp;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            for(int i = 0 ; i<s ; i++){
                auto node = q.front();
                q.pop();

                if(node->left){
                    mpp[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    mpp[node->right]=node;
                    q.push(node->right);
                }
            }
        }

        unordered_set<TreeNode*>st ;
        queue<pair<TreeNode*, int>>qq;
        qq.push({target, 0});
        st.insert(target);
        while(!qq.empty()){
            auto n = qq.front();
            if(n.second == k)break;

            qq.pop();
            int dist = n.second;
            TreeNode* node = n.first;
            if(mpp.find(node) != mpp.end() && st.find(mpp[node]) == st.end()){
                TreeNode* val = mpp[node];
                st.insert(val);
                qq.push({val, dist+1});
            }
            if(node->left && st.find(node->left) == st.end()){
                TreeNode* val = node->left;
                st.insert(val);
                qq.push({val, dist+1});
            }
            if(node->right && st.find(node->right) == st.end()){
                TreeNode* val = node->right;
                st.insert(val);
                qq.push({val, dist+1});
            }
        }

        while(!qq.empty()){
            auto it = qq.front();
            qq.pop();
            ans.push_back(it.first->val);
        }
        return ans;
    }
};