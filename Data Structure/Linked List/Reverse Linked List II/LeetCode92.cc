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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dum = new ListNode(-1);
        dum->next = head;
        ListNode* pre = dum;
        for(int i=0;i<left-1;i++) pre = pre->next;
        ListNode* cur = pre->next;
        ListNode* n;
        for(int i=0;i<right-left;i++)
        {
            n = cur->next;
            cur->next = n->next;
            n->next = pre->next;
            pre->next = n;
        }

        return dum->next;
    }
};
