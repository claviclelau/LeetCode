class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		return candy_3(ratings);
    }
    int candy_1(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
        vector <int> candy_num(INT_MIN, ratings.size());
		int i_count = 0, N = candy_num.size() - 1;
		bool isUp = true;
		for (int i = 0; i<N; ++i)
		{
			if (ratings[i]<ratings[i+1])
			{
				candy_num[i] = ++i_count;
				isUp = true;
			}
			else if (isUp)
			{
				isUp = false;
				candy_num[i] = ++i_count;
				i_count = 0;
			}
		}
		if (ratings[N]>ratings[N-1])
			candy_num[N] = ++i_count;
		i_count = 0;
		isUp = true;
		for (int i = N; i>0; --i)
		{
			if (ratings[i]<ratings[i-1])
			{
				candy_num[i] = ++i_count;
				isUp = true;
			}
			else if (isUp)
			{
				isUp = false;
				candy_num[i] = ++i_count > candy_num[i]? i_count : candy_num[i];
				i_count = 0;
			}
		}
		i_count = 0;
		for (int i = N; i>=0; i++)
			i_count += candy_num[i];
		
		return i_count;
    }
	//Second attempt. But if failed on case {1,2,2}. My output is 5 while the correct answer is 4.
	//It seems that I misunderstood the meaning of the problem.
	//If neighboring ratings are equal, they are not necessarily the same. For example, when ratings are {1,2,2,3}, candy number can be {1,2,1,2}.
	int candy_2(vector<int> &ratings)
	{
		if (ratings.size()<=1)
			return ratings.size();
		
		int i_candy = 1, i_total_candy = 1, i_last_position = ratings.size() - 1;
		bool isDown = ratings[ratings.size()-1]>ratings[ratings.size()-2]? true: false;
		for (int i = ratings.size() - 2; i>=0; --i)
		{
			if (ratings[i] == ratings[i+1])
				i_total_candy += i_candy;
			else if (ratings[i]>ratings[i+1])
			{
				if (isDown)
				{
					isDown = false;
                    i_total_candy += ((i_candy > 1? (i_last_position - i) : (i_last_position - i + 1))*(1 - i_candy));
					i_candy = 1;
					i_last_position = i;
				}
				else
					i_total_candy += (++i_candy);
			}
			else
			{
                if (!isDown)
                {
                    isDown = true;
                    if (i!=0)
                        i_last_position = i;
                }
				i_total_candy += (--i_candy);
			}
		}
		if (isDown)
			i_total_candy += ((i_last_position+1)*(1 - i_candy));
		return i_total_candy;
	}
	
	//Third attempt by modifying the code of second attempt. And correct some mistakes.
	//Still it is a little complicated to understand.
	//Will refer to someone else's code.
	int candy_3(vector<int> &ratings)
	{
		if (ratings.size()<=1)
			return ratings.size();
		
		int i_candy = 1, i_total_candy = 1, i_last_position = ratings.size() - 1;
		bool isDown = ratings[ratings.size()-1]>ratings[ratings.size()-2]? true: false;
		for (int i = ratings.size() - 2; i>=0; --i)
		{
			if (ratings[i] == ratings[i+1])
			{
                if (isDown)
                    i_total_candy += (i_candy > 1 ? (i_last_position - i - 1) : (i_last_position - i))*(1 - i_candy);
				i_candy = 1;
				i_total_candy += i_candy;
				i_last_position = i;
			}
			else if (ratings[i]>ratings[i+1])
			{
				if (isDown)
				{
					isDown = false;
                    i_total_candy += (i_candy > 1 ? (i_last_position - i - 1) : (i_last_position - i))*(1 - i_candy);
					i_candy = 2;
					i_total_candy += i_candy;
					i_last_position = i + 1;
				}
				else
					i_total_candy += (++i_candy);
			}
			else
			{
                if (!isDown)
                {
                    isDown = true;
                    i_last_position = i + 1;
                }
				i_total_candy += (--i_candy);
			}
		}
		if (isDown)
			i_total_candy += (i_candy > 1 ? (i_last_position) : (i_last_position + 1))*(1 - i_candy);
		return i_total_candy;
	}
};