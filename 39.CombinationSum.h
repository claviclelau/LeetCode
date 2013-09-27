class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > answer;
        vector<int> combination;
        DFS(answer, combination, 0, candidates, target, 0);
        return answer;
    }
    void DFS(vector<vector<int> > & answer, vector<int> & combination, int sum, vector<int> & candidates, int target, int order)
    {
        for (int i = order; i<candidates.size(); i++)
        {
            int temp_sum = sum + candidates[i];
            if (temp_sum == target)
            {
                answer.push_back(combination);
                answer[answer.size()-1].push_back(candidates[i]);
            }
            else if (temp_sum < target)
            {
                combination.push_back(candidates[i]);
                DFS(answer, combination, temp_sum, candidates, target, i);
                combination.pop_back();
            }
        }
    }
};