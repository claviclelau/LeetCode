class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if (s==NULL&&p==NULL)
			return true;
		if (s==NULL||p==NULL)
			return false;
		if (*p=='\0')//Pay special attention to this. It is p NOT s.
			return *s == '\0';
		if (*(p+1)!='*')
			return ((*s == *p)||((*p == '.')&&(*s!='\0')))&&isMatch(s+1, p+1);
			
		while ((*s == *p)||((*p == '.')&&(*s!='\0')))
		{
			if (isMatch(s, p+2)) return true;
			s++;
		}
		return isMatch(s, p+2);//Because "a*" means repeat a any times, including zero.
    }
};