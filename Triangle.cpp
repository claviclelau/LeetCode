class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        return minimumTotalNonRe(triangle);
    }
    //Time limit exceeded.
    int minimumTotalRe(vector<vector<int> > &triangle, int i, int j)
    {
        if (i == triangle.size() - 1)
            return triangle[i][j];
        
        int left, right;
        left = minimumTotalRe(triangle, i + 1, j);
        right = minimumTotalRe(triangle, i + 1, j + 1);
        
        return triangle[i][j] + (left < right ? left : right);
    }
    //DP
    int minimumTotalNonRe(vector<vector<int> > &triangle)
    {
        int minimum = 0;
        int N = triangle.size();
        vector <int> DP(triangle[N-1]);
        for (int i = N - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                DP[j] = triangle[i][j] + (DP[j] < DP[j + 1] ? DP[j] : DP[j+1]);
            }
        }
        return DP[0];
    }
};