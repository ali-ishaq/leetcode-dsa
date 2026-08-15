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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* r=head;
      ListNode* l=head;

      for(int i=0;i<n;i++)
        r=r->next;

      if(!r)
        return head->next;

      while(r->next){
        l=l->next;
        r=r->next;
      }
      
      l->next=l->next->next;

      return head;
    }
};