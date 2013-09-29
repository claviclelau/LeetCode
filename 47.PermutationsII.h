class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> permute;
		vector<bool> avali(num.size(), true);
		vector<vector<int> > answer;
		sort(num.begin(), num.end());
		permute.clear();
		permuteDuplicatesRe(num, permute, avali, answer);
		return answer;
    }
    void permuteDuplicatesRe(vector<int> & num, vector<int> & permute, vector<bool> & avali, vector<vector<int> > & answer)
	{
		if (num.size()==permute.size())
		{
			answer.push_back(permute);
			return;
		}
		
		int i_last_index = -1;
		for (int i = 0; i<num.size(); i++)
		{
			if (!avali[i]) continue;
			if (i_last_index!=-1&&num[i]==num[i_last_index]) continue;
			avali[i] = false;
			permute.push_back(num[i]);
			permuteDuplicatesRe(num, permute, avali, answer);
			permute.pop_back();
			avali[i] = true;
			i_last_index = i;
		}
	}
};