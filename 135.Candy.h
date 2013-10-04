class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (ratings.size()<=1)
            return ratings.size();
        int answer = 0, i_last_count = 0, i_current_count = 1;
		bool isUp = ratings[0]<ratings[1];
		for (int i = 1; i<ratings.size(); i++)
		{
			if (isUp)
			{
				while (i<ratings.size()&&ratings[i]>ratings[i-1])
				{
					++i_current_count;
					++i;
				}
				answer += i_current_count*(i_current_count-1)/2;
				i_last_count = i_current_count;
			}
		}
    }
};