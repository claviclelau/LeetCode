class Solution {
public:
    int findMin(vector<int> &num) {
        return findMinRe(num, 0, num.size() - 1);
    }
    int findMinNonRe(vector<int> & num)
    {
        int N = num.size() - 1;
        if (num[0] < num[N])
            return num[0];
        
        int iStart = 0;
        int iEnd = N;
    	int minValue = INT_MAX;
    	while(iStart <= iEnd - 5)
    	{
    		int iMiddle = (iStart + iEnd)/2;
    		if (num[iStart] > num[iMiddle])
    			iEnd = iMiddle;
    		else
    			iStart = iMiddle;
    	}
    	
    	for (int i = iStart; i <= iEnd; ++i)
    		minValue = minValue < num[i] ? minValue : num[i];

    	return minValue;
    }

    int findMinRe(vector <int> & num, int iStart, int iEnd)
    {
        if (num[iStart] < num[iEnd])
            return num[iStart];
    	int minValue = INT_MAX;
    	if (iStart > iEnd - 5)
    	{
    		for(int i = iStart; i <= iEnd; ++i)
    			minValue = minValue < num[i] ? minValue : num[i];

    		return minValue;
    	}

    	int iMiddle = (iStart + iEnd)/2;
    	if (num[iStart] > num[iMiddle])
    		return findMinRe(num, iStart, iMiddle);
    	else
    		return findMinRe(num, iMiddle, iEnd);
    }
};