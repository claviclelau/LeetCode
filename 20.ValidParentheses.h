class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size()==0)
            return true;
            
        if (s.size()&1!=0)
            return false;
            
        vector<char> ParenthesStack;
        for(int i = 0; i<s.size(); i++)
        {
            switch(s[i]){
                case '(':
                case '{':
                case '[':
                    ParenthesStack.push_back(s[i]);
                    break;
                case ')':
                    if (ParenthesStack.size()==0||ParenthesStack.back()!='(')
                        return false;
                    else
                        ParenthesStack.pop_back();
                    break;
                case '}':
                    if (ParenthesStack.size()==0||ParenthesStack.back()!='{')
                        return false;
                    else
                        ParenthesStack.pop_back();
                    break;
                case ']':
                    if (ParenthesStack.size()==0||ParenthesStack.back()!='[')
                        return false;
                    else
                        ParenthesStack.pop_back();
                    break;
                default:
                    return false;
            }
        }
        
        if (ParenthesStack.size()!=0)
            return false;
        
        return true;
    }
};