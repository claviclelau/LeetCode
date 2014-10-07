class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        return wordBreakDPNonRe(s, dict);
    }
    bool wordBreakRe(const string & s, int start, unordered_set<string> & dict)
    {
    	if (s.size()==0)
    		return false;

    	if (start == s.size())
    		return true;
    	unordered_set<string>::iterator iter;
    	for (int i = start; i < s.size(); ++i)
    	{
    		iter = dict.find(s.substr(start, i-start+1));
    		if (iter != dict.end() && wordBreakRe(s, i+1, dict))
    			return true;
    	}
    	return false;
    }
    bool wordBreakDP(const string & s, vector<char> & DP, unordered_set<string> & dict, int iStart)
    {
    	if (s.size() == 0)
    		return false;
    	if (iStart == s.size())
    		return true;

    	if (DP[iStart] != 0)
    		return DP[iStart] == 2;

    	for (int i = iStart + 1; i <= s.size(); ++i)
    	{
    		if (wordBreakDP(s, DP, dict, i) && dict.find(s.substr(iStart, i - iStart)) != dict.end())
    		{
    			DP[iStart] = 2;
    			return true;
    		}
    	}
    	DP[iStart] = 1;
    	return false;
    }
    bool wordBreakDPNonRe(const string & s, unordered_set<string> & dict)
    {
    	int N = s.size();
    	vector <bool> DP(N+1, false);
    	DP[0] = true;

    	for (int i = 1; i <= N; ++i)
    	{
    		for (int j = i - 1; j >= 0; --j)
    		{
    			if (DP[j] && dict.find(s.substr(j, i - j)) != dict.end())
    			{
    				DP[i] = true;
    				break;
    			}
    		}
    	}
    	return DP[N];
    }
};