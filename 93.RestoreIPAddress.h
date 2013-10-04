class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string ip;
		vector<string> answer;
		DFS_simple(answer, 0, 3, s, ip);
		return answer;
    }
	void DFS (vector<string> & answer, int i_start, int dot_num, const string & s, string & ip)
	{
		if (i_start>=s.size())
			return;
		if (dot_num == 0)
		{
			if (s[i_start]=='0'&&i_start!=s.size()-1)
				return;
			int num = 0;
			for (int i = i_start; i<s.size(); i++)
			{
				num = num*10 + s[i] - '0';
			    if (num>255)
    				return;
			}
			ip += s.substr(i_start, s.size() - i_start);
			answer.push_back(ip);
			return;
		}
		int num = 0;
		int i_size = ip.size();
		for (int i = i_start; i<s.size(); i++)
		{
			if (s[i_start]=='0')
			{
				ip += "0.";
				DFS(answer, i+1, dot_num-1, s, ip);
				ip.resize(i_size);
				break;
			}
			num = num*10 + s[i] - '0';
			if (num<=255)
			{
				ip += s.substr(i_start, i - i_start + 1);
				ip += '.';
				DFS(answer, i+1, dot_num-1, s, ip);
				ip.resize(i_size);
			}
			else
				break;
		}
	}
	void DFS_simple(vector<string> & answer, int i_start, int dot_num, const string & s, string & ip)
	{
		if (dot_num==0)
		{
			if (i_start==s.size())
				answer.push_back(ip);
			return;
		}
		int num = 0;
		if (ip.size()!=0)
			ip += '.', --dot_num;
		int i_size = ip.size();
		for (int i = i_start; i<s.size(); i++)
		{
			num = num*10 + s[i] - '0';
			if (num<=255)
			{
				ip += s.substr(i_start, i - i_start + 1);
				DFS_simple(answer, i+1, dot_num, s, ip);
				ip.resize(i_size);
				if (num==0)
					break;
			}
			else
				break;
		}
	}
};