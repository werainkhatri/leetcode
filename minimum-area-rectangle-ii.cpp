#include <bits/stdc++.h>

using namespace std;

double DOUBLE_MAX = numeric_limits<double>::max();
double MAX_SLOPE = 40001;

class Line
{
public:
    int x1, y1, x2, y2;
    double len, slope;

    Line(vector<int> p1, vector<int> p2)
    {
        if (p2[0] > p1[0] || p2[1] > p1[1])
        {
            x1 = p1[0];
            y1 = p1[1];
            x2 = p2[0];
            y2 = p2[1];
        }
        else
        {
            x1 = p2[0];
            y1 = p2[1];
            x2 = p1[0];
            y2 = p1[1];
        }
        len = sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
        if (x1 == x2)
            slope = MAX_SLOPE;
        else
            slope = (double)(y2 - y1) / (double)(x2 - x1);
    }

    void p()
    {
        cout << x1 << y1 << x2 << y2 << endl;
    }
};

double slope(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
        return MAX_SLOPE;
    return (double)(y2 - y1) / (double)(x2 - x1);
}

double length(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

double minAreaFreeRect(vector<vector<int>> &points)
{
    double minArea = DOUBLE_MAX;
    unordered_map<double, vector<Line>> slopes;
    for (int i = 0; i < points.size() - 1; i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            Line line(points[i], points[j]);
            slopes[line.slope].push_back(line);
        }
    }

    for (auto i = slopes.begin(); i != slopes.end(); i++)
    {
        if (i->second.size() < 2)
            continue;
        vector<Line> ls = i->second;
        cout << "si:" << i->first << endl;
        for (int j = 0; j < ls.size() - 1; j++)
        {
            for (int k = j + 1; k < ls.size(); k++)
            {
                if (ls[j].len != ls[k].len)
                    continue;
                double s = slope(ls[j].x1, ls[j].y1, ls[k].x1, ls[k].y1);
                if (i->first == 0 && s == MAX_SLOPE || i->first == MAX_SLOPE && s == 0)
                {
                    double area = ls[j].len * length(ls[j].x1, ls[j].y1, ls[k].x1, ls[k].y1);
                    if (area < minArea)
                        minArea = area;
                }
                else if (s != MAX_SLOPE)
                {
                    double s2 = round(i->first * 100000) / 100000;
                    double rs = -round((1 / s) * 100000) / 100000;
                    if (s2 == rs)
                    {
                        double area = ls[j].len * length(ls[j].x1, ls[j].y1, ls[k].x1, ls[k].y1);
                        if (area < minArea)
                            minArea = area;
                    }
                }
            }
        }
    }
    return minArea == DOUBLE_MAX ? 0 : minArea;
}

int main()
{
    vector<vector<int>> points{{3, 3}, {2, 2}, {0, 0}, {2, 1}, {3, 0}, {1, 3}, {3, 1}, {0, 1}};
    cout << minAreaFreeRect(points) << endl;
    return 0;
}