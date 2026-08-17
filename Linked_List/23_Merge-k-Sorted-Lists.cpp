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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(ListNode* i : lists){
            while(i){
                pq.push(i->val);
                i=i->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while(!pq.empty()) {
            curr->next = new ListNode(pq.top());
            curr=curr->next;
            pq.pop();           
        }
        return dummy->next;
    }
};