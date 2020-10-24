// 종이접기
#include <iostream>

using namespace std;

int main(void)
{
    int N = 0;
    long long Ans = 0, Tmp = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> Tmp;
            Ans += Tmp;
        }
    }

    cout << Ans << endl;

    return 0;
}