#include <vector>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

struct square
{
    //row
    int r;

    //column
    int c;

    //value
    bool color;

};

int main()
{
    int M;
    cin >> M;
    M -= 1;
    int N;
    cin >> N;
    N -= 1;
    int K;
    cin >> K;
    char tempC;
    int tempI;


    vector<square> squares((M + 1) * (N + 1));
    int count1 = 0;
    for (int i = 0; i <= M; i++)
    {
        for (int x = 0; x <= N; x++)
        {
            squares[count1].r = i;
            squares[count1].c = x;
            squares[count1].color = false;
            count1++;
        }
    }

    int gold = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> tempC;
        getchar();
        cin >> tempI;
        tempI -= 1;

        if (tempC == 'R')
        {
            for (int x = (N+1) * tempI; x < ((N+1) * tempI) + (N + 1); x++)
            {
                if (squares[x].color)
                {
                    squares[x].color = false;
                    gold--;
                }
                else
                {
                    squares[x].color = true;
                    gold++;
                }
            }
        }
        if (tempC == 'C')
        {
            for (int x = tempI; x <= tempI + ((N + 1) * M); x += (N + 1))
            {
                if (squares[x].color)
                {
                    squares[x].color = false;
                    gold--;
                }
                else
                {
                    squares[x].color = true;
                    gold++;
                }
            }
        }
    }

    cout << gold;
    return 0;
}