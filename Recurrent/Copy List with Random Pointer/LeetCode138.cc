class Solution {
public:
    unordered_map<Node*, Node*> hash;
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        if(!hash.count(head))
        {
            Node* newnode = new Node(head->val);
            hash[head] = newnode;
            newnode->next = copyRandomList(head->next);
            newnode->random = copyRandomList(head->random);
        }

        return hash[head];
    }
};
