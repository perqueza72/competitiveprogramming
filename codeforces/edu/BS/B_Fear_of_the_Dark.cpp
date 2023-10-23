#include <bits/stdc++.h>

using namespace std;


struct Point{
    double x, y;

    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    Point(){}
};

double d(const Point &a, const Point &b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


Point p, l1, l2, o = Point(0.0, 0.0);
double calc(){
    double a = max(d(p, l1), d(o, l1));
    double b = max(d(p, l2), d(o, l2));
    double c = max( max(min(d(o, l1), d(o, l2)), min(d(p, l1), d(p, l2))), d(l1, l2)/2);

    return min(a, min(b, c));
}

int main(){
    int t;
    cin >> t;

    // Point a = Point(-1, -1), b = Point(4, 3);
    // cout << (d(a, b)/2) << endl;
    cout.precision(10);
    while(t--){
        cin >> p.x >> p.y;
        cin >> l1.x >> l1.y;
        cin >> l2.x >> l2.y;

        cout << fixed << calc() << "\n";
    }
}