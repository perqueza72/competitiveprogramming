#include <bits/stdc++.h>

using namespace std;

const int EPSILON = 1e-10;

struct Point
{
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point() {}

    void operator()(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

struct Line
{
    int a = 0;
    int b = 0;
    int c = 0;

    void operator=(const Line &l)
    {
        this->a = l.a;
        this->b = l.b;
        this->c = l.c;
    }

};

void printLine(const Line &l){
    cout << "a: " << l.a << " b: " << l.b << " c: " << l.c << "\n";
}

Line getLine(const Point &p, const Point &q)
{
    int c = q.y*p.x-p.y*q.x;

    // cout << "p: " << p.x << " " << p.y << "\n";
    // cout << "q: " << q.x << " " << q.y << "\n";
    // cout << "m: " << m << endl;
    Line l;
    l.a = p.y-q.y;
    l.b = q.x-p.x;
    l.c = c;

    return l;
};

int determinante(const Point &p, const Point &q)
{
    return  p.x * q.y - q.x * p.y;
}

bool isParalela(const Line &l1, const Line &l2, pair<double, double> &r, bool &changed)
{
    Point p1(l1.c, l2.c), p2(l1.b, l2.b);
    Point p3(l1.a, l2.a), p4(l1.c, l2.c);
    Point p5(l1.b, l2.b), p6(l1.a, l2.a);

    int a = determinante(p1, p2);
    int b = determinante(p3, p4);
    int c = determinante(p5, p6);

    // printLine(l1);
    // printLine(l2);
    // cout << a << " " << b << " " << c << endl;

    if (c == 0)
    {
        if (a == 0 && b == 0)
            return false;
        return true;
    }

    changed = true;
    r.first = (double)a / (double)c;
    r.second =(double)b / (double)c;

    return false;
}

void readPoint(Point &p)
{
    cin >> p.x >> p.y;
}

int main()
{

    int n;
    bool change;
    Line l1, l2;
    Point p1, p2, p3, p4;
    pair<double, double> r;
    cin >> n;

    cout << "INTERSECTING LINES OUTPUT\n";
    cout.precision(2);
    for (int i = 0; i < n; i++)
    {
        readPoint(p1);
        readPoint(p2);
        l1 = getLine(p1, p2);

        readPoint(p3);
        readPoint(p4);
        l2 = getLine(p3, p4);

        change = false;
        bool paralela = isParalela(l1, l2, r, change);

        if (paralela)
            cout << "NONE\n";
        else if (!change)
            cout << "LINE\n";
        else
            cout << fixed << "POINT " << r.first << " " << r.second << "\n";
    }
    cout << "END OF OUTPUT\n";

    return 0;
}