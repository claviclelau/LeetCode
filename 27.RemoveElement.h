class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		return removeElement_2(A, n, elem);
	}
    int removeElement_1(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if (n==0)
			return 0;
        int i_front = 0, i_back = n - 1;
		while(i_front<i_back)
		{
			if (A[i_front]==elem)
			{
				if (A[i_back]!=elem)
					A[i_front++] = A[i_back];
				--i_back;
			}
			else
				++i_front;
		}
		
		//Lots of subtleties. Should pay special attention to special cases.
		i_front = min(i_front, i_back);
		return A[i_front]==elem?i_front:i_front+1;
    }
	
	//This one is much simpler. From AnnieKim
	int removeElement_2(int A[], int n, int elem)
	{
		int i = 0;
		for (int j = 0; j<n; j++)
			if (A[j]!=elem)
				A[i++] = A[j];
		
		return i;
	}
};