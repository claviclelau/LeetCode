class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return searchInsertRe(A, 0, n-1, target);
    }
    int searchInsertRe(int A[], int i_start, int i_end, int target)
    {
        if (A[i_end]<target)
            return i_end+1;
		if (i_start==i_end)
			return i_start;
		int i_middle = (i_start + i_end)/2;
		if (A[i_middle]==target)
			return i_middle;
		if (A[i_middle]<target)
			return searchInsertRe(A, i_middle + 1, i_end, target);
		else
			return searchInsertRe(A, i_start, i_middle, target);
	}
};