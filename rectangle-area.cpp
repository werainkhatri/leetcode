#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int ABCD = (C - A) * (D - B);
    int EFGH = (G - E) * (H - F);

    int left = max<int>(A, E);
    int right = min<int>(G, C);
    int bottom = max<int>(F, B);
    int top = min<int>(D, H);

    // If overlap
    int overlap = 0;
    if (right > left && top > bottom)
        overlap = (right - left) * (top - bottom);

    return ABCD + EFGH - overlap;
}

int main()
{
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    cout << computeArea(a, b, c, d, e, f, g, h) << endl;
    return 0;
}