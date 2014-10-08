class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> answer;
        if (!wordBreakDPNonRe(s, dict))
            return answer;

        string sentence;
        wordBreakIIRe(s, 0, dict, sentence, answer);
        return answer;
    }
    void wordBreakIIRe(const string & s, int start, unordered_set<string> & dict, string & sentence, vector <string> & answer)
    {
        if (start == s.size())
        {
            answer.push_back(sentence);
            return;
        }
        string sentence_copy(sentence);
        for (int i = start + 1; i <= s.size(); ++i)
        {
            if (dict.find(s.substr(start, i - start))!=dict.end())
            {
                if (sentence.size() != 0)
                {
                    sentence += " ";
                }
                sentence += s.substr(start, i - start);
                wordBreakIIRe(s, i, dict, sentence, answer);
                sentence = sentence_copy;
            }
        }
    }
    bool wordBreakDPNonRe(const string & s, unordered_set<string> & dict)
    {
        int N = s.size();
        vector <bool> DP(N+1, false);
        DP[0] = true;

        for (int i = 1; i <= N; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (DP[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    DP[i] = true;
                    break;
                }
            }
        }
        return DP[N];
    }
};