class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty())
            return;
        int M = board.size();
        int N = board[0].size();
        for (int i = 0; i<M; ++i)
        {
            if (board[i][0]=='O')
                BFS(i, 0, board);
            if (board[i][N-1]=='O')
                BFS(i, N-1, board);
        }
        for (int i = 0; i<N; ++i)
        {
            if (board[0][i]=='O')
                BFS(0, i, board);
            if (board[M-1][i]=='O')
                BFS(M-1, i, board);
        }
        for (int i = 0; i<M; i++)
        {
            for (int j = 0; j<N; j++)
            {
                switch(board[i][j]){
                case 'S':
                    board[i][j] = 'O';
                    break;
                case 'O':
                    board[i][j] = 'X';
                    break;
                }
            }
        }
    }
    void DFS(int i, int j, vector<vector<char>> &board)
    {
        board[i][j] = 'S';
        if (i>0&&board[i-1][j]=='O')
            DFS(i-1, j, board);
        if (j>0&&board[i][j-1]=='O')
            DFS(i, j-1, board);
        if (j<board[0].size()-1&&board[i][j+1]=='O')
            DFS(i, j+1, board);
        if (i<board.size()-1&&board[i+1][j]=='O')
            DFS(i+1, j, board);
    }
    void BFS(int i, int j, vector<vector<char>> &board)
    {
        int N = board[0].size();
        queue<int> my_queue;
        my_queue.push(i*N + j);
        board[i][j] = 'S';
        while (!my_queue.empty())
        {
            int index = my_queue.front();
            my_queue.pop();
            i = index/N, j= index%N;
            if (i>0&&board[i-1][j]=='O')
            {
                board[i-1][j] = 'S';//This is necessary.
                my_queue.push((i-1)*N + j);
            }
            if (j>0&&board[i][j-1]=='O')
            {
                board[i][j-1] = 'S';
                my_queue.push(i*N + j - 1);
            }
            if (j<board[0].size()-1&&board[i][j+1]=='O')
            {
                board[i][j+1] = 'S';
                my_queue.push(i*N + j + 1);
            }
            if (i<board.size()-1&&board[i+1][j]=='O')
            {
                board[i+1][j] = 'S';
                my_queue.push((i+1)*N + j);
            }
        }
    }
};