class Solution {
public:
	//From AnnieKim's code.
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!str) return 0;
		while (*str==' ')  str++;
		bool positive = true;
		if (*str=='+'||*str=='-')
		{
			positive = *str == '+';
			str++;
		}
		long long answer = 0;
		while(*str>='0'&&*str<='9')
		{
			answer = answer * 10 + (*str - '0');
			str++;
		}
		answer = positive ? answer : -answer;
		if (answer > INT_MAX) return INT_MAX;
		if (answer < INT_MIN) return INT_MIN;
		return (int) answer;
    }
};