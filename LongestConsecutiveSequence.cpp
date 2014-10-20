class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> numSet;
        int N = num.size();
        for (int i = 0; i < N; ++i)
        {
        	numSet.insert(num[i]);
        }

        int answer = 0;
        for (int i = 0; i < N; ++i)
        {
        	int val = num[i];
        	int iCount = 0;
        	if (numSet.find(val) != numSet.end())
        	{
        		while (numSet.find(val++) != numSet.end())
        		{
        			++iCount;
        			numSet.erase(val-1);
        		}

        		val = num[i];
        		while (numSet.find(--val) != numSet.end())
        		{
        			++iCount;
        			numSet.erase(val);
        		}
        	}
        	answer = max(iCount, answer);
        }
        return answer;
    }
};