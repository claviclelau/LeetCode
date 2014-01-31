class Solution {
public:
	//This code causes runtime error using LeetCode online judge. The input case is {[""],0}.
	//Don't know why, because it is OK when I use the same test case in XCode.
	vector<string> fullJustify(vector<string> &words, int L) {
	        // Start typing your C/C++ solution below
	        // DO NOT write int main() function
			vector <string> answer;
			string str;
	        for (int i = 0; i<words.size(); )
			{
				int i_length = words[i].size();
				int i_word = i;
				str.clear();
				while (i_length + words[i_word+1].size() + 1 < L)
				{
					++i_word;
					i_length += (words[i_word].size() + 1);
				}
				if (i_word == i)
				{
					str += words[i];
					str.resize(L, ' ');
				}
				else
				{
					int i_total_space = L - i_length + (i_word - i);
					int i_space_num = i_total_space / (i_word - i);
					int i_additional_space_num = i_total_space % (i_word - i);
					str = words[i];
					for (int j = i + 1; j <= i_word; ++j)
					{
						int N = str.size() + i_space_num + (i_additional_space_num > 0 ? 1 : 0);
						str.resize(N, ' ');
						str += words[j];
	                    --i_additional_space_num;
					}
				}
				answer.push_back(str);
				i = i_word + 1;
			}
			return answer;
	    }
};