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
    // O(n) space
    // void reorderList(ListNode* head) {
    //     if (!head || !head->next) return;

    //     deque<ListNode*> dq;
    //     for (ListNode* curr = head; curr; curr = curr->next)
    //         dq.push_back(curr);

    //     ListNode dummy;
    //     ListNode* tail = &dummy;

    //     while (dq.size() > 1) {
    //         tail->next = dq.front(); dq.pop_front();
    //         tail = tail->next;
    //         tail->next = dq.back(); dq.pop_back();
    //         tail = tail->next;
    //     }
    //     if (!dq.empty()) {
    //         tail->next = dq.front();
    //         tail = tail->next;
    //     }
    //     tail->next = nullptr;
    // }

    // O(1) space
    void reorderList(ListNode* head) {
        //   Find Middle
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second list
        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr; // unlink first part
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Merge
        ListNode* first = head;
        ListNode* sec = prev;
        while (sec) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec->next;
            first->next = sec;
            sec->next = temp1;
            first = temp1;
            sec = temp2;
        }
    }
};