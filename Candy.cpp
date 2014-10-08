class Solution {
public:
    int candy(vector<int> &ratings) {
        return candy_2(ratings);
    }
    int candy_1(vector<int> & ratings)
    {
    	int N = ratings.size();
    	if (N == 0)
    		return 0;
    	int maxValue = 1;
    	int maxIndex = 0;
    	int ret = 1;
    	int candy = 1;
    	for (int i = 1; i<N; ++i)
    	{
    		if (ratings[i] >= ratings[i-1])
    		{
    			candy = ratings[i] == ratings[i-1] ? 1 : candy + 1;
    			maxValue = candy;
    			maxIndex = i;
    		}
    		else
    		{
    			if (candy == 1)
    			{
    				ret += i - maxIndex - 1;
    				if (maxValue <= i - maxIndex)
    				{
    					++maxValue;
    					++ret;
    				}
    			}
    			candy = 1;
    		}
    		ret += candy;
    	}
    	return ret;
    }
    int candy_2(vector<int> & ratings)
    {
    	int N = ratings.size();
    	if (N == 0)
    		return 0;

    	vector <int> candy(N, 1);
    	for (int i = 1; i<N; ++i)
    	{
    		if (ratings[i]>ratings[i-1])
    			candy[i] = candy[i-1] + 1;
    	}

    	for (int i = N - 2; i>=0; --i)
    	{
    		if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
    			candy[i] = candy[i+1] + 1;
    	}

    	int ret = 0;

    	for (int i = 0; i<N; ++i)
    	{
    		ret += candy[i];
    	}

    	return ret;
    }
};