class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >pathSumMatrix(grid);
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[i].size(); j++)
            {
                pathSumMatrix[i][j] = -1;
            }
        }
        pathSumMatrix[0][0] = grid[0][0];
        return minPathSumRecursive(grid, pathSumMatrix, grid.size() - 1, grid[0].size() - 1);
    }
    int minPathSumRecursive(vector<vector<int> > &grid, vector<vector<int> > &pathSumMatrix, int i_row, int i_col)
    {
        if (pathSumMatrix[i_row][i_col]!=-1)
            return pathSumMatrix[i_row][i_col];
        
        int i_up = i_row==0?0x7FFFFFFF:minPathSumRecursive(grid, pathSumMatrix, i_row - 1, i_col);
        int i_left = i_col==0?0x7FFFFFFF:minPathSumRecursive(grid, pathSumMatrix, i_row, i_col - 1);
        return pathSumMatrix[i_row][i_col] = (i_up<i_left?i_up:i_left) + grid[i_row][i_col];
    }
};