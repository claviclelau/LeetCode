class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int answer = 0;
        for (int i = 0; i < 32; ++i)
		{
			int count = 0;
			int mask = 1 << i;
			for (int j = 0; j < n; ++j)
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