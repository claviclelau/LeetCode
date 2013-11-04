class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if (x==0)
			return 0;
        int y = x, bits = 0;
		while(y)
		{
			y>>=1;
			++bits;
		}
		bits = (bits-1)/2;
		int answer = 1;
		answer<<=bits;
		while (--bits>=0)
		{
			//In case of overflow, use long long int.
			long long int root = answer+(1<<bits);
			if (root*root<=(long long int)x)
				answer = root;
		}
		return answer;
    }
};