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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* check = head;
        int lengthOfLL = 0;

        while(check!=NULL){
            check = check->next;
            lengthOfLL++;
        }
        if(lengthOfLL<=1){return NULL;}
        if(lengthOfLL==2){head->next=NULL; return head;}

        check = head;
        for(int i=0; i<(lengthOfLL/2)-1; i++){
            check = check->next;
        }
        check->next = check->next->next;
        return head;
    }
};