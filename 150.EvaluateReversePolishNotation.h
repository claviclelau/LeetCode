class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		if (tokens.size()==0)
			return 0;
		stack <int> my_stack;
		for (int i = 0; i<tokens.size(); ++i)
		{
			int elem1, elem2;
			if (tokens[i].size()==1&&(tokens[i][0]<'0'||tokens[i][0]>'9'))
			{
				elem2 = my_stack.top();
				my_stack.pop();
				elem1 = my_stack.top();
				my_stack.pop();
				switch (tokens[i][0]){
                    case '+':
                        my_stack.push(elem1 + elem2);
                        break;
                    case '-':
                        my_stack.push(elem1 - elem2);
                        break;
                    case '*':
                        my_stack.push(elem1 * elem2);
                        break;
                    case '/':
                        my_stack.push(elem1 / elem2);
                        break;
                }
            }
            else
            {
                my_stack.push(atoi(tokens[i].c_str()));
            }
        }
        return my_stack.top();
    }
};