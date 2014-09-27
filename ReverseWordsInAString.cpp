class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0)
            return;
        string sCopy(s);
        int a = sCopy.size() - 1;
        int b = a;
        int n = 0;
        s.resize(s.size() + 1);
        while(1)
        {
            findNextWord(sCopy, a, b);
            if (a < 0)
                break;
            for (int i = b + 1; i <= a; ++i, ++n)
                s[n] = sCopy[i];
            
            s[n++] = ' ';
            
            if (b < 0)
                break;
            
            a = b;
        }
        s.resize(n-1 > 0 ? n-1 : 0);
    }
    void findNextWord(string & s, int &a, int &b)
    {
        while (a>=0 && s[a]==' ')
            --a;
        if (a == 0 && s[0] == ' ')
            --a;
        b = a;
        while (b >= 0 && s[b]!=' ')
            --b;
    }
};