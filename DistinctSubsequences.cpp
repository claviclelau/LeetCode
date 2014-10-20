class Solution {
public:
    int numDistinct(string S, string T) {
        int N = T.size();
        vector <int> DP[2];
        DP[0].resize(N, 0);
        DP[1].resize(N, 0);
        int M = S.size();
        int current = 0;
        int previous = 1;
        for (int i = 0; i < M; ++i)
        {
        	current = i & 1;
        	previous = (~i) & 1;
        	for (int j = 0; j < N; ++j)
        	{
        		if (j == 0)
        		{
        			DP[current][0] = T[0] == S[i] ? DP[previous][0] + 1 : DP[previous][0];
        			continue;
        		}
        		DP[current][j] = T[j] == S[i] ? DP[previous][j-1] + DP[previous][j] : DP[previous][j]; 
        	}
        }
        return DP[current][N-1];
    }
};
