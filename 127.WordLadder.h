class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return BFS(start, end, dict);
    }
	int BFS (string start, string end, unordered_set<string> &dict)
	{
		queue <pair <string, int> > my_queue;
		my_queue.push(make_pair(start, 1));
		pair <string , int> my_pair;
		string my_word;
		while (!my_queue.empty())
		{
			my_pair = my_queue.front();
			my_queue.pop();
			my_word = my_pair.first;
			for (int i = 0; i<my_word.size(); i++)
			{
				my_word = my_pair.first;
				for (char c = 'a'; c<='z'; c++)
				{
					my_word[i] = c;
					if (my_word==end)
						return my_pair.second+1;
					if (dict.find(my_word)!=dict.end())
					{
						dict.erase(my_word);
						my_queue.push(make_pair(my_word, my_pair.second+1));
					}
				}
			}
		}
		return 0;
	}
};