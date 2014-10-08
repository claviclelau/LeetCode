class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        //This one utilize the fact that if there is an answer, the answer is unique. O(n).
        //Old code's time cost is O(n^2);
        int N = gas.size();
        int min = gas[0] - cost[0];
        int sum = min;
        int ret = 0;
        for (int i = 1; i<N; ++i)
        {
        	sum += gas[i] - cost[i];
        	if (sum < min)
        	{
        		min = sum;
        		ret = i;
        	}
        }
        return sum >= 0 ? (ret + 1)%N : -1;
    }
};