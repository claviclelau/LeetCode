class Solution {
public:
    int singleNumber(int A[], int n) {
        int answer = A[0];

        for (int i = 1; i<n; ++i)
        	answer ^= A[i];

        return answer;
    }
};