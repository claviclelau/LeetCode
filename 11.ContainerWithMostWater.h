class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size()<2)
            return 0;
            
        int i_start = 0, i_end = height.size() - 1;
        int i_area = (height[i_start]<height[i_end]?height[i_start]:height[i_end])*(i_end - i_start);
        int i_temp_area = 0;
        while(i_start<i_end)
        {
            if (height[i_start]<height[i_end])
                ++i_start;
            else
                --i_end;
            
            i_temp_area = (height[i_start]<height[i_end]?height[i_start]:height[i_end])*(i_end - i_start);
            i_area = i_area>i_temp_area?i_area:i_temp_area;
        }
        return i_area;
    }
};