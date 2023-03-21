#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int cross_product(Point a, Point b, Point c) {
    int x1 = b.x - a.x;
    int y1 = b.y - a.y;
    int x2 = c.x - a.x;
    int y2 = c.y - a.y;
    return x1 * y2 - x2 * y1;
}

bool compare_points(Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

vector<Point> convex_hull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return points;

    sort(points.begin(), points.end(), compare_points);

    vector<Point> hull;

    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross_product(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int lower_hull_size = hull.size();

    for (int i = n-2; i >= 0; --i) {
        while (hull.size() > lower_hull_size && cross_product(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back();
    return hull;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convex_hull(points);

    set <pair<int,int>> my;
    for (int i = 0; i < hull.size(); ++i) {
        int x1 = hull[i].x;
        int y1 = hull[i].y;
        my.insert({x1, y1});
    }

    cout << hull.size() << endl;
    for(auto it:hull){
        cout << "(" << it.x << ", " << it.y << ")" << endl;
    }


    return 0;
}
