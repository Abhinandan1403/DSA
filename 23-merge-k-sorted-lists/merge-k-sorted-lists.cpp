/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    typedef pair<int, ListNode*> p;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size() ;
        priority_queue<p, vector<p>, greater<p>>pq;
        for(auto node : lists){
            if(node){
                pq.push({node->val, node->next});
            }
        }

        ListNode* head = new ListNode(0) ;
        ListNode* curr = head ;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            curr->next = new ListNode(it.first);
            curr = curr->next ;
            ListNode* n = it.second ;
            if(n){
                pq.push({n->val, n->next});
            }
        }

        return head->next ;
    }
};