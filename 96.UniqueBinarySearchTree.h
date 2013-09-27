class Solution {
public:
    vector <int> unique;
    Solution()
    {
        unique.push_back(1);
        unique.push_back(1);
    }
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<unique.size())
            return unique[n];
        
        unique.resize(n+1, -1);
        int i_method = 0;
        for (int i = 1; i<=n; i++)
        {
            if (unique[i-1]==-1)
                unique[i-1] = numTrees(i-1);
                
            if (unique[n-i]==-1)
                unique[n-i] = numTrees(n-i);
                
            i_method += (unique[i-1]*unique[n-i]);
        }
        unique[n] = i_method;
        return unique[n];
    }
};