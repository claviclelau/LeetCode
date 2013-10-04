class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
		while (i<n)//Should pay special attention to it. Must use while not for.
		{
			if (A[i]!=i+1&&A[i]>0&&A[i]<=n&&A[i]!=A[A[i]-1])//If without A[i]!=A[A[i]-1], it will get stuck.
				swap(A[i], A[A[i]-1]);
			else
				i++;
		}
		for (int i = 0; i<n; i++)
			if (A[i] != (i+1))
				return i+1;
		return n+1;
    }
};