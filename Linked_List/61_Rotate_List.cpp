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
    int listSize(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (k == 0 || !head)
            return head;

        ListNode *l = head, *r = head;
        k = k % listSize(head);
        
        for (int i = 0; i < k; i++)
            r = r->next;

        while (r->next) {
            l = l->next;
            r = r->next;
        }

        r->next = head;
        ListNode* temp = l->next;
        l->next = nullptr;
        head = temp;
        return head;
    }
};