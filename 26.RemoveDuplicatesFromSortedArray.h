class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n==0)
			return 0;
		int i_fast = 1, i_slow = 0;
		while(i_fast<n)
		{
			if (A[i_fast]!=A[i_slow])
				A[++i_slow] = A[i_fast];
			++i_fast;
		}
		return i_slow+1;
    }
};