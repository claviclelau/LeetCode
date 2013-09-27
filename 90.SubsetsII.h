class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector <vector <int> > answer;
        answer.resize(1);
        for (int i = 0; i<S.size(); i++)
        {
            int i_count = 1;
            while(i<S.size()-1&&S[i]==S[i+1])
                ++i_count, ++i;
            
            int i_size = answer.size();
            for (int j = 0; j<i_count; j++)
            {
                for (int k = 0; k<i_size; k++)
                {
                    answer.push_back(answer[j*i_size+k]);
                    answer[answer.size()-1].push_back(S[i]);
                } 
            }
        }
        return answer;
    }
};