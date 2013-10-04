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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector <Interval> answer;
        bool isInserted = false;
		for (int i = 0; i<intervals.size(); i++)
		{
			int relation = mergeIntervals(newInterval, intervals[i]);
			if(relation==0)
				continue;
			else if(relation==1)
				answer.push_back(intervals[i]);
			else
			{
				answer.push_back(newInterval);
				for (; i<intervals.size(); ++i)
					answer.push_back(intervals[i]);
				isInserted = true;
			}
		}
		if (!isInserted)
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