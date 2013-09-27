class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows<=1) //Without this condition will cause Memory Limit Exceeded.
            return s;
            
        string answer;

        if (s.size()==0)
            return answer;
    
        int k, index;
        for (int i = 0; i<nRows; i++)
        {
            for (k = 0, index = i; index<s.size(); k++, index = (2*nRows - 2)*k+i)
            {
                answer += s[index];
    
                if (i==0||i==nRows-1)
                    continue;
    
                if ((index += 2*(nRows-i-1))<s.size())
                {
                    answer += s[index]; 
                }
            }
        }
        return answer;
    }
};