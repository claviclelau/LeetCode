class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i_size = digits.size();
		for (int i = i_size - 1; i >= 0; --i)
		{
			if (digits[i] != 9)
			{
				digits[i] += 1;
				return digits;
			}
			else
				digits[i] = 0;
		}
		digits.resize(i_size + 1);
		for (int i = i_size; i > 0; --i)
			digits[i] = digits[i-1];

		digits[0] = 1;
		vector <int> answer(digits);
		return answer;			//You cannot return digits directly. Because it is not declared in this scope.
    }
};