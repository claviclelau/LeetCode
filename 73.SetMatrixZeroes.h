class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool b_first_row_clear = false;
        bool b_first_col_clear = false;
        for (int i = 0; i<matrix[0].size(); i++)
        {
            if (matrix[0][i]==0)
            {
                b_first_row_clear = true;
                break;
            }
        }
        for (int i = 0; i<matrix.size(); i++)
        {
            if (matrix[i][0]==0)
            {
                b_first_col_clear = true;
                break;
            }
        }
        
        for (int i = 0; i<matrix.size(); i++)
        {
            for (int j = 0; j<matrix[i].size(); j++)
            {
                if (matrix[i][j]==0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i<matrix[0].size(); i++)//Be careful! i starts from 1 NOT 0
        {
            if (matrix[0][i]==0)
            {
                for (int j = 0; j < matrix.size(); j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        for (int i = 1; i<matrix.size(); i++)//Be careful! i starts from 1 NOT 0
        {
            if (matrix[i][0]==0)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (b_first_row_clear)
        {
            for (int i = 0; i<matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        if (b_first_col_clear)
        {
            for (int i = 0; i<matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};