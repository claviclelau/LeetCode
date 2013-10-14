class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> row(n,0);
        vector<vector<int> > matrix(n, row);
        
        char next_move = 0;
        int i_row = 0, i_col = 0;
        for (int i = 1; i<=n*n; i++)
        {
            matrix[i_row][i_col] = i;
            switch(next_move){
                case 0:
                    if (i_col==n-1||matrix[i_row][i_col+1]!=0)
                    {
                        ++i_row;
                        next_move = (next_move+1)%4;
                    }    
                    else
                        ++i_col;
                    break;
                case 1:
                    if (i_row==n-1||matrix[i_row+1][i_col]!=0)
                    {
                        --i_col;
                        next_move = (next_move+1)%4;
                    }
                    else
                        ++i_row;
                    break;
                case 2:
                    if (i_col==0||matrix[i_row][i_col-1]!=0)
                    {
                        --i_row;
                        next_move = (next_move+1)%4;
                    }    
                    else
                        --i_col;
                    break;
                case 3:
                    if (i_row==0||matrix[i_row-1][i_col]!=0)
                    {
                        ++i_col;
                        next_move = (next_move+1)%4;
                    }
                    else
                        --i_row;
                    break;
            }    
        }
        return matrix;
    }
};