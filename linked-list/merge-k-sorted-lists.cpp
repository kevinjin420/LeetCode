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
    struct listComp{
        bool operator()(const ListNode* lhs, const ListNode* rhs){
            return lhs->val > rhs->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        priority_queue<ListNode*, vector<ListNode*>, listComp> pq;
        for(int i = 0; i < lists.size(); i++) if(lists[i]) pq.push(lists[i]);
        while(pq.size()){
            ListNode* temp = pq.top();
            pq.pop();
            head->next = temp;
            head = head->next;
            if(temp->next) pq.push(temp->next);
        }
        return dummy->next;
    }
};