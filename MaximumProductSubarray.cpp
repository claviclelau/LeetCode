class Solution {
public:
    int maxProduct(int A[], int n) {
        return maxProductDP(A, n);
    }
    int maxProduct_1(int A[], int n) {
        if (n == 1)
            return A[0];
        int result = 0;
        int a = 0, b = 0;
        while (1)
        {
            getNoZeroSubarray(A, a, b, n);
            if (a == n && b == 0)
                return 0;
            if (a == n)
                break;
            
            int tempResult = maxProductNoZero(A + a, b - a);
            
            result = result > tempResult ? result : tempResult;
            
            a = b;
        }
        return result;
    }
    int maxProductNoZero(int A[], int n)
    {
        if (n == 1)
            return A[0];
        int result = 1;
        for (int i = 0; i < n; ++i)
            result *= A[i];
        
        if (result > 0)
            return result;
        
        int leftResult = 1;
        int rightResult = result;
        for (int i = 0; i < n; ++i)
        {
            leftResult *= A[i];
            rightResult /= A[i];
            int tempResult = rightResult > 0 ? rightResult : leftResult;
            result = tempResult > result ? tempResult : result;
        }
        return result;
    }
    void getNoZeroSubarray(int A[], int & a, int & b, int n)
    {
        while (a < n && A[a] == 0)
            ++a;
        if (a == n)
            return;
        
        b = a + 1;
        while (b < n && A[b] != 0)
            ++b;
    }


    int maxProductDP(int A[], int n)
    {
        if (n == 1)
            return A[0];

        int curMax, curMin, ret;
        ret = curMax = curMin = A[0];
        for(int i = 1; i<n; ++i)
        {
            int tempMax = curMax * A[i];
            int tempMin = curMin * A[i];
            if (tempMin > tempMax)
            {
                int temp = tempMin;
                tempMin = tempMax;
                tempMax = temp;
            }
            curMax = tempMax > A[i] ? tempMax : A[i];
            curMin = tempMin < A[i] ? tempMin : A[i];
            ret = ret > curMax ? ret : curMax;
        }
        return ret;
    }
};