class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==0)
			return;
		if (m==0)
		{
			for (int i = 0; i<n; i++)
				A[i] = B[i];
			return;
		}
		
		int i = m - 1, j = n - 1, k = m + n - 1;
		while(i>=0&&j>=0)
		{
			if (A[i]>B[j])
			{
				A[k] = A[i];
				--i;
			}
			else
			{
				A[k] = B[j];
				--j;
			}
			--k;
		}
		while (j>=0)
		{
			A[k] = B[j];
			--k;
			--j;
		}
    }
};