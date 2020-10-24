//트럭 주차
#include <iostream>

using namespace std;

int g_nMap[3][100];

int main(void)
{
    int A = 0;
    int B = 0;
    int C = 0;
    int nMin  = 0;
    int nMax  = 0;
    int nStart = 0;
    int nEnd = 0;
    int nTmp = 0;
    int nAns = 0;

    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++)
    {
        cin >> nStart >> nEnd;
        
        if(i == 0)
        {
            nMin = nStart;
            nMax = nEnd;
        }
        else
        {
            if(nStart < nMin)
                nMin = nStart;
            if(nEnd > nMax)
                nMax = nEnd;
        }

        for(int j = nStart; j < nEnd; j++)
        {
            g_nMap[i][j] = 1;
        }
    }

    for(int i = nMin; i < nMax; i++)
    {
        nTmp = g_nMap[0][i] + g_nMap[1][i] + g_nMap[2][i];
        if (nTmp == 1)
            nAns += A;
        else if(nTmp == 2)
            nAns += B*2;
        else if(nTmp == 3)
            nAns += C*3;
    }

    cout << nAns << endl;

    return 0;
}