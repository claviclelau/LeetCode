class Solution {
public:
    int matrix[100][100];
    Solution(){
        memset(matrix, 0, sizeof(int)*10000);
        matrix[0][0] = 1;
    }
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return uniquePathsRe(m-1, n-1);
    }
    int uniquePathsRe(int m, int n)
    {
        if (m<0||n<0)
            return 0;
        if (matrix[m][n]!=0)
            return matrix[m][n];
        
        matrix[m][n] = uniquePathsRe(m, n-1) + uniquePathsRe(m-1, n);
        return matrix[m][n];
    }
};