#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<float> heights;
    float temp;

    cin >> temp;

    heights.push_back(temp);

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        heights.push_back(temp);
    }

    vector<float> widths;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        widths.push_back(temp);
    }

    float area = 0;

    for (int i = 0; i < N; i++)
    {
        area += widths[i] * (heights[i] + heights[i + 1]) / 2;
    }

    cout << fixed;
    cout << setprecision(1);
    cout << area;
    return 0;
}