class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i_max_index = 0, i_min_index = 0;
        int i_max_profit = 0;
        for (int i = 1; i<prices.size(); i++)
        {
            if (prices[i]<prices[i_min_index])
            {
                i_min_index = i_max_index = i;
            }
            else if (prices[i]>=prices[i_max_index])
            {
                i_max_index = i;
                if (i_max_profit<prices[i_max_index] - prices[i_min_index])
                    i_max_profit = prices[i_max_index] - prices[i_min_index];
            }
        }
        return i_max_profit;
    }
};