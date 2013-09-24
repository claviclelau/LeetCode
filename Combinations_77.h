class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector <int> > answer;
        combineRe(n, k, answer);
        return answer;
    }
    void combineRe(int n, int k, vector< vector<int> > & answer)
    {
        if (n<k)
            return;
    	if (k==1)
		{
			int i_size = answer.size()-1;
			answer.resize(answer.size()+n);
			for (int i = 1; i<=n; i++)
				answer[i_size+i].push_back(i);
			return;
		}
        if (n==k)
        {
            answer.resize(answer.size()+1);
            for (int i = 1; i<=n; i++)
                answer[answer.size()-1].push_back(i);
                
            return;
        }
                
        for (int i = n; i>=k; i--)
        {
            int i_size = answer.size();
            combineRe(i-1, k-1, answer);
            for (int j = answer.size()-1; j>=i_size; j--)
                answer[j].push_back(i);
        }
    }
};