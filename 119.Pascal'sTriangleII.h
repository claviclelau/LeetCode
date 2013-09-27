class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
           
        vector<int> v_rows[2];
        int i_current = 0;
        int i_next = 0;
        v_rows[0].push_back(1);
        for (int i = 0; i<rowIndex; i++)
        {
            i_next = (i_current+1)& 1;
            v_rows[i_next].resize(v_rows[i_current].size());
            v_rows[i_next][0] = 1;
            for (int j = 1; j<v_rows[i_current].size(); j++)
            {
                v_rows[i_next][j] = v_rows[i_current][j] + v_rows[i_current][j-1];
            }
            v_rows[i_next].push_back(1);
            i_current = (++i_current) & 1;
        }
        return v_rows[i_current];
    }
};