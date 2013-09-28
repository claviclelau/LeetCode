class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pair <int , int> my_pair;
        vector<pair<int, int> > number_copy;
        for (int i = 0; i<numbers.size(); i++)
        {
            my_pair.first = numbers[i];
            my_pair.second = i+1;
            number_copy.push_back(my_pair);
        }
        sort(number_copy.begin(), number_copy.end(), compare);
        int i = 0, j = number_copy.size()-1;
        vector<int> answer;
        while (i<j)
        {
            int sum = number_copy[i].first + number_copy[j].first;
            if (sum == target)
            {
                answer.push_back(min(number_copy[i].second,number_copy[j].second));
                answer.push_back(max(number_copy[i].second,number_copy[j].second));
                return answer;
            }
            else if (sum < target)
                ++i;
            else
                --j;
        }
    }
	static bool compare(pair<int, int> pair_1, pair<int, int> pair_2)//static is important.
	{
		return pair_1.first<pair_2.first;
	}
};