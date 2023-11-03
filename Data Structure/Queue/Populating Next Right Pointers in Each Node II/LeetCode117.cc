class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            Node* pre;
            Node* no;
            for(int i=0;i<sz;i++)
            {
                if(i == 0)
                {
                    pre = q.front();
                    q.pop();
                    no = pre;
                }
                else
                {
                    no = q.front();
                    q.pop();
                    pre->next = no;
                    pre = pre->next;
                }
                if(no->left) q.push(no->left);
                if(no->right) q.push(no->right);
            }
            no->next = nullptr;
        }
        return root;
    }
};
