class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer(1);
        vector<int> S_replace(S);
        sort(S_replace.begin(), S_replace.end());
        if (S.size()==0)
            return answer;
            
        for (int i = 0; i<S_replace.size(); i++)
        {
            int temp_size = answer.size();
            for(int j = 0; j<temp_size; j++)
                answer.push_back(answer[j]);
                
            for(int j = temp_size; j<answer.size(); j++)
                answer[j].push_back(S_replace[i]);
        }
        return answer;
    }
};