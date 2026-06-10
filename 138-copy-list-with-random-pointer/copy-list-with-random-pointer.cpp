/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* node = head ;
        Node* ok = new Node(-1);
        Node* dummy = ok ; 
        unordered_map<Node*, Node*>mpp ; //real, copy

        while(node){
            Node* copy = new Node(node->val);
            mpp[node] = copy ;
            dummy -> next = copy ;
            dummy = dummy ->next ;
            node = node->next ;
        }

        node = head ;
        dummy = ok ;
        while(node){
            Node* curr = mpp[node] ;
            Node* rando = node->random ;
            Node* nn = mpp[rando] ;
            curr->random = nn ;
            node = node->next ;
        }

        return ok->next ;

    }
};