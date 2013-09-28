/******************************************************************************
This one is associated with LeetCode Problem 132: Palindrome Partitioning II
******************************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = s.size();
        int * dp = new int [N];
        int i_length = 1;
        int i_begin = 0, i_end = 0;
        for (int i = 1; i<N; i++)
        {
            dp[i] = true;
            for (int j = 0; j<i; j++)
            {
                dp[j] = s[i]==s[j]?dp[j+1]:false;
                if (dp[j]&&i-j+1>i_length)
                {
                    i_length = i-j+1;
                    i_begin = j;
                    i_end = i;
                }
            }
        }
        delete [] dp;
        return s.substr(i_begin, i_length);
    }
};