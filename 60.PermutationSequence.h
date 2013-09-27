class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str_answer;
        if (n==1)
        {
            str_answer = "1";
            return str_answer;
        }
        vector<char> v_answer;
        for (int i = 1; i<=n; i++)
        {
            v_answer.push_back('0'+i);
        }
        int i_factorial = 1;
        for (int i = 2; i<=n-1; i++)
        {
            i_factorial *= i;
        }
        int i_bit_num = 0;
    	--k;
		int i_time = n-1;
        while(n-1-i_bit_num>0)
        {
            int i_exchange = k/i_factorial;
            char c_temp = v_answer[i_bit_num+i_exchange];
            for (int i = i_bit_num+i_exchange; i>i_bit_num; i--)
            {
                v_answer[i] = v_answer[i-1];
            }
            v_answer[i_bit_num] = c_temp;
	    k %= i_factorial;
	    i_factorial /= (n-1-i_bit_num);
            i_bit_num++;  
        }
        for (int i = 0; i<v_answer.size(); i++)
        {
            str_answer += v_answer[i];
        }
        return str_answer;
    }
};