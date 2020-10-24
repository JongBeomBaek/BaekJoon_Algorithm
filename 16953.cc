// A > B
#include <iostream>

using namespace std;

int A2B(int A, int B, int nCnt)
{
	if(B == A)
		return (nCnt + 1);
	else if(B < A)
		return -1;
	else
	{
		if(B%2 == 0)
		{
			int Tmp = B/2;
			return A2B(A, Tmp, (nCnt + 1));
		}
		else
		{	
			int Tmp = 0;
			if(B%10 == 1)
			{
				Tmp = B/10;
				return A2B(A, Tmp, (nCnt + 1));
			}
			else 
				return -1;
		} 	
	}
}
int main(void)
{
	int A = 0, B = 0;
	int nAns = 0;

	cin >> A >> B;

	nAns = A2B(A, B, 0);

	cout << nAns << endl;

	return 0;
}
