class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size()<=1)
            return 0;
        int i_max, i_min;
        i_max = i_min = 0;
        int i_max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i]>prices[i_max])
                i_max = i;
            else if (prices[i]<=prices[i_max])// This is a little subtle.
            {
                i_max_profit += prices[i_max] - prices[i_min];
                i_max = i_min = i;
            }
        }
        i_max_profit += prices[i_max] - prices[i_min];
        return i_max_profit;
    }
};