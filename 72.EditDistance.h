class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return minDistanceDP(word1, word2);
    }
	int minDistanceDP(const string & word1, const string & word2)
	{
		int M = word1.size()+1;
		int N = word2.size()+1;
		vector <int> row (N, -1);
		vector<vector<int> > DP(M, row);
		for (int i = 0; i<M; i++)
			DP[i][0] = i;
		for (int i = 1; i<N; i++)
			DP[0][i] = i;
			
		for (int i = 1; i<M; ++i)
		{
			for (int j = 1; j<N; ++j)
			{
				if (word1[i-1]==word2[j-1])
					DP[i][j] = DP[i-1][j-1];
				else
					DP[i][j] = min(min(DP[i-1][j-1], DP[i-1][j]), DP[i][j-1]) + 1;
			}
		}
		return DP[M-1][N-1];
	}
};