class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		vector<string> answer;
		if (!wordBreakPossible(s, dict)) return answer;
		string sentence;
		wordBreakRe(s, dict, 0, answer, sentence);
		return answer;
    }
	//Time limit exceeded. Check the possibility before search for the answer then it will pass.
	void wordBreakRe(const string & s, unordered_set<string> &dict, int i_start, vector<string> & answer, string & sentence)
	{
		if (i_start==s.size())
		{
			answer.push_back(sentence);
			return;
		}
		int i_length = s.size();
		int i_size = sentence.size();
		string s_sub;
		for (int i = i_start + 1; i<=i_length; ++i)
		{
			s_sub = s.substr(i_start, i - i_start);
			
			if (dict.find(s_sub)!=dict.end())
			{
				if (sentence.size()!=0)
					sentence += " ";
				sentence += s_sub;
				wordBreakRe(s, dict, i, answer, sentence);
				sentence.resize(i_size);
			}
		}
	}
	//Bottom-up scheme for problem Word Break.
	bool wordBreakPossible(const string &s, const unordered_set<string> &dict) {
        int N = s.size();
        bool canBreak[N+1];
        memset(canBreak, false, sizeof(canBreak));
        canBreak[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[N];
    }
};