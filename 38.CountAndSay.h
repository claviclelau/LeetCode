class Solution {
public:
	vector <string> v_saynumber;
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n<=v_saynumber.size())
			return v_saynumber[n-1];
		if (v_saynumber.size()==0)
			v_saynumber.push_back("1");

		for (int i = v_saynumber.size(); i<n; ++i)
		{
			string s = v_saynumber.back();
			stringstream sstr;
			int i_count = 1;
			for (int j = 0; j<s.size(); j++)
			{
				while (j<s.size()-1&&s[j]==s[j+1])
					++i_count, ++j;
				sstr<<i_count;
				sstr<<s[j];
				i_count = 1;
			}
			v_saynumber.push_back(sstr.str());
		}
		return v_saynumber[n-1];
    }
};