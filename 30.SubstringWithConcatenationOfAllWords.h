class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <int> answer;
		if (S.empty()||L.empty()) return answer;
		int M = S.size(), N = L.size();
		int K = L[0].size();
		unordered_map<string, int> need;
		unordered_map<string, int> found;
		unordered_map<string, int>::iterator iter;
		for (int i = 0; i<N; ++i)
			need[L[i]]++;
		for (int i = 0; i<=M - N*K; ++i)
		{
			found.clear();
			int j;
			for (j = 0; j<N; ++j)
			{
				string s = S.substr(i+K*j, K);
				iter = need.find(s);
				if (iter==need.end())
					break;
				if (iter->second <= found[s])
					break;
				found[s]++;
			}
			if (j==N) answer.push_back(i);
		}
		return answer;
    }
};