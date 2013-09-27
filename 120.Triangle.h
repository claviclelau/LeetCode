//1. Use O(n^2) space.
//2. Use O(n) space.
class Solution {
public:
	int minimumTotal_1(vector<vector<int> > &triangle) {
		return minimumTotal_2(triangle);
	}
    int minimumTotal_1(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size()==0)
            return 0;
        if (triangle.size()==1)
            return triangle[0][0];
            
        vector<vector<int> > pathSumTriangle (triangle);
        int i_minimum = 0;
        for (int i = 1; i<triangle.size(); i++)
        {
            for (int j = 0; j<triangle[i].size(); j++)
            {
                int i_left = j==0?0x7FFFFFFF:pathSumTriangle[i-1][j-1];
                int i_right = (j==pathSumTriangle[i].size()-1)?0x7FFFFFFF:pathSumTriangle[i-1][j];
                pathSumTriangle[i][j] += i_left<i_right?i_left:i_right;
                if (i==triangle.size()-1)
                {
                    if (j==0)
                        i_minimum = pathSumTriangle[i][j];
                    else
                        i_minimum = i_minimum<pathSumTriangle[i][j]?i_minimum:pathSumTriangle[i][j];
                }
            }
        }
        return i_minimum;
    }
	
	int minimumTotal_2(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size()==0)
            return 0;
        if (triangle.size()==1)
            return triangle[0][0];
            
        vector<int> pathSumTriangle (triangle.back());
        int i_minimum = 0;
        pathSumTriangle[0] = triangle[0][0];
        for (int i = 1; i<triangle.size(); i++)
        {
            pathSumTriangle[i] = pathSumTriangle[i-1] + triangle[i][i];
            i_minimum = pathSumTriangle[i];
            for (int j = i - 1; j>0; --j)
            {
                pathSumTriangle[j] = (pathSumTriangle[j]<pathSumTriangle[j-1]?pathSumTriangle[j]:pathSumTriangle[j-1]) + triangle[i][j];
                if (i==triangle.size()-1)
                {
                    i_minimum = i_minimum<pathSumTriangle[j]?i_minimum:pathSumTriangle[j];
                }
            }
            pathSumTriangle[0] += triangle[i][0];
            i_minimum = i_minimum<pathSumTriangle[0]?i_minimum:pathSumTriangle[0];
        }
        return i_minimum;
    }
};
