class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size()==0||s[0]=='0')// Subtlety 1
            return 0;
            
        vector<int> decode_method(s.size()+1);
        decode_method[0] = 1;
        decode_method[1] = 1;
        
        for (int i = 1; i<s.size(); i++)
        {
            if (s[i]=='0')
            {
                if (s[i-1]=='0'||s[i-1]>'2')// Subtlety 2
                    return 0;
                    
                decode_method[i+1] = decode_method[i-1];
            }
            else
            {
                switch(s[i-1]){// Subtlety 3
                    case '1':
                        decode_method[i+1] = decode_method[i] + decode_method[i-1];
                        break;
                    case '2':
                        if (s[i]<='6'&&s[i]>='0')
                            decode_method[i+1] = decode_method[i] + decode_method[i-1];
                        else
                            decode_method[i+1] = decode_method[i];
                        break;
                    default:
                        decode_method[i+1] = decode_method[i];
                        break;
                }
            }
        }
        return decode_method[s.size()];
    }
};