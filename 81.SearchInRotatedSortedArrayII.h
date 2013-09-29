/**************************************************************************
If there are duplicates, you can't decide which branch the target is in.
for example, target is 3, the array is {1,3,1,1,1}.
So binary search is not possible.
**************************************************************************/
class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i<n; i++)
		{
			if (A[i]==target)
				return true;
		}
		return false;
    }
};