class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> numSet;
        for(int i = 0; i<num.size(); i++)
        {
            numSet.insert(num[i]);
        }
        int answer = 0;
        for(int i = 0; i<num.size()&&numSet.size()>answer; i++)
        {
            int i_count = 0;
            if (numSet.find(num[i])!=numSet.end())
            {
                ++i_count;
                int val = num[i];
                while(numSet.find(++val)!=numSet.end())
                {
                    ++i_count;
                    numSet.erase(val);
                }
                    
                
                val = num[i];
                while(numSet.find(--val)!=numSet.end())
                {
                    ++i_count;
                    numSet.erase(val);
                }
                answer = answer>i_count?answer:i_count;
            }
        }
        return answer;
    }
};