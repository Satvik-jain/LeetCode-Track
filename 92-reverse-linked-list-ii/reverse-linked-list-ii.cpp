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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        stack<ListNode*>st;
        ListNode* prev = nullptr, *curr = head;
        int i = 0;
        ListNode* lowerLim;
        while(true){
            i++;
            if (i == left) lowerLim = prev;
            if (i > right) break;
            ListNode* next = curr->next;
            if (i>=left && i<=right){
                st.push(curr);
            }
            prev = curr;
            curr = next;
        }
        ListNode* temp;
        if (lowerLim) lowerLim->next = st.top();
        if (left == 1) head = st.top();
        while(!st.empty()){
            temp = st.top(); 
            st.pop();
            temp->next = (st.empty()) ? nullptr : st.top();
        }
        temp -> next = curr;
        return head;
    }
};