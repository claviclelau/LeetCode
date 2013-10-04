class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return canJump_2(A, n);
    }
	int canJump_2(int A[], int n)
	{
		int i_slow = 0, i_fast = 0;
		int max_reach = 0;
		int jump_time = 0;
		while (max_reach<n-1)
		{
			for (int i = i_slow; i<=i_fast; i++)
				max_reach = max(max_reach, A[i] + i);
				
			if (max_reach == i_fast)
				break;
			i_slow = i_fast + 1;
			i_fast = max_reach;
			++jump_time;
		}
		return jump_time;
	}
};