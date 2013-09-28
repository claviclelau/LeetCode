/***********************************************************************
Problem: http://leetcode.com/onlinejudge#question_132

Notes: Using DP. 

Code source: https://github.com/AnnieKim/LeetCode/blob/master/PalindromePartitioningII.h
***********************************************************************/
class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = s.size();
        bool * isP = new bool [N];
        int * dp = new int [N];
        dp[0] = 0;
        for (int i = 1; i<N; i++)
        {
            isP[i] = true;
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j<i; j++)
            {
                isP[j] = s[j]==s[i]?isP[j+1]:false;// isP[j] == true   -> [j...i] is a palindrome
                                                   // isP[j+1] == true -> [j+1...i-1] is a palindrome
                
                if (isP[j])
                    dp[i] = j==0?0:min(dp[i], dp[j-1] + 1);// dp[i] -> minCount for [0...i]
            }
        }
        int answer = dp[N-1];
        delete [] isP;
        delete [] dp;
        return answer;
    }
};