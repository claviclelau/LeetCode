class Solution {
public:
    vector <unsigned long long int> Fibonacci;
    Solution()
    {
        Fibonacci.push_back(1);
        Fibonacci.push_back(1);
        Fibonacci.push_back(2);
    }
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (Fibonacci.size()>n)
            return Fibonacci[n];
            
        int i_size = Fibonacci.size();
        Fibonacci.resize(n+1);
        for (int i = i_size; i<Fibonacci.size(); i++)
            Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
            
        return Fibonacci[n];
    }
};