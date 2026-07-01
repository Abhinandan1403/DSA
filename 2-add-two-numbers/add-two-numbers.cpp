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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;

        while(l1 && l2){
            sum += l1->val;
            sum += l2->val;
            sum += carry;
            carry = sum/10;
            sum %= 10;
            ListNode* node = new ListNode(sum);
            temp->next = node;
            temp = node;
            l1 = l1->next;
            l2 = l2->next;
            sum = 0;
        }

        while(l1){
            sum += l1->val;
            sum += carry;
            carry = sum/10;
            sum %= 10;
            ListNode* node = new ListNode(sum);
            temp->next = node;
            temp = node;
            l1 = l1->next;
            sum = 0;
        }

        while(l2){
            sum += l2->val;
            sum += carry;
            carry = sum/10;
            sum %= 10;
            ListNode* node = new ListNode(sum);
            temp->next = node;
            temp = node;
            l2 = l2->next;
            sum = 0;
        }

        if(carry){
            ListNode* node = new ListNode(1);
            temp->next = node;
        }
        return head->next;
    }
};