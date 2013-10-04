/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compareIntervals(Interval inter_1, Interval inter_2)
    {
        return inter_1.start < inter_2.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (intervals.size()<=0)
            return intervals;
        vector <Interval> answer;
        sort(intervals.begin(), intervals.end(), compareIntervals);
        Interval newInterval = intervals[0];
        for (int i = 1; i<intervals.size(); i++)
        {
            int relation = mergeIntervals(newInterval, intervals[i]);
            if (relation==-1)
            {
                answer.push_back(newInterval);
                newInterval = intervals[i];
            }
        }
        answer.push_back(newInterval);
        return answer;
    }
    int mergeIntervals(Interval & inter_1, Interval inter_2)
	{
		if (inter_1.end<inter_2.start)
			return -1;
		if (inter_1.start>inter_2.end)
			return 1;
		
		inter_1.start = min(inter_1.start, inter_2.start);
		inter_1.end = max(inter_1.end, inter_2.end);
		return 0;
	}
};