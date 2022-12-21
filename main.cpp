#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#define ROW 100
#define COL 100

using namespace std;

int m = 6;
int n = 7;
int image[ROW][COL] = {
    {0, 0, 0, 1, 2, 1, 5},
    {4, 1, 8, 4, 9, 12, 15},
    {1, 2, 3, 4, 6, 7, 9},
    {2, 5, 6, 7, 4, 8, 9},
    {2, 1, 6, 5, 7, 2, 10},
    {13, 1, 5, 12, 14, 15, 10},
};
map<int, int> h;
map<int, int> t;
map<int, int> f;

void inputImage()
{
    cout << "Input row: ";
    cin >> m;
    cout << "Input col: ";
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Input [" << i << "][" << j << "]: ";
            cin >> image[i][j];
        }
    }
}

void showImage()
{
    cout << "Show image: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (image[i][j] < 10)
            {
                cout << "[0" << image[i][j] << "] ";
            }
            else
            {
                cout << "[" << image[i][j] << "] ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void grayLevelHistogram()
{
    cout << "Show gray level histogram: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            h[image[i][j]] = h[image[i][j]] + 1;
        }
    }
    for (auto &x : h)
    {
        cout << x.first << ": " << x.second << endl;
    }

    cout << endl;
}

void calculateT()
{
    int total = 0;
    for (auto &x : h)
    {
        total += x.second;
        t[x.first] = total;
    }
}

int calculateFg(int g, double tb)
{
    int b = round(g / tb) - 1;
    return max(0, b);
}

void calculateF(int tb)
{
    for (auto &x : t)
    {
        f[x.first] = calculateFg(x.second, tb);
    }
}

void onGrayBalance(int level)
{
    cout << "on gray balance" << endl;
    double tb = m * n / level;
    calculateT();
    calculateF(tb);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            image[i][j] = f[image[i][j]];
        }
    }
}

int main()
{
    // inputImage();
    showImage();
    grayLevelHistogram();
    onGrayBalance(5);
    showImage();
    return 0;
}