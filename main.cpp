#include <iostream>
#include <fstream>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <iomanip>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
const ll N = 1e5 + 5;
const int INF = 1e9;
const ld PI = 3.1415926535;
int n;

struct Vector {
    double x;
    double y;

    Vector() {}

    Vector(double _x, double _y) {
        x = _x;
        y = _y;
    }
};

struct point {
    long double x;
    long double y;

    point() {}

    point(long  double _x, long double _y) {
        x = _x;
        y = _y;
    }
};

struct line_segment {
    double ax;
    double ay;
    double bx;
    double by;

    line_segment() {}

    line_segment(double _ax, double _ay, double _bx, double _by) {
        ax = _ax;
        ay = _ay;
        bx = _bx;
        by = _by;
    }
};

Vector operator+(Vector a, Vector b) {
    return Vector(a.x + b.x, a.y + b.y);
}

Vector &operator+=(Vector &a, Vector b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

double operator*(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double operator^(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

ostream &operator<<(ostream &stream, Vector a) {
    stream << a.x << ' ';
    stream << a.y;
    return stream;
}

ld vector_leight(double ax, double ay, double bx, double by) {
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

ld P_leight(double ax, double ay, double a1, double b1, double c1) {
    return (abs(a1 * ax + b1 * ay + c1)) / sqrt(a1 * a1 + b1 * b1);
}

Vector vector_maker(double x1, double y1, double x2, double y2) {
    return Vector(x2 - x1, y2 - y1);
}
//Vector operator-(Vector& a, Vector& b) {
//    return Vector(b.x - a.x, b.y - a.y);
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ld s2 = 0;
    cin >> n;
    point x[n + 2];
    for (int i = 0; i < n; i++) {
        cin >> x[i].x >> x[i].y;
    }
    for (int i = 1; i < n; i++) {
        ld s = ((x[i - 1].y + x[i].y) * (x[i - 1].x - x[i].x))/2;
            s2+= s;
    }
    ld s = ((x[n - 1].y + x[0].y) * (x[n - 1].x - x[0].x))/2;
    s2+= s;
    cout << fixed << setprecision(8)  << abs(s2) << '\n';
    return 0;
}