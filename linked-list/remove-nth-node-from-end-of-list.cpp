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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){
            if(n == 1) return nullptr;
            return head;
        }
        else if(!head->next->next){
            if(n == 2) return head->next;
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head;
        for(int i = 0; i < n; i++) fast = fast->next;
        if(!fast) return head->next;
        else fast = fast->next;
        ListNode* slow = head;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        return head;
    }
};