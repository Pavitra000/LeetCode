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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* copyA = headA;
        ListNode* copyB = headB;
        int A = 0;
        int B = 0;
        while(copyA!=NULL){
            A++;
            copyA = copyA->next;
        }
        copyA = headA;
        while(copyB!=NULL){
            B++;
            copyB = copyB->next;
        }
        copyB = headB;
        if(A>B){
            for(int i=1; i<=A-B; i++){
                copyA = copyA->next;
            }
        }
        else{for(int i=1; i<=B-A; i++){copyB = copyB->next;}}


        while(copyA!=copyB){copyA = copyA->next; copyB = copyB->next;}

        return copyA;
    }
};