class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size()==1)
        {
            return *(new vector<vector<string> >(1,(*(new vector<string>(1,s)))));
        }
        vector<vector<string>> answer;
        vector<char> v_current(1, 1);
        DFS(s, 0, 0, v_current, answer);
        return answer;
    }
    bool CheckPalindrome(string s, int i_begin, int i_end)
    {
    	if (i_begin>i_end)
			return false;

        while(i_begin<i_end)
        {
            if (s[i_begin]!=s[i_end])
                return false;
                
            ++i_begin;
            --i_end;
        }
        return true;
    }
    void DFS(const string & s, int i_begin, int i_last, vector<char> & v_current, vector<vector<string> > & answer)
    {
        if (i_begin==s.size()-1)
        {
			if (CheckPalindrome(s, i_last, i_begin))
			{
                vector <string> palindromes;
                string palin;
				palin+=s[0];
                for (int i=1; i<v_current.size(); i++)
                {
                    if (v_current[i]==1)
                    {
                        palindromes.push_back(palin);
                        palin.clear();
                    }   
                    palin+=s[i];
                }
                palindromes.push_back(palin);
				answer.push_back(palindromes);
			}
            return;
        }
        v_current.push_back(0);
        DFS(s, i_begin+1, i_last, v_current, answer);
        v_current.pop_back();
        if (CheckPalindrome(s, i_last, i_begin))
        {
            v_current.push_back(1);
            DFS(s, i_begin+1, i_begin+1, v_current, answer);
            v_current.pop_back();
        }
    }
};