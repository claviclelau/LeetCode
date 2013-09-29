class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        searchRe(A, 0, n-1, target);
    }
	int searchRe(int A[], int i_begin, int i_end, int target)
	{
		if (i_begin>i_end)
			return -1;
		if (i_begin==i_end)
			return A[i_begin]==target?i_begin:-1;
		
		int i_middle = (i_begin + i_end)/2;
		if (A[i_middle]==target)
			return i_middle;
		if (A[i_begin]<=A[i_middle])
		{
			if (target>=A[i_begin]&&target<=A[i_middle])
				return searchRe(A, i_begin, i_middle - 1, target);
			return searchRe(A, i_middle + 1, i_end, target);
		}
		else
		{
			if (target>=A[i_middle]&&target<=A[i_end])
				return searchRe(A, i_middle + 1, i_end, target);
			return searchRe(A, i_begin, i_middle - 1, target);
		}
	}
};