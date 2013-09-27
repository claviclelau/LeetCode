class Solution {
public:
    vector<vector<int> > Triangle;
    Solution()
    {
        vector <int> v_first;
        v_first.push_back(1);
        Triangle.push_back(v_first);
    }
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer;
        if (numRows<=Triangle.size())
        {
            for (int i = 0; i<numRows; i++)
                answer.push_back(Triangle[i]);
                
            return answer;
        }
        
        vector<int> temp_vector;
        for (int i = Triangle.size(); i<numRows; i++)
        {
            temp_vector.clear();
            temp_vector.push_back(1);
            for (int j = 1; j<Triangle[i-1].size(); j++)
            {
                temp_vector.push_back(Triangle[i-1][j]+Triangle[i-1][j-1]);
            }
            temp_vector.push_back(1);
            Triangle.push_back(temp_vector);
        }
        for (int i = 0; i<numRows; i++)
            answer.push_back(Triangle[i]);
            
        return answer;
    }
};