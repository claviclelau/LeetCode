class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size()==0)
        {   
            return string("");
        }
        return longestCommonPrefixBinaryDivide(strs, 0, strs.size()-1);
    }
    string longestCommonPrefixBinaryDivide(vector<string> & strs, int i_begin, int i_end)
    {
        if (i_begin==i_end)
            return strs[i_begin];
        
        if (i_begin==(i_end - 1))
        {
            int i = 0;
            while (i<strs[i_begin].size()&&i<strs[i_end].size()&&strs[i_begin][i]==strs[i_end][i])
            {
                ++i;
            }
            return string(strs[i_begin].substr(0, i));
        }
        
        string str1(longestCommonPrefixBinaryDivide(strs, i_begin, (i_begin+i_end)/2));
        string str2(longestCommonPrefixBinaryDivide(strs, (i_begin+i_end)/2+1, i_end));
        int i = 0;
        while (i<str1.size()&&i<str2.size()&&str1[i]==str2[i])
        {
            ++i;
        }
//        string answer(str1.substr(0, i));
        return string(str1.substr(0, i));
    }
};