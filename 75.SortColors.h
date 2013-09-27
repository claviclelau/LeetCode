class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i_red = -1, i_blue = n;
        while(A[++i_red]==0);
        while(A[--i_blue]==2);
        
        int i = i_red;
        int i_temp;
        while(i<=i_blue)
        {
            switch(A[i]){
            case 0:
                A[i] = A[i_red];
                A[i_red] = 0;
                while(A[++i_red]==0);
                i = i>i_red?i:i_red;
                break;
            case 1:
                ++i;
                break;
            case 2:
                A[i] = A[i_blue];
                A[i_blue] = 2;
                while(A[--i_blue]==2);
                break;
            }
        }
    }
};