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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* t1 = l1, * t2 = l2;
        ListNode* prevt1, * prevt2;
        while(t1 || t2){
            if (t1 && t2){
                t1->val = t1->val + t2->val + carry;
                if (t1->val>9){
                    t1->val = t1->val%10;
                    carry = 1;
                }
                else carry = 0;
                prevt1 = t1;
                prevt2 = t2;
                t1 = t1->next;
                t2 = t2->next;
            }
            else if(t1){
                t1->val = t1->val + carry;
                if (t1->val>9){
                    t1->val = t1->val%10;
                    carry = 1;
                }
                else carry = 0;
                prevt1 = t1;
                t1 = t1->next;
            }
            else{
                prevt1->next = t2;
                t1 = prevt1->next;
                t2 = nullptr;
            }
        }
        if(carry){
            ListNode* extra = new ListNode(1);
            prevt1->next = extra;
        }
        return l1;
    }
};