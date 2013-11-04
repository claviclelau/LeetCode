class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		unordered_set<string> my_dict(dict);
        int i_level = BFS(start, end, dict);
		vector<vector<string>> answer;
		vector<string> ladder;
		ladder.push_back(start);
		DFS(start, end, my_dict, answer, i_level - 1, ladder);
		return answer;
    }
	//Naive idea is first BFS then DFS. It will cause time limit exceeded.
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
	void DFS (string start, string end, unordered_set<string> & dict, vector<vector<string> > & answer, int i_level, vector<string> & ladder)
	{
		if (i_level==0)
			return;
		string my_word;
		int N = start.size();
		for (int i = 0; i<N; ++i)
		{
			my_word = start;
			for (char c = 'a'; c<='z'; c++)
			{
				my_word[i] = c;
				if (my_word==end)
				{
					ladder.push_back(my_word);
					answer.push_back(ladder);
					ladder.pop_back();
					continue;
				}
				if (my_word==start||dict.find(my_word)==dict.end())
					continue;
				ladder.push_back(my_word);
				DFS(my_word, end, dict, answer, i_level - 1, ladder);
				ladder.pop_back();
			}
		}
	}
};