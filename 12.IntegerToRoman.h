class Solution {
public:
	const string roman[4][10] = {
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
	};
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        string answer;
		int i = 1000;
		int digit = 3;
		while(num>0)
		{
			answer += roman[digit][num/i];
			num %= i;
			i /= 10;
			--digit;
		}
		return answer;
    }
};