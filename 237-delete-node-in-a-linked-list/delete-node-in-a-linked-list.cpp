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
    void deleteNode(ListNode* node) {
        ListNode* temp = node, *curr = node;
        while(curr->next){
            temp = curr;
            curr = curr->next;
            temp->val = curr->val;
        }
        temp->next = NULL;
        delete curr;
    }
};