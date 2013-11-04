class Solution {
public:
	//From AnnieKim
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<char, int> roman;
		roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;
		int answer = 0;
		int N = s.size();
		for (int i = 0; i<N; ++i)
		{
			if (i<N-1 && roman[s[i]]<roman[s[i+1]])
				answer -= roman[s[i]];
			else
				answer += roman[s[i]];
		}
		return answer;
    }
};