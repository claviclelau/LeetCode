class Solution {
public:
    string letters[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> answer;
        vector<char> v_letters;
        DFS (digits, 0, v_letters, answer);
        return answer;
    }
    void DFS(string & digits, int i_level, vector<char> & v_letters, vector<string> & answer)
    {
        if (i_level==digits.size())
        {
            string str_letter;
            for (int i = 0; i<v_letters.size(); i++)
            {
                str_letter += v_letters[i];
            }
            answer.push_back(str_letter);
            return;
        }        
        
        for (int i = 0; i<letters[digits[i_level]-'0'].size(); i++)
        {
            v_letters.push_back(letters[digits[i_level]-'0'][i]);
            DFS(digits, i_level+1, v_letters, answer);
            v_letters.pop_back();
        }
    }
};