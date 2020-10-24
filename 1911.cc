//흙길 보수하기 
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N = 0;
	int L = 0;
	int M_st = 0;
	int M_fi = 0;
    priority_queue< pair<int, int> > prior_Que;

	int Pos = 0;
	int cnt = 0;

	cin >> N >> L;

	for(int i = 0; i < N; i++)
	{
		cin >> M_st;
		cin >> M_fi;
        pair<int, int> pTmp = make_pair(-M_st, -M_fi);    
        prior_Que.push(pTmp);
	}

    while(!prior_Que.empty())
    {
        pair<int, int> pTmp = prior_Que.top();
        prior_Que.pop();
        
        if(-pTmp.first > Pos) 
            Pos =  -pTmp.first;

        while(-pTmp.second > Pos)
        {
            Pos += L;
            cnt++;
        }
    }

	cout << cnt << endl;

	return 0;
}