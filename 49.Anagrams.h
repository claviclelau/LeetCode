class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <string> answer;
        if (strs.size()<=1)
            return answer;
            
        map <string, int> anas;
        
        for (int i = 0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anas.find(s)==anas.end())
            {
                anas[s] = i;
            }
            else
            {
                if (anas[s]>=0)
                {
                    answer.push_back(strs[anas[s]]);
                    anas[s] = -1;
                }
                answer.push_back(strs[i]);
            }
        }
        return answer;
    }
};