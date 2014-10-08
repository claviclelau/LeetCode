class Solution {
public:
    int singleNumber(int A[], int n) {
        int answer = 0;
        for (int i = 0; i<32; ++i)
        {
        	int mask = 1<<i;
        	int count = 0;
        	for (int j = 0; j<n; ++j)
        	{
        		if (A[j]&mask)
        			++count;
        	}
        	if (count % 3 != 0)
        		answer |= mask;
        }
        return answer;
    }
};