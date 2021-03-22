#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct f
{
    int P;
    int W;
    int D;
};

int N;

int CheckTime(vector<f> ft, int c)
{
    int time1 = 0;
    int temp2;
    for (int x = 0; x < N; x++)
    {
        temp2 = c - ft[x].P;
        if (abs(temp2) <= ft[x].D)
        {
            //Do Nothing
        }
        else if(temp2 < 0)
        {
            time1 += abs((c + ft[x].D) - ft[x].P) * ft[x].W;
        }
        else
        {
            time1 += abs((c - ft[x].D) - ft[x].P) * ft[x].W;
        }
    }
    
    return time1;
}

int main()
{
    
    cin >> N;

    vector<f> fs(N);

    int maxP = 0;
    int minP = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> fs[i].P;
        getchar();
        cin >> fs[i].W;
        getchar();
        cin >> fs[i].D;

        if (i == 0)
        {
            minP = fs[i].P;
        }
        else
        {
            minP = min(minP, fs[i].P);
        }

        maxP = max(maxP, fs[i].P);
        
    }

    int minT = CheckTime(fs, minP);
    for (int i = minP + 1; i <= maxP; i++)
    {
        minT = min(CheckTime(fs, i), minT);
    }

    cout << minT;
    return 0;
}