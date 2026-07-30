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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* null = NULL;
        if(head==NULL){return head;}
        if(head->next==NULL && n==1){return null;}
        if(head->next->next==NULL && n==1){head->next=NULL; return head;}
        if(head->next->next==NULL && n==2){head=head->next; return head;}
        ListNode* check = head;
        int length = 0;
        while(check!=NULL){check = check->next; length++;}
        if(n==length){head = head->next; return head;}
        check = head;
        for(int i=1; i<=length-n-1; i++){
            check = check->next;
        }
        check->next = check->next->next;
        return head;
    }
};