/****************************************************************
http://leetcode.com/onlinejudge#question_131

Update: 
1. Rewrite a neat one on 2013/09/27.
****************************************************************/

class Solution {
public:
	vector<vector<string> > partition(string s) {
		return partition_2(s);
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
	/****************************************************************
	                 Version 1. Not neat.
	****************************************************************/
    vector<vector<string> > partition_1(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size()==1)
        {
            return *(new vector<vector<string> >(1,(*(new vector<string>(1,s)))));
        }
        vector<vector<string>> answer;
        vector<char> v_current(1, 1);
        DFS_1(s, 0, 0, v_current, answer);
        return answer;
    }
    void DFS_1(const string & s, int i_begin, int i_last, vector<char> & v_current, vector<vector<string> > & answer)
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
        DFS_1(s, i_begin+1, i_last, v_current, answer);
        v_current.pop_back();
        if (CheckPalindrome(s, i_last, i_begin))
        {
            v_current.push_back(1);
            DFS_1(s, i_begin+1, i_begin+1, v_current, answer);
            v_current.pop_back();
        }
    }
	/****************************************************************
	        Version 2. Rewrite one after consult others' code.
	****************************************************************/
	vector<vector<string> > partition_2(string s) {
		vector <vector<string> > answer;
		if (s.empty())
		{
			answer.resize(1);
			return answer;
		}
		vector <string> partition;
		DFS_2(s, partition, answer, 0);
		return answer;
	}
	void DFS_2(const string & s, vector<string> & partition, vector<vector<string> > & answer, int i_begin)
	{
		if (i_begin==s.size())
		{
			answer.push_back(partition);
			return;
		}
		
		for (int i = i_begin; i<s.size(); i++)
		{
			if (CheckPalindrome(s, i_begin, i))
			{
				partition.push_back(s.substr(i_begin, i-i_begin+1));
				DFS_2(s, partition, answer, i+1);
				partition.pop_back();
			}
		}
	}
};