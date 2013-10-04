class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int N = gas.size();
        if (N==1)
            return (gas[0] - cost[0]>=0)?0:-1;
        for (int i = 0; i<N; i++)
        {
            gas[i] -= cost[i];
            gas.push_back(gas[i]);
        }
        for(int i = 0; i<N; i++)
        {
            bool isAnswer = true;
            int sum = 0;
            for (int j = 0; j<N; j++)
            {
                sum += gas[i+j];
                if (sum<0)
                {
                    isAnswer = false;
                    break;
                }
            }
            if (isAnswer)
                return i>=N?(i-N):i;
        }
        return -1;
    }
};