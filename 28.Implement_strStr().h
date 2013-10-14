class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return strStrKMP(haystack, needle);
    }
	//From AnnieKim's code.
	char *strStrNonKMP(char * haystack, char * needle)
	{
		while (true)
		{
			char * h = haystack, *n = needle;
			while(*n!='\0'&& *h == *n)
			{
				++h;
				++n;
			}
			if (*n=='\0') return haystack;
			if (*h=='\0') return NULL;
			haystack++;
		}
	}
	//KMP
	char * strStrKMP(char * haystack, char * needle)
	{
		int N = strlen(needle);
		int H = strlen(haystack);
		if (N==0)
			return haystack;
		int * feature = new int [N];
		feature[0] = 0;
		for (int i = 1; i<N; i++)
		{
			int k = feature[i-1];
			while (k>0&&needle[i]!=needle[k])
				k = feature[k-1];
			if (needle[i]==needle[k])
				feature[i] = k + 1;
			else
				feature[i] = 0;
		}
		int i_n = 0;
		for (int i = 0; i<H; i++)
		{
			while(needle[i_n]!=haystack[i]&&i_n>0)
				i_n = feature[i_n-1];
			if (needle[i_n]==haystack[i])
				++i_n;
			if (i_n==N)
				return haystack + i - N + 1;
		}
		return NULL;
	}
};