class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > answer;
        if (s.empty())
        {
        	answer.resize(1);
        	return answer;
        }
        vector<string> partition;
        DFS(s, 0, partition, answer);
        return answer;
    }
    bool checkPalindrome(const string & s, int iStart, int iEnd)
    {
    	while (iStart < iEnd)
    	{
    		if (s[iStart++]!=s[iEnd--])
    			return false;
    	}
    	return true;
    }
    void DFS(const string & s, int iStart, vector<string> & partition, vector<vector<string> > & answer)
    {
    	if (iStart == s.size())
    	{
    		answer.push_back(partition);
    		return;
    	}

    	int N = s.size();
    	for (int i = iStart; i<N; ++i)
    	{
    		if (checkPalindrome(s, iStart, i))
    		{
    			partition.push_back(s.substr(iStart, i - iStart + 1));
    			DFS(s, i+1, partition, answer);
    			partition.pop_back(); 
    		}
    	}
    }
};