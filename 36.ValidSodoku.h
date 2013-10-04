class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return CheckLines(board)&&CheckRows(board)&&CheckCells(board);
    }
	bool CheckLines(vector<vector<char> > &board)
	{
		char c_found[9];
		for (int i = 0; i<9; ++i)
		{
			memset(c_found, 0, 9);
			for (int j = 0; j<9; ++j)
			{
				if (board[j][i]=='.')
					continue;
				char index = board[j][i] - '1';
				if (c_found[index])
					return false;
				else
					c_found[index] = 1;
			}
		}
		return true;
	}
	bool CheckRows(vector<vector<char> > &board)
	{
		char c_found[9];
		for (int i = 0; i<9; ++i)
		{
			memset(c_found, 0, 9);
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j]=='.')
					continue;
				char index = board[i][j] - '1';
				if (c_found[index])
					return false;
				else
					c_found[index] = 1;
			}
		}
		return true;
	}
	bool CheckCells(vector<vector<char> > &board)
	{
		char c_found[9];
		for (int i = 0; i<9; i+=3)
		{
			for (int j = 0; j<9; j+=3)
			{
				memset(c_found, 0, 9);
				for (int m = 0; m<3; ++m)
				{
					for (int n = 0; n<3; ++n)
					{
						if (board[i+m][j+n]=='.')
							continue;
						char index = board[i+m][j+n] - '1';
						if (c_found[index])
							return false;
						else
							c_found[index] = 1;
					}
				}
			}
		}
		return true;
	}
};