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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if(lenA > lenB){
            for(int i = 0; i < abs(lenA - lenB); i++){
                headA = headA->next;
            }
        }
        else if(lenA < lenB){
            for(int i = 0; i < abs(lenA - lenB); i++){
                headB = headB->next;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    int getLen(ListNode* node){
        int count = 0;
        while(node != nullptr){
            node = node->next;
            count++;
        }
        return count;
    }
};