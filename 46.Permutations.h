class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer;
        if (num.size()==0)
            return answer;
        permuteUniqueRecursive(num, answer, 0);
    }
    void permuteUniqueRecursive(vector<int> & num, vector<vector<int> > & answer, int n)
    {
        if (n == num.size()-1)
        {
            answer.push_back(num);
            return;
        }
        
        for (int i = n; i<num.size(); i++)
        {
                
            int i_temp = num[n];
            num[n] = num[i];
            num[i] = i_temp;
            
            permuteUniqueRecursive(num, answer, n+1);
            
            i_temp = num[n];
            num[n] = num[i];
            num[i] = i_temp;
        }
    }
};