class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i_forward = 0, i_backward = s.size() - 1;
        while(i_forward<i_backward&&i_forward<s.size()&&i_backward>0)
        {
            while(!((s[i_forward]>='a'&&s[i_forward]<='z')||(s[i_forward]>='A'&&s[i_forward]<='Z')||(s[i_forward]>='0'&&s[i_forward]<='9'))&&i_forward<i_backward)
                ++i_forward;
                
            while(!((s[i_backward]>='a'&&s[i_backward]<='z')||(s[i_backward]>='A'&&s[i_backward]<='Z')||(s[i_backward]>='0'&&s[i_backward]<='9'))&&i_backward>i_forward)
                --i_backward;
                
            if (s[i_backward]>='a'&&s[i_backward]<='z')
                s[i_backward]-=32;
                
            if (s[i_forward]>='a'&&s[i_forward]<='z')
                s[i_forward]-=32;
                
            if (s[i_backward]!=s[i_forward])
                return false;
                
            ++i_forward;
            --i_backward;
        }
        return true;
    }
};