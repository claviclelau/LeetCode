class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function;       
        if(((m+n)&1)==0)
            return ((double)findKthInSortedArrayRecursive(A, m, B, n, (m+n)/2+1) + (double)findKthInSortedArrayRecursive(A, m, B, n, (m+n)/2))/2;
        else
            return findKthInSortedArrayRecursive(A, m, B, n, (m+n+1)/2);
    }
    int findKthInSortedArrayRecursive(int A[], int m, int B[], int n, int k)
    {
        if (m == 0)
            return B[k-1];
        else if (n==0)
            return A[k-1];
        int i_place;
        if (m>n)
        {
            i_place = BinarySearchRecursive(A, 0, m - 1, B[n/2]);
            if (i_place + n/2 == k - 1)
                return B[n/2];
            else if (i_place + n/2 > k - 1)
                return findKthInSortedArrayRecursive(A, i_place, B, n/2, k);
            else
                return findKthInSortedArrayRecursive(&A[i_place], m-i_place, &B[n/2+1], n - n/2 - 1, k - i_place - n/2 - 1);
        }
        else
        {
            i_place = BinarySearchRecursive(B, 0, n - 1, A[m/2]);
            if (i_place + m/2 == k - 1)
                return A[m/2];
            else if (i_place + m/2 > k - 1)
                return findKthInSortedArrayRecursive(B, i_place, A, m/2, k);
            else
                return findKthInSortedArrayRecursive(&B[i_place], n-i_place, &A[m/2+1], m - m/2 - 1, k - i_place - m/2 - 1);
        }
    }
    // Return the index of target, if target were inserted into this array.
    int BinarySearchRecursive(int A[], int i_begin, int i_end, int target)
    {
        int i_middle = (i_begin+i_end)/2;
        if (target==A[i_middle])
            return i_middle;
        else if(i_begin==i_end)
        {
            if (target<A[i_middle])
                return i_middle;
            else
                return i_middle+1;
        }
        
        if (target<A[i_middle])
        {
            if (i_begin == i_middle)
                return i_begin;
            else
                return BinarySearchRecursive(A, i_begin, i_middle-1, target);
        }
        else
        {
            return BinarySearchRecursive(A, i_middle+1, i_end, target);
        }
    }
};