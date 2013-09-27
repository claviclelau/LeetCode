class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (obstacleGrid[0][0]==1)
            return 0;
        vector<vector<int> > pathMatrix(obstacleGrid);
        for (int i = 0; i<pathMatrix.size(); i++)
        {
            for (int j = 0; j<pathMatrix[i].size(); j++)
            {
                pathMatrix[i][j] = -1;
            }
        }
        pathMatrix[0][0] = 1;
        return uniquePathRecursive(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1, pathMatrix);
    }
    int uniquePathRecursive(vector<vector<int> > &obstacleGrid, int i_row, int i_col, vector<vector<int> >& pathMatrix)
    {
        if (obstacleGrid[i_row][i_col]==1)
            return 0;
        if (pathMatrix[i_row][i_col]!=-1)
            return pathMatrix[i_row][i_col];
            
        pathMatrix[i_row][i_col] = (i_row==0||obstacleGrid[i_row-1][i_col]==1)?0:uniquePathRecursive(obstacleGrid, i_row - 1, i_col, pathMatrix);
        pathMatrix[i_row][i_col] += (i_col==0||obstacleGrid[i_row][i_col-1]==1)?0:uniquePathRecursive(obstacleGrid, i_row, i_col - 1, pathMatrix);
        
        return pathMatrix[i_row][i_col];
    }
};