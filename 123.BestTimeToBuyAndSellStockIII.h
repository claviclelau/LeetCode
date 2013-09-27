class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2)
            return 0;

        int * from_begin = new int[prices.size()];
        int * from_end = new int[prices.size()];
        int i_max_profit = 0, i_min = 0, i_max = 0;
        from_begin[0] = 0;
        from_end[prices.size() - 1] = 0;
        for (int i = 1; i<prices.size(); ++i)
        {
            if (prices[i]>prices[i_max])
            {
                i_max = i;
                i_max_profit = max(i_max_profit, (prices[i_max] - prices[i_min]));
            }
            else if(prices[i]<prices[i_min])
            {
                i_max = i_min = i;
            }
            from_begin[i] = i_max_profit;
        }
        i_max_profit = 0, i_min = i_max = prices.size() - 1;
        for (int i = prices.size() - 2; i>=0; --i)
        {
            if (prices[i]<prices[i_min])
            {
                i_min = i;
                i_max_profit = max(i_max_profit, (prices[i_max] - prices[i_min]));
            }
            else if(prices[i]>prices[i_max])
            {
                i_max = i_min = i;
            }
            from_end[i] = i_max_profit;
        }
        i_max_profit = 0;
        for (int i = prices.size() - 1; i>=0; --i)
        {
            i_max_profit = max(i_max_profit, (from_end[i] + from_begin[i]));//See Notes. This is important.
        }
        delete [] from_begin;
        delete [] from_end;
        return i_max_profit;
    }
};