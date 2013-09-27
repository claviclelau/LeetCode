class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int i_start, i_end;
        int answer = 0x7FFFFFFF;
        int sum;
        for (int i = 0; i<num.size()-2; ++i)
        {       
            i_start = i+1;
            i_end = num.size()-1;
            
            while (i_start<i_end)
            {       
                sum = num[i] + num[i_start] + num[i_end];
                if (sum==target)
                {
                    return target;
                }
                else
                {
                    answer = abs(sum-target)<abs(answer)?sum-target:answer;
                    if (sum>target)
                    {
                        --i_end;
                    }   
                    else
                    {
                        ++i_start;
                    }
                }
            }
        }
        return answer + target;
    }
};