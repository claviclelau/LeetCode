class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return maxSubArrayDivide(A, 0, n-1);
    }
    int maxSubArrayDivide(int A[], int i_start, int i_end)
    {
        if (i_start==i_end)
            return A[i_start];
            
        int i_left = maxSubArrayDivide(A, i_start, (i_start+i_end)/2);
        int i_right = maxSubArrayDivide(A, (i_start+i_end)/2 + 1, i_end);
        int i_max = i_left>i_right?i_left:i_right;
        
        i_left = A[(i_start+i_end)/2];
        i_right = A[(i_start+i_end)/2+1];
        int i_max_left = i_left;
        int i_max_right = i_right;
        for (int i = (i_start+i_end)/2 - 1; i>=0; i--)
        {
            i_left += A[i];
            i_max_left = i_max_left>i_left?i_max_left:i_left;
        }
        for (int i = (i_start+i_end)/2 + 2; i<=i_end; i++)
        {
            i_right += A[i];
            i_max_right = i_max_right>i_right?i_max_right:i_right;
        }
        i_max_left += i_max_right;
        
        return i_max>i_max_left?i_max:i_max_left;
    }
};