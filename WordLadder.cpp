class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        return BFS(start, end, dict);
    }
    int BFS(string start, string & end, unordered_set<string> &dict)
    {
        if (start == end)
            return 1;
    	pair<string, int> myPair;
    	int length = 1;
    	queue<pair<string, int> > myQueue;
    	myQueue.push(make_pair(start, 1));
    	int N = start.size();
    	string s;
    	while(!myQueue.empty())
    	{
    		myPair = myQueue.front();
    		myQueue.pop();
    		s = myPair.first;
    		for (int i = 0; i < N; ++i)
    		{
    			char z = s[i];
    			for (char c = 'a'; c <= 'z'; ++c)
    			{
    				if (c == z)
    					continue;

    				s[i] = c;
    				if (s == end)
    				    return myPair.second + 1;
    				if (dict.find(s) == dict.end())
    				{
    					continue;
    				}

    				myQueue.push(make_pair(s, myPair.second + 1));
    				dict.erase(s);
    			}
    			s[i] = z;
    		}
    	}
    	return 0;
    }
};