class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());
        while (k--) {
            int x = q.top(); 
            q.pop();
            q.push(int(sqrt(x)));
        }

        long long sum = 0;
        while(!q.empty())
        {
            sum += q.top();
            q.pop();
        }

        return sum;
    }
};
