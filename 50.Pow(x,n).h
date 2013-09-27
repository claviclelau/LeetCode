class Solution {
public:
	double pow(double x, int n) {
		return powRecursive(x, n);
	}
    double powRecursive(double x, int n) {
        if (x < 0)
            return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (x == 1)
            return x;
        if (n < 0)
            return 1.0 / pow(x, -n);
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        double half = pow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
	double powNotThatRecursive(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x==1||n==0)
            return 1;
            
        if (n==1)
            return x;
        
        if (x<0)
            return (n&1)==0?pow(-x, n):-pow(-x, n);
            
        if (n<0)
            return 1.0/pow(x, -n);
           
        double answer = 1;
        while(n!=0)
        {
            if ((n&1)!=0)
                answer *= x;
            
            x *= x;
            n >>= 1;
        }
        return answer;
    }
};