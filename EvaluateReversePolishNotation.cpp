class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    	if (tokens.size() == 0)
    		return 0;
        stack <int> my_stack;
        int iSize = tokens.size();
        int a, b;
        for (int i = 0; i < iSize; ++i)
        {
        	switch(tokens[i][0])
        	{
        		case '+':
        			a = my_stack.top();
        			my_stack.pop();
        			b = my_stack.top();
        			my_stack.pop();
        			my_stack.push(a + b);
        			break;
        		case '-':
        			a = my_stack.top();
        			my_stack.pop();
        			b = my_stack.top();
        			my_stack.pop();
        			my_stack.push(b - a);
        			break;
        		case '*':
        			a = my_stack.top();
        			my_stack.pop();
        			b = my_stack.top();
        			my_stack.pop();
        			my_stack.push(b * a);
        			break;
        		case '/':
        			a = my_stack.top();
        			my_stack.pop();
        			b = my_stack.top();
        			my_stack.pop();
        			my_stack.push(b / a);
        			break;
        		default:
        			my_stack.push(atoi(tokens[i].c_str()));
        			break;
        	}
        }
        return my_stack.top();
    }
};