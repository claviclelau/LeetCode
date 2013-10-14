class Solution {
public:
    int totalNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string row(n, '.');
		vector<string> board(n, row);
		vector<vector<string> > answer;
		solveNQueensRe_2(n, answer, board, 0, 0);
		return answer.size();
    }
	//Time limit exceeded, when n equals 12.
	void solveNQueensRe_2(int n, vector< vector<string> > & answer, vector<string> & board, int i_row, int i_queen_left)
	{
		if (i_queen_left==n)
		{
			answer.push_back(board);
			return;
		}
		if (i_row==n)
			return;
		for (int i = 0; i<n; i++)
		{
			if (CheckPossibility(board, i_row*n + i, n))
			{
				board[i_row][i] = 'Q';
				solveNQueensRe_2(n, answer, board, i_row + 1, i_queen_left + 1);
				board[i_row][i] = '.';
			}
		}
	}
	bool CheckPossibility(vector<string> & board, int i_position, int n)
	{
		int i_row = i_position/n, i_col = i_position%n;
		for (int i = 0; i<n; ++i)
		{
			if (board[i][i_col]=='Q'||board[i_row][i]=='Q')
				return false;
		}
		int i_min = min(i_row, i_col), i_max = max(i_row, i_col);
		i_max = n - i_max;
		for (int i = -i_min; i<i_max; i++)
		{
			if (board[i_row+i][i_col+i]=='Q')
				return false;
		}
		i_max = i_row + i_col;
		i_min = min(i_max+1, n);
		for (int i = 0; i<i_min; ++i)
		{
			if (i_max - i >= n)
				continue;
			if (board[i][i_max-i]=='Q')
				return false;
		}
		return true;
	}
};