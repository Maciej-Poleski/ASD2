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
void init(int argc, char **argv)
{
    if (argc != 3) {
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
std::istream &in = std::cin;
std::ostream &out = std::cout;
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

size_t n,R;

typedef double double_t;
const double_t EPS = 1e-9;

struct xy { // punkt w 2D
    double_t x, y;
    xy(double_t xi, double_t yi):x(xi), y(yi) {}
    xy() {}
    double_t norm() const {
        return x*x+y*y;    // kwadrat(!) normy euklidesowej
    }
};

typedef xy Point;

inline xy operator+(const xy&a, const xy&b) {
    return xy(a.x+b.x, a.y+b.y);
}
inline xy operator-(const xy&a, const xy&b) {
    return xy(a.x-b.x, a.y-b.y);
}
inline xy operator*(const xy&a, double_t f) {
    return xy(a.x*f, a.y*f);
}
inline xy operator/(const xy&a, double_t f) {
    return xy(a.x/f, a.y/f);
}
inline xy cross(const xy&a) {
    return xy(-a.y, a.x);    // obrot o 90 stopni
}
inline double_t operator*(const xy&a, const xy&b) {
    return a.x*b.x+a.y*b.y;
}
inline double_t det(const xy&a, const xy&b) {
    return a.x*b.y-b.x*a.y;
}

struct circle { // okrag w 2D
    Point c;
    double_t r; // srodek, promien
    circle(const Point&ci, double_t ri):c(ci), r(ri) {}
    circle() {}
    double_t length() const {
        return 2*M_PI*r;    // dlugosc
    }
    double_t area() const {
        return M_PI*r*r;    // pole kola
    }
};

// Przeciecie dwoch okregow. Zwraca liczbe punktow. Zalozenie: c1.c!=c2.c
int intersection(const circle &c1, const circle &c2, Point I[]/*OUT*/) {
    using std::swap;
    double_t d=(c2.c-c1.c).norm(), r1=c1.r*c1.r/d, r2=c2.r*c2.r/d;
    Point u=c1.c*((r2-r1+1)*0.5)+c2.c*((r1-r2+1)*0.5);
    if (r1>r2) swap(r1,r2);
    double_t a=(r1-r2+1)*0.5;
    a*=a;
    if (a>=r1+EPS) return 0;
    if (a>r1-EPS) {
        I[0]=u;
        return 1;
    }
    Point v=cross(c2.c-c1.c);
    double_t h=sqrt(r1-a);
    I[0]=u+v*h;
    I[1]=u-v*h;
    return 2;
}

Point *points;

struct Event
{
    Point point;
    size_t id;
};

static bool atan2Compare(const Event &lhs,const Event &rhs)
{
    return atan2(lhs.point.y,lhs.point.x)<atan2(rhs.point.y,rhs.point.x);
}

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while (z--) {
        in>>n>>R;
        points=new Point[n];
        for(size_t i=0;i<n;++i)
            in>>points[i].x>>points[i].y;

        size_t result=0;

        for(size_t i=0;i<n;++i)
        {
            Event *events=new Event[2*n];
            size_t p=0;
            for(size_t j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                Point out[2];
                int c=intersection({points[i],R},{points[j],R},out);
                if(c==1)
                {
                    events[p++]={out[0]-points[i],j};
                    events[p++]={out[0]-points[i],j};
                }
                else if(c==2)
                {
                    events[p++]={out[0]-points[i],j};
                    events[p++]={out[1]-points[i],j};
                }
            }
            // Być może punkty będą nachodzić, wtedy trzeba dodatkowo przydzielać priorytet
            std::sort(events,events+p,atan2Compare);

            out<<"i: "<<i<<'\n';
            for(size_t j=0;j<p;++j)
            {
                out<<"x: "<<events[j].point.x<<" y: "<<events[j].point.y<<'\n';
            }

            size_t current=0;
            bool *V=new bool[n];
            for(size_t j=0;j<n;++j)
                V[j]=false;

            for(size_t j=0;j<p;++j)
            {
                if(V[events[j].id])
                    --current;
                else
                {
                    result=std::max(++current,result);
                    V[events[j].id]=true;
                }
            }

            delete [] V;
            delete [] events;
        }

        out<<result+1<<'\n';

        delete [] points;
    }
}

} // namespace

int main(int argc, char **argv)
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





