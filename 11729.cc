//하노이 탑 이동 순서
#include <iostream>
#include <stdio.h>

using namespace std;

void Hanoi(int N,int nSrc, int nTar, int nOth)
{
    if(N == 1)
    {
        printf("%d %d\n", nSrc, nTar);       
    }
    else
    {
        Hanoi(N-1,nSrc, nOth, nTar);
        printf("%d %d\n", nSrc, nTar);       
        Hanoi(N-1, nOth, nTar, nSrc);
    }
}


int main(void)
{
    int N = 0;
    int nCnt = 1;
    cin >> N;

    
    for(int i = 2; i <= N; i++)
    {
        nCnt = 2*nCnt + 1;
    }

    printf("%d\n", nCnt);    

    Hanoi(N, 1, 3, 2);
    
    return 0;
}