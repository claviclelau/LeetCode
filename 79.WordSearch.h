class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.size()==0)
            return true;
        
        if (word.size()==1)
        {
            for (int i = 0; i<board.size(); i++)
            {
                for (int j = 0; j<board[i].size(); j++)
                {
                    if (board[i][j]==word[0])
                        return true;
                }
            }
            return false;
        }
        
        vector<vector<char> > visited(board.size());
        for (int i = 0; i<visited.size(); i++)
        {
            visited[i].resize(board[i].size(), 0);
        }
        for (int i = 0; i<board.size(); i++)
        {
            for (int j = 0; j<board[i].size(); j++)
            {
                if (board[i][j]==word[0]&&DFS(board, visited, i, j, word, 1))
                    return true;
            }
        }
        return false;
    }
    bool DFS (vector<vector<char> > & board, vector<vector<char> > & visited, int row, int col, const string & word, int i_word)
    {
        visited[row][col] = 1;
        if (row!=0&&!visited[row-1][col])
        {
            if (board[row-1][col]==word[i_word])
            {
                if (i_word==word.size()-1)
                    return true;
                else if (DFS(board, visited, row-1, col, word, i_word+1))
                    return true;
            }
                
        }
        if (row<visited.size()-1&&!visited[row+1][col])
        {
            if (board[row+1][col]==word[i_word])
            {
                if (i_word==word.size()-1)
                    return true;
                else if (DFS(board, visited, row+1, col, word, i_word+1))
                    return true;
            }
        }
        if (col!=0&&!visited[row][col-1])
        {
            if (board[row][col-1]==word[i_word])
            {
                if (i_word==word.size()-1)
                    return true;
                else if (DFS(board, visited, row, col-1, word, i_word+1))
                    return true;
            }
        }
        if (col<visited[row].size()-1&&!visited[row][col+1])
        {
            if (board[row][col+1]==word[i_word])
            {
                if (i_word==word.size()-1)
                    return true;
                else if (DFS(board, visited, row, col+1, word, i_word+1))
                    return true;
            }
        }
        
        visited[row][col] = 0;
        return false;
    }
};