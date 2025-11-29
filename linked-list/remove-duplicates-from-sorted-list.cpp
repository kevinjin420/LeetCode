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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* it = head;
        while(it != nullptr && it->next != nullptr){
            if(it->val == it->next->val){
                it = delNext(it);
            }
            else{
                it = it->next;
            }
        }
        return head;
    }

    ListNode* delNext(ListNode* it){
        ListNode* del = it->next;
        it->next = it->next->next;
        delete del;
        return it;
    }
};