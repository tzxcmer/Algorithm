class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int num: nums) {
            pq.push(num);
        }
        
        while(k > 0 && !pq.empty()) {
            int num = pq.top(); 
            pq.pop();
            pq.push(-num);
            k--;
        }
        
        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};
