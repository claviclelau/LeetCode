class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<=1)
            return true;
        char * c_visited = new char[n];
        memset(c_visited, 0, n*sizeof(char));
        if (DFS(A, n, c_visited, 0))
        {
            delete [] c_visited;
            return true;
        }
        else
        {
            delete [] c_visited;
            return false;
        }
    }
    bool DFS(int A[], int n, char * c_visited, int i_visit)
    {
        c_visited[i_visit] = 1;
        for (int i = A[i_visit]; i>=1; i--)
        {
            int i_new_visit = i_visit + i;
            
            if (i_new_visit>=n-1)
                return true;
            
            if (c_visited[i_new_visit])
                continue;
                
            if (DFS(A, n, c_visited, i_new_visit))
                return true;
        }
        return false;
    }
};