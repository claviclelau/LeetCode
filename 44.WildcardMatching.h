class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return isMatchGreedy(s, p);
    }
	//Simple recursive way. Time limit exceeded.
	bool isMatchRe(const char *s, const char *p)
	{
		if (!s&&!p)
			return true;
		if (!s||!p)
			return false;
		if (*s=='\0'&&*p=='\0')
			return true;
		if (*p == '*')
		{
			while (1)
			{
				if (*(p+1)=='*')
				{
					++p;
					continue;
				}
				if (isMatchRe(s, p+1))
					return true;
				if (*s=='\0')
					break;
				++s;
			}
			return false;
		}
		else if (*p == '?')
		{
			if (*s == '\0')
				return false;
			return isMatchRe(s+1, p+1);
		}
		else
		{
			return *s==*p? isMatchRe(s+1, p+1):false;
		}
	}
	//DP. Time limit exceeded.
	bool isMatchDP(const char * s, const char * p)
	{
		int p_length = strlen(p);
		int s_length = strlen(s);
		char * DP[2];
		DP[0] = new char [s_length+1];
		DP[1] = new char [s_length+1];
		DP[0][s_length] = 1;
		DP[1][s_length] = 1;
		for (int i = p_length - 1; i>=0; --i)
		{
			memset(DP[(i+1)%2], 0, sizeof(char)*(s_length+1));
			if (p[i]=='*')
			{
				for (int j = s_length; j>=0; --j)
					if (DP[i%2][j])
						for (; j>=0; --j)
							DP[(i+1)%2][j] = 1;
			}
			else
			{
				for (int j = s_length - 1; j>=0; --j)
					DP[(i+1)%2][j] = (p[i]==s[j]||p[i]=='?')&&DP[i%2][j+1];
			}
		}
		return DP[0][0];
	}
	//Greedy. Frome AnnieKim
	bool isMatchGreedy(const char * s, const char * p)
	{
		const char * sbackup = NULL, * pbackup = NULL;
		while (*s!='\0')
		{
			if (*p==*s||*p=='?')
				s++, p++;
			else if (*p=='*')
			{
				while (*p=='*') p++;
				if (*p=='\0') return true;
				sbackup = s;
				pbackup = p;
			}
			else
			{
				if (sbackup==NULL) return false;
				s = ++sbackup;
				p = pbackup;
			}
		}
		while (*p=='*') p++;
		return *p == '\0';
	}
};