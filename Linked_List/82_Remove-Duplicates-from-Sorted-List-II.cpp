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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* left = dummy;

        while (left->next && left->next->next) {

            ListNode* right = left->next;
            if (right->val != right->next->val) {
                left = right;
            } else {
                while (right->next && right->val == right->next->val) {
                    ListNode* temp = right;
                    right = temp->next;
                    delete temp;
                }
                left->next = right->next;
                delete right;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};