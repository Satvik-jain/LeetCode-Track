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
        unordered_map<ListNode*, int> mpp;
        while(true){
            if (head == nullptr)
            return false;

            if (mpp.find(head) != mpp.end()){
                return true;
            }
            mpp[head] = 1;
            head = head -> next;
        }
        return false;
    }
};