class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> answer;
		FindRangeIndex(A, n, target, answer);
		return answer;
    }
	int searchRangeSmallRe(int A[], int i_begin, int i_end, int target)
	{
		if (i_end<i_begin)
			return -1;
			
		int i_middle = (i_begin + i_end)/2;
		if (A[i_middle]==target)
		{
			if (i_middle==i_begin||A[i_middle-1]!=target)
				return i_middle;
			return searchRangeSmallRe(A, i_begin, i_middle - 1, target);
		}
		if (A[i_middle]<target)
			return searchRangeSmallRe(A, i_middle + 1, i_end, target);
		else
			return searchRangeSmallRe(A, i_begin, i_middle - 1, target);
	}
	int searchRangeBigRe(int A[], int i_begin, int i_end, int target)
	{
		if (i_end<i_begin)
			return -1;
			
		int i_middle = (i_begin + i_end)/2;
		if (A[i_middle]==target)
		{
			if (i_middle==i_end||A[i_middle+1]!=target)
				return i_middle;
			return searchRangeBigRe(A, i_middle + 1, i_end, target);
		}
		if (A[i_middle]<target)
			return searchRangeBigRe(A, i_middle + 1, i_end, target);
		else
			return searchRangeBigRe(A, i_begin, i_middle - 1, target);
	}
	//From AnnieKim's code.
	void FindRangeIndex(int A[], int n, int target, vector<int> & answer)
	{
		answer.clear();
		answer.resize(2, -1);
		int l = FindLower(A, n, target);
		int u = FindUpper(A, n, target);
		if (l<=u)
		{
			answer[0] = l;
			answer[1] = u;
		}
	}
	int FindLower(int A[], int n, int target)
	{
		int l = 0, u = n - 1;
		while(l<=u)
		{
			int middle = (l+u)/2;
			if (A[middle]<target)
				l = middle + 1;
			else
				u = middle - 1;
		}
		return l;
	}
	int FindUpper(int A[], int n, int target)
	{
		int l = 0, u = n - 1;
		while(l<=u)
		{
			int middle = (l+u)/2;
			if (A[middle]<=target)
				l = middle + 1;
			else
				u = middle - 1;
		}
		return u;
	}
};