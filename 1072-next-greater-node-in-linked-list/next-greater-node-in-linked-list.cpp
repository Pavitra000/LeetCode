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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *copy = head;
        vector<int> arr;
        stack<int> st;
        while(copy!=NULL){
            arr.push_back(copy->val);
            copy = copy->next;
        }
        vector<int> ans = arr;
        for(int i=arr.size()-1; i>=0; i--){
            if(st.empty()==1){st.push(arr[i]); ans[i]=0;}
            else if(st.top()>arr[i]){ans[i]=st.top(); st.push(arr[i]);}
            else if(st.top()<=arr[i]){
                while(st.top()<=arr[i]){
                    st.pop();
                    if(st.empty()){ans[i]=0; st.push(arr[i]); break;}
                    else if(st.top()>arr[i]){ans[i]=st.top(); st.push(arr[i]); break;}
                }
            }
        }
        return ans;
    }
};