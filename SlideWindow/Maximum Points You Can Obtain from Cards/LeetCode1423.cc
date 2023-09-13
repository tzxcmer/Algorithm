class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int wsize = n - k;
        int sum = accumulate(cardPoints.begin(), 
        cardPoints.begin() + wsize, 0);
        int minsum = sum;
        for(int i=wsize;i<n;i++)
        {
            sum += cardPoints[i] - cardPoints[i-wsize];
            minsum = min(sum,minsum);
        }

        return accumulate(cardPoints.begin(),cardPoints.end(),0) - minsum;
    }
};
