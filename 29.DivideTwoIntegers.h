class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool minus = false;
		long long dividend_ll = (long long)dividend;
		long long divisor_ll = (long long )divisor;
        dividend_ll = dividend<0?(minus=!minus, -dividend_ll):dividend_ll;
        divisor_ll = divisor<0?(minus=!minus, -divisor_ll):divisor_ll;
        long long temp_divisor = divisor_ll;
        long long quotient = 0;
        long long n = 1;
        while (dividend_ll>(temp_divisor<<1))
        {
            temp_divisor <<= 1;
            n <<= 1;
        }
        while(dividend_ll>=divisor_ll)
        {
            while (dividend_ll<temp_divisor)
            {
                temp_divisor >>= 1;
                n >>= 1;
            }
            quotient += n;
            dividend_ll -= temp_divisor;
        }
        return (int)(minus?-quotient:quotient);
    }
};