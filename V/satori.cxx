//Maciej Poleski
#ifdef DEBUG
#define _GLIBCXX_CONCEPT_CHECKS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
namespace
{
namespace Wrapper
{
std::ifstream in;
std::ofstream out;
}
void init(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cerr << "Potrzeba dokładnie dwóch argumentów\n";
        std::abort();
    }
    Wrapper::in.open(argv[1]);
    Wrapper::out.open(argv[2]);
}
}
#define check(x) assert(x)
#else
#ifndef NDEBUG
#define NDEBUG
#endif
#define check(x)
#include <iostream>
namespace
{
namespace Wrapper
{
std::istream& in = std::cin;
std::ostream& out = std::cout;
}
}
#endif

#include <tr1/cstdint>

namespace
{
namespace Wrapper
{
typedef std::tr1::uint_fast64_t uint_fast64_t;
typedef std::tr1::uint_fast32_t uint_fast32_t;
typedef std::tr1::uint_fast16_t uint_fast16_t;
typedef std::tr1::uint_fast8_t uint_fast8_t;

typedef std::tr1::uint64_t uint64_t;
typedef std::tr1::uint32_t uint32_t;
typedef std::tr1::uint16_t uint16_t;
typedef std::tr1::uint8_t uint8_t;

typedef std::tr1::int_fast64_t int_fast64_t;
typedef std::tr1::int_fast32_t int_fast32_t;
typedef std::tr1::int_fast16_t int_fast16_t;
typedef std::tr1::int_fast8_t int_fast8_t;

typedef std::tr1::int64_t int64_t;
typedef std::tr1::int32_t int32_t;
typedef std::tr1::int16_t int16_t;
typedef std::tr1::int8_t int8_t;

typedef std::size_t size_t;
}

}

#include <string>
#include <algorithm>
#include <limits>
#include <locale>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <tr1/random>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <tr1/memory>
#include <tr1/functional>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <complex>

namespace
{
using namespace Wrapper;

static size_t n, R;

typedef double double_t;
static const double_t EPS = 1e-9;

struct Point   // punkt w 2D
{
    double_t x, y;
    Point(double_t xi, double_t yi): x(xi), y(yi) {}
    Point() {}
    double_t norm() const
    {
        return x * x + y * y; // kwadrat(!) normy euklidesowej
    }
};

static bool operator==(const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

static bool operator!=(const Point& lhs, const Point& rhs)
{
    return !(lhs == rhs);
}

static Point operator+(const Point& a, const Point& b)
{
    return Point(a.x + b.x, a.y + b.y);
}
static Point operator-(const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y);
}
static Point operator*(const Point& a, double_t f)
{
    return Point(a.x * f, a.y * f);
}

static Point cross(const Point& a)
{
    return Point(-a.y, a.x);    // obrot o 90 stopni
}

struct circle   // okrag w 2D
{
    Point c;
    double_t r; // srodek, promien
};

// Przeciecie dwoch okregow. Zwraca liczbe punktow. Zalozenie: c1.c!=c2.c
static int intersection(const circle& c1, const circle& c2, Point result[]/*OUT*/)
{
    using std::swap;
    double_t d = (c2.c - c1.c).norm(), r1 = c1.r * c1.r / d, r2 = c2.r * c2.r / d;
    Point u = c1.c * ((r2 - r1 + 1) * 0.5) + c2.c * ((r1 - r2 + 1) * 0.5);
    if (r1 > r2)
        swap(r1, r2);
    double_t a = (r1 - r2 + 1) * 0.5;
    a *= a;
    if (a >= r1 + EPS)
        return 0;
    if (a > r1 - EPS)
    {
        result[0] = u;
        return 1;
    }
    Point v = cross(c2.c - c1.c);
    double_t h = sqrt(r1 - a);
    result[0] = u + v * h;
    result[1] = u - v * h;
    return 2;
}

static Point* points;

struct Event
{
    Point point;
    size_t id;
    size_t mainCircle;
    bool end;
};

static bool atan2Compare(const Event& lhs, const Event& rhs)
{
    if (lhs.point != rhs.point)
    {
        double_t lhs_x = lhs.point.x - points[lhs.mainCircle].x;
        double_t lhs_y = lhs.point.y - points[lhs.mainCircle].y;
        double_t rhs_x = rhs.point.x - points[rhs.mainCircle].x;
        double_t rhs_y = rhs.point.y - points[rhs.mainCircle].y;
        if (lhs_y <= 0 && rhs_y > 0)
            return true;
        else if (lhs_y <= 0)
            return lhs_x < rhs_x;
        else if (lhs_y > 0 && rhs_y <= 0)
            return false;
        else if (lhs_y > 0)
        {
            if (rhs_y < 0)
            {
                return false;
            }
            // rhs_y>=0
            if (rhs_y > 0)
                return lhs_x > rhs_x;
            else if (rhs_y == 0)
                return false;
        }
//         return atan2(lhs_y, lhs_x) < atan2(rhs_y, rhs_x);
    }
    else
    {
        return lhs.end < rhs.end;
    }
}

static bool atan2ComparePoints(const Point& lhs, const Point& rhs)
{
    return atan2(lhs.y, lhs.x) < atan2(rhs.y, rhs.x);
}

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while (z--)
    {
        in >> n >> R;
        points = new Point[n];
        for (size_t i = 0; i < n; ++i)
            in >> points[i].x >> points[i].y;

        size_t result = 0;

        for (size_t i = 0; i < n; ++i)
        {
            Event* events = new Event[2 * n];
            size_t p = 0;
            for (size_t j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                Point out[2];
                int c = intersection( {points[i], R}, {points[j], R}, out);
                if (c == 1)
                {
                    events[p++] = {out[0], j, i, false};
                    events[p++] = {out[0], j, i, true};
                }
                else if (c == 2)
                {
                    using std::swap;
                    Point temp[3] = {out[0] - points[i], out[1] - points[i], points[j] - points[i]};
                    if (atan2ComparePoints(temp[2], temp[1]))
                        swap(temp[2], temp[1]);
                    if (atan2ComparePoints(temp[1], temp[0]))
                        swap(temp[1], temp[0]);
                    if (atan2ComparePoints(temp[2], temp[1]))
                        swap(temp[2], temp[1]);
                    bool s;
                    if ((temp[0] == out[0] - points[i]) && (temp[1] == points[j] - points[i]))
                        s = true;
                    else if ((temp[0] == points[j] - points[i]) && (temp[1] == out[1] - points[i]))
                        s = true;
                    else if ((temp[0] == out[1] - points[i]) && (temp[1] == out[0] - points[i]))
                        s = true;
                    else
                        s = false;
                    events[p++] = {out[0], j, i, !s};
                    events[p++] = {out[1], j, i, s};
                }
            }

            std::sort(events, events + p, atan2Compare);

            //             out<<"i: "<<i<<'\n';
            //             for(size_t j=0; j<p; ++j)
            //             {
            //                 out<<"x: "<<events[j].point.x-points[events[j].mainCircle].x<<" y: "<<events[j].point.y-points[events[j].mainCircle].y<<'\n';
            //             }

            size_t current = 0;
            bool* V = new bool[n];
            for (size_t j = 0; j < n; ++j)
                V[j] = false;

            std::vector<Event> e2(events, events + p);
            e2.insert(e2.end(), events, events + p);

            for (std::vector<Event>::const_iterator ii = e2.begin(), e = e2.end(); ii != e; ++ii)
            {
                if (ii->end && V[ii->id])
                {
                    --current;
                    V[ii->id] = false;
                }
                else if ((!ii->end) && (!V[ii->id]))
                {
                    result = std::max(++current, result);
                    V[ii->id] = true;
                }
            }

            delete [] V;
            delete [] events;
        }

        out << result + 1 << '\n';

        delete [] points;
    }
}

} // namespace

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
#ifdef DEBUG
    init(argc, argv);
#else
    (void)argc;
    (void)argv;
#endif
    solution();
    return 0;
}
