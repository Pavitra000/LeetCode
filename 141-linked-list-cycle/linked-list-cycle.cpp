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
        unordered_map<ListNode* ,int> mapp;
        while(head!=NULL){
            if(mapp.find(head)==mapp.end()){mapp[head]=1;}
            else if(mapp.find(head)!=mapp.end()){return true;}
            head = head->next;
        }
        return false;
    }
};