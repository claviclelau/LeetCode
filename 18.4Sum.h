class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer;
        if (num.size()<4)
            return answer;
        
        sort(num.begin(), num.end());
        
        for (int i = num.size() - 1; i>2; --i)
        {
            int i_size = answer.size();
            threeSum(num, i, answer, target - num[i]);
            for (; i_size<answer.size(); i_size++)
            {
                answer[i_size].push_back(num[i]);
            }
            while(i>2&&num[i]==num[i-1])
                --i;
        }
        return answer;
    }
    void threeSum(vector<int> &num, int size, vector<vector<int> > & answer, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size()<3)
            return;
        
        vector<int> triplet;
        int i_start, i_end;
        int sum;
        for (int i = 0; i < size -2; ++i)
        {
            if (i>0&&num[i]==num[i-1])
                continue;
                
            i_start = i+1;
            i_end = size -1;
            
            while (i_start<i_end)
            {
                if (num[i_start]==num[i_start+1]&&num[i] + num[i_start] + num[i_start+1]==target)
                {
                    triplet.clear();
                    triplet.push_back(num[i]);
                    triplet.push_back(num[i_start]);
                    triplet.push_back(num[i_start]);
                    answer.push_back(triplet);
                }
                while (i_start<i_end&&num[i_start]==num[i_start+1])
                    ++i_start;
                    
                if (i_start==i_end)
                    break;
                    
                if (num[i_end]==num[i_end-1]&&num[i] + num[i_end-1] + num[i_end]==target)
                {
                    triplet.clear();
                    triplet.push_back(num[i]);
                    triplet.push_back(num[i_end]);
                    triplet.push_back(num[i_end]);
                    answer.push_back(triplet);
                }
                while (i_end>i_start&&num[i_end]==num[i_end-1])
                    --i_end;
                    
                sum = num[i] + num[i_start] + num[i_end];
                if (sum==target)
                {
                    triplet.clear();
                    triplet.push_back(num[i]);
                    triplet.push_back(num[i_start]);
                    triplet.push_back(num[i_end]);
                    answer.push_back(triplet);
                    ++i_start;
                }
                else if (sum>target)
                    --i_end;
                else
                    ++i_start;
            }
        }
    }
};