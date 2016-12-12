#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-7

typedef long long ll;

bool equals(double x, double y)
{
    return fabs(x - y) < EPS;
}

class Point
{
public:
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

double D(const Point &P, const Point &Q, const Point &R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

double angle(const Point& P, const Point& A, const Point& B)
{
    auto ux = P.x - A.x;
    auto uy = P.y - A.y;

    auto vx = P.x - B.x;
    auto vy = P.y - B.y;

    auto num = ux * vx + uy * vy;
    auto den = hypot(ux, uy) * hypot(vx, vy);

    // Caso especial: se den == 0, algum dos vetores é degenerado: os dois
    // pontos são iguais. Neste caso, o ângulo não está definido

    return acos(num / den);
}

class Polygon {
public:
    vector<Point> vertices;
    int n = 0;

    // O parâmetro deve conter os n vértices do polígono
    Polygon(const vector<Point>& vs) : vertices(vs), n(vs.size())
    {
        vertices.push_back(vertices[0]);
    }

    Polygon() : n(0)
    {
    }

    double area() const
    {
        double a = 0;
        for (int i = 0; i < n; ++i) {
            a += vertices[i].x * vertices[i+1].y;
            a -= vertices[i+1].x * vertices[i].y;
        }

        return 0.5 * fabs(a);
    }

    bool contains(const Point& P) const
    {
        if (n < 3)
            return false;

        auto sum = 0.0;

        for (int i = 0; i < n; ++i)
        {
            auto d = D(P, vertices[i], vertices[i + 1]);

            // Pontos sobre as arestas ou vértices são considerados interiores
            if (equals(d, 0))
                return true;

            auto a = angle(P, vertices[i], vertices[i + 1]);

            sum += d > 0 ? a : -a;
        }

        return equals(fabs(sum), 2*PI);
    }
};

Point intersection(const Point& P, const Point& Q, const Point& A, const Point& B)
{
    auto a = B.y - A.y;
    auto b = A.x - B.x;
    auto c = B.x * A.y - A.x * B.y;
    auto u = fabs(a * P.x + b * P.y + c);
    auto v = fabs(a * Q.x + b * Q.y + c);

    return Point((P.x * v + Q.x * u)/(u + v), (P.y * v + Q.y * u)/(u + v));
}

Polygon cut_polygon(const Polygon& P, const Point& A, const Point& B)
{
    vector<Point> points;

    for (int i = 0; i < P.n; ++i) {
        auto d1 = D(A, B, P.vertices[i]);
        auto d2 = D(A, B, P.vertices[i + 1]);

        // Vértice à esquerda da reta
        if (d1 > -EPS)
            points.push_back(P.vertices[i]);

        // A aresta cruza a reta
        if (d1 * d2 < -EPS)
            points.push_back(intersection(P.vertices[i], P.vertices[i+1], A, B));
    }

    return points.empty() ? Polygon() : Polygon(points);
}

int main()
{    
    int tc = 1;
    int N, W, H, x, y;
    while (cin >> N >> W >> H >> x >> y) {
        Point p(x,y);
        Polygon pol({Point(0,0), Point(W, 0), Point(W, H), Point(0,H)});
        for (int i = 0; i < N; i++) {
            Point P, Q;
            cin >> P.x >> P.y >> Q.x >> Q.y;

            Polygon left = cut_polygon(pol, P, Q);
            if (left.n >= 3 && left.contains(p)) {
                pol = left;
                continue;
            }
            
            Polygon right = cut_polygon(pol, Q, P);
            if (right.n >= 3 && right.contains(p)) pol = right;
        }

        printf("Case #%d: %.3f\n", tc++, pol.area());
    }
    
    return 0;
}
