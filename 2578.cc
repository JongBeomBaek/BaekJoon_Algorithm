//빙고
#include <iostream>

#define MAP_SIZE 5

using namespace std;

typedef struct _cordi{
	int r;
	int c;
}Cordi;

int g_nMap[MAP_SIZE][MAP_SIZE];

int Bingo(void)
{
	int cnt = 0;

	cnt += g_nMap[0][0] * g_nMap[1][0] * g_nMap[2][0] * g_nMap[3][0] * g_nMap[4][0];
	cnt += g_nMap[0][1] * g_nMap[1][1] * g_nMap[2][1] * g_nMap[3][1] * g_nMap[4][1];
	cnt += g_nMap[0][2] * g_nMap[1][2] * g_nMap[2][2] * g_nMap[3][2] * g_nMap[4][2];
	cnt += g_nMap[0][3] * g_nMap[1][3] * g_nMap[2][3] * g_nMap[3][3] * g_nMap[4][3];
	cnt += g_nMap[0][4] * g_nMap[1][4] * g_nMap[2][4] * g_nMap[3][4] * g_nMap[4][4];

	cnt += g_nMap[0][0] * g_nMap[0][1] * g_nMap[0][2] * g_nMap[0][3] * g_nMap[0][4];
	cnt += g_nMap[1][0] * g_nMap[1][1] * g_nMap[1][2] * g_nMap[1][3] * g_nMap[1][4];
	cnt += g_nMap[2][0] * g_nMap[2][1] * g_nMap[2][2] * g_nMap[2][3] * g_nMap[2][4];
	cnt += g_nMap[3][0] * g_nMap[3][1] * g_nMap[3][2] * g_nMap[3][3] * g_nMap[3][4];
	cnt += g_nMap[4][0] * g_nMap[4][1] * g_nMap[4][2] * g_nMap[4][3] * g_nMap[4][4];

	cnt += g_nMap[0][0] * g_nMap[1][1] * g_nMap[2][2] * g_nMap[3][3] * g_nMap[4][4];
	cnt += g_nMap[0][4] * g_nMap[1][3] * g_nMap[2][2] * g_nMap[3][1] * g_nMap[4][0];

	return cnt;
}

int main(void)
{
	Cordi tMap[26];
	int nAns = 0;
	int nTmp = 0;

	for (int i = 0; i < MAP_SIZE; i++)
	{	
		for(int j = 0; j < MAP_SIZE; j++)
		{
			cin >> nTmp;
			tMap[nTmp].r = i;
			tMap[nTmp].c = j;
 		}	
	}

	for (int i = 0; i < 25; i++)
	{	
		if(i <= 10)
		{
			cin >> nTmp;
			g_nMap[tMap[nTmp].r][tMap[nTmp].c] = 1;
		}
		else
		{
			cin >> nTmp;
			g_nMap[tMap[nTmp].r][tMap[nTmp].c] = 1;
			
			if(Bingo() >= 3)
			{
				nAns = i+1;
				break;
			}
		}
	}

	cout << nAns << endl;

	return 0;
}