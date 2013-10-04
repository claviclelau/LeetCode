class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return canJump_3(A, n);
    }
	//Time limit exceeded.
    bool DFS(int A[], int n, char * c_visited, int i_visit)
    {
        c_visited[i_visit] = 1;
        for (int i = A[i_visit]; i>=1; i--)
        {
            int i_new_visit = i_visit + i;
            
            if (i_new_visit>=n-1)
                return true;
            
            if (c_visited[i_new_visit])
                continue;
                
            if (DFS(A, n, c_visited, i_new_visit))
                return true;
        }
        return false;
    }
	//Time limit exceeded.
	bool canJump_1(int A[], int n)
	{
		char * jump = new char [n];
		memset(jump, 0, n*sizeof(char));
		jump[n-1] = 1;
		bool findNew;
		while(1)
		{
			findNew = false;
			for (int i = 0; i<n; i++)
			{
				if (jump[i])
					continue;
				int l_bound = max(0, i-A[i]);
				int u_bound = min(n-1, i+A[i]);
				for (int j = l_bound; j<=u_bound; ++j)
				{
					if (jump[j])
					{
						jump[i] = 1;
						findNew = true;
					}
				}
			}
			if (!findNew)
				break;
		}
		bool answer = jump[0];
		delete [] jump;
		return answer;
	}
	bool canJump_2(int A[], int n)
	{
		int i_slow = 0, i_fast = 0;
		int max_reach = 0;
		while (max_reach<n)
		{
			for (int i = i_slow; i<=i_fast; i++)
				max_reach = max(max_reach, A[i] + i);
				
			if (max_reach == i_fast)
				break;
			i_slow = i_fast;
			i_fast = max_reach;
		}
		return max_reach >= n-1;
	}
	bool canJump_3(int A[], int n)
	{
		int max_reach = 0;
		for (int i = 0; i<n; i++)
		{
			if (max_reach>=i)
				max_reach = max(max_reach, A[i] + i);
		}
		return max_reach >= n-1;
	}
};