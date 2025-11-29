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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* altPtr = head->next;
        ListNode* altHead = altPtr;
        ListNode* mainPtr = head;
        while(altPtr != nullptr && altPtr->next != nullptr){
            mainPtr->next = altPtr->next;
            mainPtr = mainPtr->next;
            altPtr->next = mainPtr->next;
            altPtr = altPtr->next;
        }
        mainPtr->next = altHead;
        return head;
    }
};