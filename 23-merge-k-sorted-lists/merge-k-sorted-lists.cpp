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
    static bool comp(ListNode* l1, ListNode*l2){
        return l1->val < l2->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        vector<ListNode*> list;
        for (auto i : lists){
            if (i == NULL) continue;
            auto temp = i;
            while(temp){
                list.push_back(temp);
                temp = temp->next;
            }
        }
        if (list.size() == 0) return nullptr;
        sort(list.begin(), list.end(), comp);
        for (int i = 0; i < list.size(); i++){
            if (i == list.size() - 1){
                list[i]->next = NULL;
                break;
            }
            list[i]->next = list[i+1];
        }
        return list[0];
    }
};