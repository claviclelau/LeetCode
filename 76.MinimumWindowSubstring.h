class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int alphabet[256];
		int times[256];
        for (int i = 0; i<256; i++)
			alphabet[i] = times[i] = 0;
            
        for (int i = 0; i<T.size(); i++)
            times[unsigned(T[i])]++;
            
        queue<unsigned int> my_queue;
        int i_length = INT_MAX, i_min, i_max;
        int i_num = 0;
        for (int i = 0; i<S.size(); i++)
        {
			if (times[unsigned(S[i])]==0)
				continue;
            if (alphabet[unsigned(S[i])]<times[unsigned(S[i])])
            {
                my_queue.push(i);
                alphabet[unsigned(S[i])]++;
                i_num++;
            }
            else
            {
                my_queue.push(i);
				alphabet[unsigned(S[i])]++;
                while (alphabet[unsigned(S[my_queue.front()])]>times[unsigned(S[my_queue.front()])])
				{
					alphabet[unsigned(S[my_queue.front()])]--;
					my_queue.pop();
				}
            }
			if (i_num==T.size()&&i_length>(my_queue.back()-my_queue.front()+1))
            {
                i_length = my_queue.back()-my_queue.front()+1;
                i_min = my_queue.front();
                i_max = my_queue.back();
            }
        }
        if (i_length==INT_MAX)
            return string("");
        else
            return S.substr(i_min, i_max-i_min+1);
    }
};