class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return isPalindrome_1(x);
    }
	bool isPalindrome_1(int x)
	{
		if (x<0)
			return false;
		int d = 1;
		while (x/d>=10) d*=10;
		while (d>1)
		{
			if (x/d!=x%10)
				return false;
			x %= d;
			x /= 10;
			d /= 100;
		}
		return true;
	}
	bool isPalindrome_2(int x)
	{
		if (x<0)
			return false;
		int reverse_x = 0;
		int temp = x;
		while(temp)
		{
			reverse_x *= 10;
			reverse_x += temp%10;
			temp /= 10;
		}
		return reverse_x == x;
	}
	bool isPalindrome_3(int x)
	{
		return isPalindromeRe(x, x);
	}
	//This is a little hard to understand.
	bool isPalindromeRe(int x, int & y)
	{
		if (x<0) return false;
		if (x==0) return true;
		if (isPalindromeRe(x/10, y) && x%10==y%10)
		{
			y /= 10;
			return true;
		}
		return false;
	}
};