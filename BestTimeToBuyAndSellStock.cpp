class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
        	return 0;

        int minPrice = prices[0];
        int maxP = 0;
        int N = prices.size();
        for (int i = 1; i < N; ++i)
        {
        	int profit = prices[i] - minPrice;
        	maxP = profit > maxP ? profit : maxP;
        	minPrice = minPrice < prices[i] ? minPrice : prices[i];
        }
        return maxP;
    }
};