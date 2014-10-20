class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N <= 1)
            return 0;
            
        vector<int> front(N, 0);
        vector<int> back(N, 0);

        int minPrice = prices[0];
        int maxP = 0;
        for (int i = 0; i < N; ++i)
        {
        	int profit = prices[i] - minPrice;
        	maxP = profit > maxP ? profit : maxP;
        	minPrice = minPrice < prices[i] ? minPrice : prices[i];
        	front[i] = maxP;
        }

        minPrice = prices[N-1];
        maxP = 0;
        for (int i = N - 2; i >=0; --i)
        {
        	int profit = minPrice - prices[i];
        	maxP = profit > maxP ? profit : maxP;
        	minPrice = minPrice > prices[i] ? minPrice : prices[i];
        	back[i] = maxP;
        }

        maxP = front[0] + back[0];
        for (int i = 1; i < N; ++i)
        {
        	int sum = front[i] + back[i];
        	maxP = maxP > sum ? maxP : sum;
        }
        return maxP;
    }
};