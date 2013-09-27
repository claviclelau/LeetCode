class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer;
        if (num.size()<3)
            return answer;
        
        vector<int> triplet;
        sort(num.begin(), num.end());
        int i_start, i_end;
        int sum;
        for (int i = 0; i<num.size()-2; ++i)
        {
            if (i>0&&num[i]==num[i-1])
                continue;
                
            i_start = i+1;
            i_end = num.size()-1;
            
            while (i_start<i_end)
            {
                if (num[i_start]==num[i_start+1]&&num[i] + num[i_start] + num[i_start+1]==0)
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
                    
                if (num[i_end]==num[i_end-1]&&num[i] + num[i_end-1] + num[i_end]==0)
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
                if (sum==0)
                {
                    triplet.clear();
                    triplet.push_back(num[i]);
                    triplet.push_back(num[i_start]);
                    triplet.push_back(num[i_end]);
                    answer.push_back(triplet);
                    ++i_start;
                }
                else if (sum>0)
                    --i_end;
                else
                    ++i_start;
            }
        }
        return answer;
    }
};