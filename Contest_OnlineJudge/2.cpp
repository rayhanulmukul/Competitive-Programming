#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

class Point
{
public:
    int x;
    int y;
};
int orientation(Point p, Point q, Point r)
{
    int ori = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (ori == 0)
        return 0;
    return (ori > 0) ? 1 : 2;
}
int distance(Point a, Point b, Point c)
{
    int x1 = a.x - b.x;
    int y1 = a.y - b.y;
    int dist1 = (y1 * y1) + (x1 * x1);
    int y2 = a.y - c.y;
    int x2 = a.x - c.x;
    int dist2 = (y2 * y2) + (x2 * x2);
    return dist1 - dist2;
}
bool comp(Point a, Point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int main()
{
    // code
    int T;
    cin >> T;

    while (T--)
    {
        int n, i;
        cin >> n;
        Point p[n];
        vector<Point> chull;
        for (i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        if (n > 3)
        {
            int xmin = 10000, xminindex;
            for (i = 0; i < n; i++)
            {
                if (p[i].x < xmin)
                {
                    xmin = p[i].x;
                    xminindex = i;
                }
                if (xmin == p[i].x)
                {
                    if (p[i].y < p[xminindex].y)
                        xminindex = i;
                }
            }

            int P = xminindex;
            int Q;

            bool flag = 1, possible = 1;
            chull.push_back(p[P]);
            while (P != xminindex || flag)
            {
                flag = 0;

                Q = (P + 1) % n;
                for (i = 0; i < n; i++)
                {
                    if (orientation(p[P], p[i], p[Q]) == 2)
                    {
                        Q = i;
                        // change=1;
                    }
                    else if (orientation(p[P], p[i], p[Q]) == 0) // colinear case
                    {
                        int dist = distance(p[P], p[Q], p[i]);

                        if (dist < 0)
                        { // if condition is like
                          // a.-------b.------c.
                          // we get dist<0 as ab-ac<0
                          // so we transfer next to c and proceed
                          // as if we don't then it takes the point next to a as next

                            Q = i;
                        }
                    }
                }

                P = Q;
                if (P == xminindex)
                    break;
                chull.push_back(p[P]);
            }
            if (possible)
            {
                sort(chull.begin(), chull.end(), comp);
                set<pair<int, int>> hullset;
                for (i = 0; i < chull.size(); i++)
                {
                    hullset.insert(make_pair(chull[i].x, chull[i].y));
                }
                // auto it;
                set<pair<int, int>>::iterator it2 = hullset.begin(), it3 = hullset.begin(), it4;
                it2++;
                for (auto it : hullset)
                {
                    bool x = true;

                    if (it2 == hullset.end() && x)
                        cout << it.first << ' ' << it.second << '\n';
                    else if (x)
                        cout << it.first << ' ' << it.second << ',' << ' ';

                    it2++;
                    it3++;
                }
            }
            else
            {
                cout << -1 << '\n';
            }
        }

        if (n == 3 && !chull.size())
        {
            bool cl = false;
            sort(p, p + n, comp);
            for (i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (p[i].x == p[j].x && p[i].y == p[j].y)
                    {
                        cl = true;
                        break;
                    }
                }
                if (cl)
                    break;
            }
            if (!cl)
            {
                for (i = 0; i < n; i++)
                {
                    if (i == n - 1)
                        cout << p[i].x << ' ' << p[i].y << '\n';
                    else
                        cout << p[i].x << ' ' << p[i].y << ',' << ' ';
                }
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (n < 3)
            cout << -1 << '\n';
    }
    return 0;
}