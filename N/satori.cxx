//Maciej Poleski
#ifdef DEBUG
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
    if(argc != 3)
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
// #include <tr1/memory>
// #include <tr1/functional>
// #include <tr1/unordered_map>
// #include <tr1/unordered_set>

namespace
{
using namespace Wrapper;

struct Circle
{
    int32_t x,y;
    int32_t r;  // defensywnie
    int32_t h;  // I tak jest padding

    std::vector<uint32_t> next;
    int32_t parent;
};

static Circle *input=0;
static size_t n;

struct Event
{
    uint32_t circleId;
    bool side;  // false=left, true=right

    Event() {}
    Event(uint32_t id,bool s) : circleId(id), side(s) {}
};

const bool operator<(const Event& lhs,const Event& rhs)
{
    int32_t lhsP=input[lhs.circleId].x+((!lhs.side)?(-input[lhs.circleId].r):(input[lhs.circleId].r));
    int32_t rhsP=input[rhs.circleId].x+((!rhs.side)?(-input[rhs.circleId].r):(input[rhs.circleId].r));
    return lhsP<rhsP;
}

struct Point
{
    uint32_t circleId;
    bool     upper;     // false=bottom,true=top

    Point(uint32_t id, bool u) : circleId(id), upper(u) {}
};

static uint64_t dist(int64_t x1,int64_t y1,int64_t x2,int64_t y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

/**
 * Najwyższy jest największy w relacji
 */
const bool operator<(const Point& lhs,const Point& rhs)
{
    if(lhs.circleId==rhs.circleId)
        return (!lhs.upper) &&  (rhs.upper);
    else if(dist(input[lhs.circleId].x,input[lhs.circleId].y,
                 input[rhs.circleId].x,input[rhs.circleId].y)>
            (static_cast<uint64_t>(input[lhs.circleId].r)+input[rhs.circleId].r)*
            (static_cast<uint64_t>(input[lhs.circleId].r)+input[rhs.circleId].r))
    {
        return input[lhs.circleId].y<input[rhs.circleId].y;
    }
    else
    {
        if(input[lhs.circleId].r>input[rhs.circleId].r)
            return !lhs.upper;
        else
            return rhs.upper;
    }
};

/**
 * @param c Dany walec
 * @param h Wysokość poziomu morza względem wysokości ojca @c c
 * @return Ilość wody w @c c i jego potomkach
 */
static int64_t calc(uint32_t c,uint32_t h)
{
    int64_t result=((input[c].h<0)?(-input[c].h):-(std::min<int32_t>(h,input[c].h)))*static_cast<int64_t>(input[c].r)*input[c].r;
    for(std::vector<uint32_t>::const_iterator i=input[c].next.begin(),e=input[c].next.end(); i!=e; ++i)
    {
        result+=calc(*i,std::max<int32_t>(0,h-input[c].h));
    }
    return result;
}

inline static void solution() __attribute__((optimize(3)));
inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while(z--)
    {
        in>>n;
        delete [] input;
        input=new Circle[n];
        Event *events=new Event[2*n];
        for(size_t i=0; i<n; ++i)
        {
            in>>input[i].x>>input[i].y>>input[i].r>>input[i].h;
            events[2*i]= Event(static_cast<uint32_t>(i),false);
            events[2*i+1]= Event(static_cast<uint32_t>(i),true);
        }
        std::sort(events,events+2*n);
        {
            // WARNING: Jak zachowa się set, gdy podczas pracy destruktora
            //          operator< powoduje UB?
            std::set<Point> points;
            for(const Event *i=events,*e=events+2*n; i!=e; ++i)
            {
                if(i->side)
                {
                    points.erase(Point(i->circleId,false));
                    points.erase(Point(i->circleId,true));
                }
                else
                {
                    std::pair<std::set<Point>::iterator,bool> t=points.insert(Point(i->circleId,false));
                    check(t.second);
                    std::set<Point>::iterator pp=t.first;
                    ++pp;
                    if(pp==points.end())
                    {
                        // nie ma ojca
                        input[i->circleId].parent=-1;
                    }
                    else
                    {
                        if(pp->upper)
                        {
                            // pp jest punktem naszego parenta
                            input[i->circleId].parent=pp->circleId;
                            input[pp->circleId].next.push_back(i->circleId);
                        }
                        else
                        {
                            // pp jest punktem naszego brata
                            input[i->circleId].parent=input[pp->circleId].parent;
                            input[input[pp->circleId].parent].next.push_back(i->circleId);
                        }
                    }
                    points.insert(Point(i->circleId,true));
                }
            }
        }

        size_t result=0;
        for(size_t i=0; i<n; ++i)
        {
            if(input[i].parent==-1)
                result+=calc(i,0);
        }
        out<<result<<'\n';
        delete [] events;
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

