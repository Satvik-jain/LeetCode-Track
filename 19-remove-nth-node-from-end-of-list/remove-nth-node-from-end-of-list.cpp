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
    void helper(ListNode* head, int n, int& last, ListNode* &new_next, bool & is_first){
        if(!head) return;
        helper(head->next, n, last, new_next, is_first);
        if (last == n){
            head->next = new_next;
            is_first = false;
        }
        last += 1;
        if (last != n) new_next = head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int last = 0;
        ListNode* new_next = nullptr;
        bool is_first = true;
        helper(head, n, last, new_next, is_first);
        return (is_first)?head->next:head;
    }
};