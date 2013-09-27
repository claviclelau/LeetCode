class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty())
            return 0;
        
        int N = matrix.size();
        int M = matrix[0].size();
        vector <int> H(M,0);
        vector <int> L(M,0);
        vector <int> R(M,M);
        int answer = 0;
        for (int i = 0; i<N; i++)
        {
            int left = 0, right = M;
            for (int j = 0; j<M; j++)
            {
                switch(matrix[i][j]){
                case '0':
                    H[j] = 0;
                    L[j] = 0;
                    R[j] = M;
                    left = j+1;
                    break;
                case '1':
                    H[j]++;
                    L[j] = max(left, L[j]);
                    break;
                }
            }
            for (int j = M-1; j>=0; j--)
            {
                switch(matrix[i][j]){
                case '0':
                    right = j;
                    break;
                case '1':
                    R[j] = min(right, R[j]);
                    answer = max(answer, H[j]*(R[j]-L[j]));
                    break;
                }
            }
        }
        return answer;
    }
};