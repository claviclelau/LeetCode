class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > answer;
		vector <int> combinations;
		sort(num.begin(), num.end());
		combinationSum2Re(num, target, answer, combinations, 0, 0);
		return answer;
    }
	void combinationSum2Re(vector<int> & num, int target, vector<vector<int> > & answer, vector <int> & combinations, int sum, int order)
	{
		for (int i = order; i<num.size(); i++)
		{
			int i_count = 1;
			while(i<num.size()-1&&num[i]==num[i+1])
				++i_count, ++i;
			int i_size = combinations.size();
			for (int j = 1; j<=i_count; j++)
			{
				int temp_sum = sum + j*num[i];
				if (temp_sum==target)
				{
					combinations.push_back(num[i]);
					answer.push_back(combinations);
					combinations.resize(i_size);
					break;
				}
				else if (temp_sum<target)
				{
					combinations.push_back(num[i]);
					combinationSum2Re(num, target, answer, combinations, temp_sum, i+1);
				}
				else
					break;
			}
			combinations.resize(i_size);
		}
	}
};