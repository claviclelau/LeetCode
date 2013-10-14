class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector <char> DP(s.size(), 0);
		return wordBreakDP(s, dict, DP, s.size()-1);
    }
	//Time limit exceeded.
	bool wordBreakRe(const string & s, int i_start, unordered_set<string> & dict)
	{
		if (i_start==s.size())
			return true;
		int i_length = s.size() - i_start;
		string word;
		for (int i = 1; i<=i_length; i++)
		{
			word = s.substr(i_start, i);
			if (dict.find(word)!=dict.end()&&wordBreakRe(s, i_start + i, dict))
				return true;
		}
		return false;
	}
	//DP
	bool wordBreakDP(string s, unordered_set<string> &dict, vector <char> & DP, int i_length)
	{
		if (i_length==-1)
			return true;
		if (DP[i_length]!=0)
			return DP[i_length]==2;
		for (int i = i_length - 1; i>=-1; --i)
		{
			if (wordBreakDP(s, dict, DP, i)&&dict.find(s.substr(i+1, i_length - i))!=dict.end())
			{
				DP[i_length] = 2;
				return true;
			}
		}
		DP[i_length] = 1;
		return false;
	}
};