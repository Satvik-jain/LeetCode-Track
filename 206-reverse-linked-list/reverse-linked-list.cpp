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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        stack<ListNode*> st;
        while(head){
            st.push(head);
            head = head->next;
        }
        head = st.top();
        st.pop();
        ListNode* curr = head;
        while(!st.empty()){
            curr->next = st.top();
            curr = st.top();
            st.pop();
        }
        curr->next = NULL;
        return head;
    }
};