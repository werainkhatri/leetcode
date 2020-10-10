#include <bits/stdc++.h>

using namespace std;

int findRadius(vector<int> &A, vector<int> &H)
{
    sort(A.begin(), A.end());
    sort(H.begin(), H.end());
    int m = 0;
    vector<int> res(A.size(), INT_MAX);
    for (int a = 0, h = 0; a < A.size() && h < H.size();)
    {
        if (A[a] <= H[h])
        {
            res[a] = H[h] - A[a];
            a++;
        }
        else
            h++;
    }

    for (int a = A.size() - 1, h = H.size() - 1; a >= 0 && h >= 0;)
    {
        if (A[a] >= H[h])
        {
            res[a] = min(res[a], A[a] - H[h]);
            a--;
        }
        else
            h--;
    }
    return *max_element(res.begin(), res.end());
}

int main()
{
    vector<int> houses{1, 2, 3, 4};
    vector<int> heaters{1, 4};
    cout << findRadius(houses, heaters);
    return 0;
}