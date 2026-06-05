/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>mpp;
        if(!node){
            return NULL ;
        }
        mpp[node] = new Node(node->val);
        queue<Node*>q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(auto& it : curr->neighbors){
                if(mpp.find(it) != mpp.end()){
                    mpp[curr]->neighbors.push_back(mpp[it]);
                }
                else{
                    mpp[it] = new Node(it->val);
                    mpp[curr]->neighbors.push_back(mpp[it]);
                    q.push(it);
                }
            }
        }
        return mpp[node];
    }
};