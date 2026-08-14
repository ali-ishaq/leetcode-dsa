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
    // O(n) Space

    // bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode*>seen;
    //     ListNode* curr=head;
    //     while(curr!=nullptr){
    //         if(seen.count(curr))
    //             return true;
    //         seen.insert(curr);
    //         curr=curr->next;
    //     }
    //     return false;
    // }

    // O(1) Space
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};