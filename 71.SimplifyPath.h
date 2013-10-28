class Solution {
public:
    string simplifyPath(string path) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    	string answer;
	    if (path.size()==0)
	    {
	        answer.push_back('/');
	        return answer;
	    }
	    int index = 0;
	    if (path[index]!='/')
	        answer.push_back('/');
	    else
	        answer.push_back(path[index++]);
	    string str;
	    for (; index < path.size(); ++index)
	    {
	        str.resize(0);
	        while(index<path.size()&&path[index]!='/')
	        {
	            str.push_back(path[index]);
	            ++index;
	        }
	        if (str.empty())
	            continue;
	        if (str=="..") {
	            if(answer.back()=='/'&&answer.size()>1)
	                answer.pop_back();
	            while(!answer.empty()&&answer.back()!='/')
	                answer.pop_back();
	        } else if(str=="."){
        
	        } else{
	            answer += str;
	            answer += "/";
	        }
	    }
	    if (answer.back()=='/'&&answer.size()>1)
	        answer.pop_back();
	    return answer;
    }
};