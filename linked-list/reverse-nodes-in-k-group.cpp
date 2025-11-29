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
    ListNode* reverseKGroup(ListNode* head, int k) {
        deque<ListNode*> s;
        ListNode* curr = head;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        while(true){
            for(int i = 0; i < k; i++){
                if(!curr) break;
                ListNode* temp = curr->next;
                curr->next = nullptr;
                s.push_back(curr);
                curr = temp;
            }
            if(s.size() == k) while(s.size()){
                res->next = s.back();
                res = res->next;
                s.pop_back();
            }
            else{
                while(s.size()){
                    res->next = s.front();
                    res = res->next;
                    s.pop_front();
                }
            }
            if(!curr) break;
        }
        return dummy->next;
    }
};