class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return searchMatrixRecursive(matrix, target, 0, matrix.size()*matrix[0].size() - 1);
    }
    bool searchMatrixRecursive(vector<vector<int> > &matrix, int target, int i_start, int i_end)
    {
        int i_middle = (i_start+i_end)/2;
        int i_row, i_col;
        GetRowAndCol(i_middle, matrix[0].size(), i_row, i_col);
        if (matrix[i_row][i_col]==target)
            return true;
        else if (i_start==i_end)
            return false;
            
        if (target<matrix[i_row][i_col])
            return searchMatrixRecursive(matrix, target, i_start, (i_middle-1)>i_start?(i_middle-1):i_start);
        else
            return searchMatrixRecursive(matrix, target, i_middle + 1, i_end);
    }
    void GetRowAndCol(int i_value, int i_row_length, int & i_row, int & i_col)
    {
        i_col = i_value%i_row_length;
        i_row = i_value/i_row_length;
    }
};