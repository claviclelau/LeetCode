class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        SudokuDFS(board);
    }
	bool SudokuDFS(vector<vector<char> > &board)
	{
		for (int i = 0; i<9; ++i)
		{
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j]=='.')
				{
					char c_available[9];
					memset(c_available, 1, 9);
					CheckAvailability(board, i, j, c_available);
					for (int k = 0; k<9; k++)
					{
						if (c_available[k])
						{
							board[i][j] = '1' + k;
							if (SudokuDFS(board))
								return true;
						}
					}
					board[i][j] = '.';
					return false;
				}
			}
		}
		return true;
	}
	void CheckAvailability(vector<vector<char> > &board, int i, int j, char c_available[9])
	{
		for (int m = 0; m<9; m++)
		{
			if (board[m][j]!='.') c_available[board[m][j]-'1'] = 0;
			if (board[i][m]!='.') c_available[board[i][m]-'1'] = 0;
			int box_i = i/3*3 + m/3, box_j = j/3*3 + m%3;
			if (board[box_i][box_j]!='.') c_available[board[box_i][box_j]-'1'] = 0;
		}
	}
};