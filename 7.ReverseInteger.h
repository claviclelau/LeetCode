class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long int answer = 0;
        while(x)
        {
            answer = answer*10 + x%10;
            x /= 10;
        }
        assert(answer<=INT_MAX&&answer>=INT_MIN);
        return answer;
    }
};