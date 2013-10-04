class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n==0)
			return 0;
		int * lmax = new int[n];
		int * rmax = new int[n];
		lmax[0] = A[0];
		rmax[n-1] = A[n-1];
		int i_max = A[0];
		for (int i = 0; i<n; ++i)
			lmax[i] = i_max>A[i]?i_max:i_max=A[i];
		i_max = A[n-1];	
		for (int i = n-1; i>=0; --i)
			rmax[i] = i_max>A[i]?i_max:i_max=A[i];
			
		int answer = 0;
		for (int i = 0; i<n; ++i)
			answer += (min(lmax[i], rmax[i]) - A[i]);
		delete [] lmax;
		delete [] rmax;
		return answer;
    }
};