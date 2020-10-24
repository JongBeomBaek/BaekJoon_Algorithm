//이동하기
#include <iostream>
#include <time.h>

using namespace std;

//#define Before

#ifdef Before
#define MAX_SIZE  1000

int g_nMap[MAX_SIZE][MAX_SIZE];


int MaximumPath(int r, int c, int n, int m, int val)
{
    if(r == n-1 && c == m-1)
    {
        return val;
    }
    else
    {
        int x = 0, y = 0, z = 0;
        int max  = 0;

        if(r < n-1)
            x = MaximumPath(r+1, c, n, m, val + g_nMap[r+1][c]);       
        if(c < m-1)
            y = MaximumPath(r, c+1, n, m, val + g_nMap[r][c+1]);     
        if(r < n-1 && c < m-1)
            z = MaximumPath(r+1, c+1, n, m, val + g_nMap[r][c+1]);      

        //cout << "(" << r << "," << c <<")val: "<< val << " x:" << x << " y:" << y << " z:" << z << endl;

        if(max < x)
            max = x;
        if(max < y)
            max = y;
        if(max < z)
            max = z;

        return max;
    }  
}

int main(void)
{
    int n = 0;
    int m = 0;
    time_t start, end;
    double result = 0.0;

    cin >> n >> m;
    start  = time(NULL);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> g_nMap[i][j];
        }
    }

    cout << MaximumPath(0, 0, n, m, g_nMap[0][0]) << endl;
    end = time(NULL);

    result =(double)(end - start);
    printf("%f", result); 
    
    return 0;
}
#else

#define MAX_SIZE  1001

int g_nMap[MAX_SIZE][MAX_SIZE];

int Get_MaxNum(int x, int y, int z)
{
    int max = 0;

    if(max < x)
        max = x;
    if(max < y)
        max = y;
    if(max < z)
        max = z;
    
    return  max;
}

int main(void)
{
    int n = 0;
    int m = 0;
    time_t start, end;
    double result = 0.0;
    
    cin >> n >> m;
    start  = time(NULL);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
        
            int tmp = 0;
            int max = 0;
            cin >> tmp;
            max = Get_MaxNum(g_nMap[i-1][j], g_nMap[i-1][j-1], g_nMap[i][j-1]);

            g_nMap[i][j] = max + tmp;
        }
    }

    cout << g_nMap[n][m] << endl;
    end  = time(NULL);

    result =(double)(end - start);
    printf("%f", result); 
    
    return 0;
}
#endif