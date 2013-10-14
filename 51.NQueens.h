class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string row(n, '.');
		vector<string> board(n, row);
		vector<vector<string> > answer;
		solveNQueenNonReWithBit(n, answer);
		return answer;
    }
	//Time limit exceeded.
	void solveNQueensRe(int n, vector< vector<string> > & answer, vector<string> & board, int i_position, int i_queen_left)
	{
		int final_position = n*n;
		if (i_queen_left==n)
		{
			answer.push_back(board);
			return;
		}
		if (i_position>=final_position)
			return;
			
		for (int i = i_position; i<final_position; ++i)
		{
			int i_row = i/n, i_col = i%n;
			if (board[i_row][i_col]=='.'&&CheckPossibility(board, i, n))
			{
				board[i_row][i_col] = 'Q';
				solveNQueensRe(n, answer, board, i + 1, i_queen_left + 1);
				board[i_row][i_col] = '.';
			}
		}
	}
	//Pass.
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
	//Backtracking
	void solveNQueenNonReWithBit(int n, vector< vector<string> > & answer)
	{
		string row(n, '.');
		vector<string> board(n, row);
		int i_chess_num = n - 1;
		int * i_place = new int[n];
		memset(i_place, 255, sizeof(int)*n);
		while(i_chess_num < n)
		{
			if (i_chess_num == -1)
			{
				answer.push_back(board);
				++i_chess_num;
				continue;
			}
			int i;
			if (i_place[i_chess_num] != -1)
			{
				i = i_place[i_chess_num] + 1;
				board[i_chess_num][i_place[i_chess_num]] = '.';
			}
			else
				i = 0;
			for (; i<n; ++i)
			{
				if (CheckPossibility(board, i_chess_num*n+i, n))
				{
					board[i_chess_num][i] = 'Q';
					i_place[i_chess_num] = i;
					--i_chess_num;
					break;
				}	
			}
			if (i==n)
			{
				i_place[i_chess_num] = -1;
				++i_chess_num;
			}
		}
		delete [] i_place;
	}
	//Permutations
	void solveNQueenPermutation()
	{
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