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
    ListNode* deleteMiddle(ListNode* head) {
        int length = findLen(head);
        if(length == 1){
            return nullptr;
        }
        ListNode* ptr = head;
        for(int i = 0; i < ((length) / 2) - 1; i++){
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
    }

    int findLen(ListNode* head){
        int count = 0;
        while(head != nullptr){
            head = head->next;
            count++;
        }
        return count;
    }
};