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
    bool hasCycle(ListNode *head) {
        ListNode* hare = head;
        ListNode* tortoise = head;

        ListNode* check = head;
        if(check==NULL || check->next==NULL || check->next->next==NULL){return false;}
        while(1){
            hare = hare->next->next;
            tortoise = tortoise->next;

            if(hare == tortoise){return true;}

            if(hare==NULL){return false;}
            if(hare->next==NULL){return false;}
        }
    }
};