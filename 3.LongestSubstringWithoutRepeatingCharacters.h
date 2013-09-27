class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i_max_length = 0, i_max_length_from_end = 0;
        int p_last_index[26];
        memset(p_last_index, 0xFF, sizeof(int)*26);
        for (int i = 0; i<s.size(); i++)
        {
            if (p_last_index[s[i]-'a']==-1||(i-p_last_index[s[i]-'a'])>i_max_length_from_end)
            {
                p_last_index[s[i]-'a'] = i;
                i_max_length_from_end++;
                i_max_length = i_max_length>i_max_length_from_end?i_max_length:i_max_length_from_end;
            }
            else
            {
                i_max_length_from_end = i - p_last_index[s[i]-'a'];
                p_last_index[s[i]-'a'] = i;
            }   
        }
        return i_max_length;
    }
};