class Solution {
public:
    struct cmp{
        bool operator()(const ListNode* t1, const ListNode* t2)
        {
            return t1->val > t2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>, cmp> heap;
        for(auto l : lists)
            if(l) heap.push(l);
        ListNode* ret = new ListNode (0);
        ListNode* prev = ret;
        while(!heap.empty())
        {
            ListNode* t = heap.top();
            heap.pop();
            prev->next = t;
            prev = prev->next;
            if(t->next)
                heap.push(t->next);
        }

        prev = ret->next;
        delete ret;
        return prev;
    }
};
