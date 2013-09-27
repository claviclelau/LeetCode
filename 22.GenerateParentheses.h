class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> answer;
        if (n<1)
            return answer;
        
        vector<char> Parenthesis;
        DFS(Parenthesis, answer, n, n);
        return answer;
    }
    void DFS(vector<char> & Parenthesis, vector<string> & answer, int i_left, int i_right)
    {
        if (i_left==0&&i_right==0)
        {
            string one_case;
            for(int i = 0; i<Parenthesis.size(); i++)
            {
                one_case += Parenthesis[i];
            }
            answer.push_back(one_case);
            return;
        }
        if (i_left==i_right)
        {
            Parenthesis.push_back('(');
            DFS(Parenthesis, answer, i_left-1, i_right);
            Parenthesis.pop_back();
        }
        else
        {
            if (i_left>0)
            {
                Parenthesis.push_back('(');
                DFS(Parenthesis, answer, i_left-1, i_right);
                Parenthesis.pop_back();
            }
            Parenthesis.push_back(')');
            DFS(Parenthesis, answer, i_left, i_right-1);
            Parenthesis.pop_back();
        }
    }
};