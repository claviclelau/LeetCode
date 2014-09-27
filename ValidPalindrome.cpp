class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0)
            return true;
        
        int iNumber = 'A' - 'a';
        int a = 0;
        int b = s.size() - 1;
        while (a < b)
        {
            while(a < b && !isAlphaNumeric(s[a]))
                ++a;
            while(a < b && !isAlphaNumeric(s[b]))
                --b;
            
            char sa = (s[a] >= 'A' && s[a] <= 'Z') ? s[a] - iNumber : s[a];
            char sb = (s[b] >= 'A' && s[b] <= 'Z') ? s[b] - iNumber : s[b];
            
            if (sa != sb)
                return false;
            
            ++a;
            --b;
        }
        return true;
    }
    bool inline isAlphaNumeric(char myChar)
    {
        return (myChar >= 'A' && myChar <= 'Z') || (myChar >= 'a' && myChar <= 'z') || (myChar >= '0' && myChar <= '9');
    }
};