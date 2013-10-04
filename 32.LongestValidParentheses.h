class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return longestValidParentheses_2(s);
    }
	//Algorithm from GitHub of AnnieKim
	int longestValidParentheses_1(string s)
	{
		stack <int> stk;
		int count = 0;
		int answer = 0;
		for (int i = 0; i<s.size(); i++)
		{
			switch (s[i]){
			case '(':
				stk.push(count);
				count = 0;
				break;
			case ')':
				if (stk.empty())
					count = 0;
				else
				{
					count += (1 + stk.top());
					stk.pop();
					answer = max(answer, count);
				}
				break;
			}
		}
		return answer*2;
	}
	
	int longestValidParentheses_2(string s)
	{
		stack <int> stk;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i]=='(')
				stk.push(i);
			else if (!stk.empty())
			{
				s[stk.top()] = '*';
				s[i] = '*';
				stk.pop();
			}
		}
		int answer = 0, i_consecutive = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '*')
				++i_consecutive;
			else
			{
				answer = max(answer, i_consecutive);
				i_consecutive = 0;
			}
		}
		answer = max(answer, i_consecutive);
		return answer;
	}
};