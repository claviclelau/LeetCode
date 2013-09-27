class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size()<=1)
            return;
            
        int i_sign = -1;
        for (int i = 1; i<num.size(); i++)
        {
            if (num[i]>num[i-1])
                i_sign = i;
        }
        int i_temp = 0;
        if (i_sign==-1)
        {
            for (int i = 0; i<num.size()-i-1; i++)
            {
                i_temp = num[i];
                num[i] = num[num.size()-i-1];
                num[num.size()-i-1] = i_temp;
            }
            return;
        }
        int i_smallest_big = i_sign;
        for (int i = i_sign + 1; i<num.size(); i++)
        {
            if (num[i]>num[i_sign-1])
                i_smallest_big = num[i]<=num[i_smallest_big]?i:i_smallest_big;       
        }
        i_temp = num[i_sign-1];
        num[i_sign-1] = num[i_smallest_big];
        num[i_smallest_big] = i_temp;
        
        for (int i = 0; i<num.size()-i-1-i_sign; i++)
        {
            i_temp = num[i_sign+i];
            num[i_sign+i] = num[num.size()-i-1];
            num[num.size()-i-1] = i_temp;
        }
    }
};