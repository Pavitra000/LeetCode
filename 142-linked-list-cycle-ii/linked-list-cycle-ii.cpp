/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return NULL;
        }

        while(1){
            fast = fast->next->next;
            slow = slow->next;

            if(fast==slow){break;}
            if(fast==NULL){return NULL;}
            if(fast->next==NULL){return NULL;}
        }

        slow = head;

        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};