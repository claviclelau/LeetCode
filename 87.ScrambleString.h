class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.size()!=s2.size())
			return false;
		
		return isScrambleRe(s1, s2);
    }
	bool isScrambleRe(string s1, string s2)
	{
		if (s1==s2)
			return true;
		if (s1.size()==1)
			return false;
		string ss1 = s1, ss2 = s2;
		//This is crucial. Without it, time limit exceeded.
		sort(ss1.begin(), ss1.end());
		sort(ss2.begin(), ss2.end());
		if (ss1!=ss2)
			return false;
		int N = s1.size();
		for (int i = 1; i<N; i++)
		{
			if (isScrambleRe(s1.substr(0, i), s2.substr(0, i))&&isScrambleRe(s1.substr(i, N-i), s2.substr(i, N-i))||
				isScrambleRe(s1.substr(0, i), s2.substr(N-i, i))&&isScrambleRe(s1.substr(i, N-i), s2.substr(0, N-i)))
				return true;
		}
		return false;
	}
};