class Solution {
public:
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return numDistinctDP(S, T);
    }
	//Time limit exceeded.
	void numDistinctRe(const string & S, const string & T, int & num, int i_start_s, int i_start_t)
	{
		if (i_start_t == T.size())
		{
			++num;
			return;
		}
		int N = S.size() - T.size() + i_start_t;
		int s = i_start_s;
		while(s<=N)
		{
			if (S[s]==T[i_start_t])
				numDistinctRe(S, T, num, s + 1, i_start_t + 1);
			++s;
		}
	}
	//Pass.
	int numDistinctDP(const string & S, const string & T)
	{
		vector <int> DP[2];
		DP[0].resize(T.size(), 0);
		DP[1].resize(T.size(), 0);
		for (int i = S.size()-1; i>=0; --i)
		{
			for (int j = T.size()-1; j>=0; --j)
			{
				if (T[j]==S[i])
					DP[i&1][j] = DP[(i+1)&1][j] + (j==T.size()-1?1:DP[(i+1)&1][j+1]);
				else
					DP[i&1][j] = DP[(i+1)&1][j];
			}
		}
		return DP[0][0];
	}
};