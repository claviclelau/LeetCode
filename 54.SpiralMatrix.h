class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector <int> answer;
		int N = matrix.size();
		if (N==0)
			return answer;
		
		int M = matrix[0].size(), i_step = M, i_col = -1, i_row = 0, move = 0;
		while (N>0&&M>0)
		{	
			for (int j = i_step; j>0; --j)
			{
				switch (move)
				{
				case 0:
					++i_col;
					answer.push_back(matrix[i_row][i_col]);
					break;
				case 1:
					++i_row;
					answer.push_back(matrix[i_row][i_col]);
					break;
				case 2:
					--i_col;
					answer.push_back(matrix[i_row][i_col]);
					break;
				case 3:
					--i_row;
					answer.push_back(matrix[i_row][i_col]);
					break;
				}
			}
			switch(move)
			{
			case 0:
			case 2:
				i_step = --N;
				break;
			case 1:
			case 3:
				i_step = --M;
			}
			move = (move+1)%4;
		}
		return answer;
    }
};