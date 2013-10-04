class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (n==0)
			return 0;
        int i_fast = 1, i_slow = 0;
		int i_count = 1;
		while(i_fast<n)
		{
			if (A[i_fast]==A[i_slow])
			{
				A[++i_slow] = A[i_fast];
				while ((++i_fast)<n&&A[i_fast] == A[i_slow]);
			}
			else
				A[++i_slow] = A[i_fast++];
		}
		return i_slow+1;
    }
};