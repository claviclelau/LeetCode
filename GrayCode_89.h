class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <int> result;
        if (n<0)
            return result;
            
        result.push_back(0);
        int add = 1;
        while (n)
        {
            int add_size = result.size()<add?result.size():add;
            
            for (int i = result.size()-1, j = 0; j<add_size; i--, j++)
                result.push_back(result[i]+add);
            
            add<<=1;
            n--;
        }
        return result;
    }
};