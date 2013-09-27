//1. https://github.com/AnnieKim/LeetCode/blob/master/LargestRectangleinHistogram.h
//Not the most efficient.
//2. http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
//More efficient.
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		return largestRectangleArea_2(height);
	}
    int largestRectangleArea_1(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack <int> stk;
        height.push_back(0);//This is subtle.
        int answer = 0;
        for (int i = 0; i<height.size(); i++)
        {
            int i_count = 0;
            while(!stk.empty()&&stk.top()>height[i])
            {
                i_count++;
                answer = max(answer, i_count*stk.top());
                stk.pop();
            }
            while (i_count--)
                stk.push(height[i]);
                
            stk.push(height[i]);
        }
        return answer;
    }
	
	int largestRectangleArea_2(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <int> stk;
        height.push_back(0);//This is subtle.
        int answer = 0;
        int i = 0;
        while(i<height.size())
		{
			if (stk.empty()||height[stk.back()]<=height[i])
				stk.push_back(i++);
			else
			{
				int temp = stk.back();
				stk.pop_back();
				answer = max(answer, height[temp]*(stk.empty()?i:(i-stk.back()-1)));//This is subtle.
			}
		}
        return answer;
    }
};