class Solution {
public:
    int minCut(string s) {
    	return minCutDP_2(s);
    }
    bool checkPalindrome(const string & s, int iStart, int iEnd)
    {
    	while(iStart < iEnd)
    	{
    		if (s[iStart++] != s[iEnd--])
    			return false;
    	}
    	return true;
    }
    void minCutDFS(const string & s, int & CutNum, int & minCutNum, int iStart)
    {
    	if (iStart == s.size())
    	{
    		if (CutNum < minCutNum)
    			minCutNum = CutNum;
    		return;
    	}

    	if (CutNum == minCutNum - 1)
   			return;

    	for (int i = s.size() - 1; i<= iStart; --i)
    	{
    		if (checkPalindrome(s, iStart, i))
    		{
    			++CutNum;
    			minCutDFS(s, CutNum, minCutNum, i + 1);
    			--CutNum;
    		}
    	}
    }
    int minCutDP(const string & s)
    {
    	if (s.size() <= 1)
    		return 0;
    	vector<int> cutNum(s.size() + 1, -1);
    	cutNum[0] = 0;
    	int N = s.size();
    	for (int i = 1; i <= N; ++i)
    	{
    		cutNum[i] = cutNum[i-1] + 1;
    		for (int j = i - 1; j >= 0; j--)
    		{
    			if (checkPalindrome(s, j, i - 1))
    			{
    				cutNum[i] = cutNum[i] < cutNum[j] + 1 ? cutNum[i] : cutNum[j] + 1;
    			}
    		}
    	}
    	return cutNum[N] - 1;
    }
    int minCutDP_2(const string & s)
    {
    	if (s.size() <= 1)
    		return 0;
    	vector<int> cutNum(s.size(), -1);
    	vector<bool> isP(s.size(), false);
    	cutNum[0] = 0;
    	int N = s.size();
    	for (int i = 1; i < N; ++i)
    	{
    		cutNum[i] = cutNum[i-1] + 1;
    		isP[i] = true;
    		for (int j = 0; j < i; ++j)
    		{
    			isP[j] = s[i] == s[j] ? isP[j+1] : false;

    			if (isP[j])
    				cutNum[i] = j == 0 ? 0:min(cutNum[i], cutNum[j-1] + 1); 
    		}
    	}
    	return cutNum[N-1];
    }
};