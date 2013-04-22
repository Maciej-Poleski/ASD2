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
#include <tr1/memory>
#include <tr1/functional>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

namespace
{
using namespace Wrapper;

static int64_t mul(std::pair<int32_t,int32_t> a,std::pair<int32_t,int32_t> b)
{
    return static_cast<int64_t>(a.first) * b.second -
           static_cast<int64_t>(b.first) * a.second;
}

static std::pair<int32_t,int32_t> sub(std::pair<int32_t,int32_t> a,std::pair<int32_t,int32_t> b)
{
    return std::make_pair(a.first-b.first,a.second-b.second);
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
        size_t n;
        in>>n;
        std::vector<std::pair<int32_t,int32_t> > points;
        for(size_t i=0; i<n; ++i)
        {
            int32_t a,b;
            in>>a>>b;
            points.push_back(std::make_pair(a,b));
        }
        std::sort(points.begin(),points.end());
        points.erase(std::unique(points.begin(),points.end()),points.end());
        std::vector<std::pair<int32_t,int32_t> > convexUpper;
        for(std::vector<std::pair<int32_t,int32_t> >::const_iterator i=points.begin(),e=points.end(); i!=e; ++i)
        {
            if(convexUpper.size()<1)
                convexUpper.push_back(*i);
            else
            {
                if(convexUpper.back().first==i->first)
                {
                    convexUpper.pop_back();
                    --i;
                }
                else if(convexUpper.size()>1)
                {
                    if(mul(sub(convexUpper.back(),convexUpper[convexUpper.size()-2]),sub(*i,convexUpper.back()))>0)
                    {
                        convexUpper.pop_back();
                        --i;
                    }
                    else
                    {
                        convexUpper.push_back(*i);
                    }
                }
                else
                    convexUpper.push_back(*i);
            }
        }
        std::vector<std::pair<int32_t,int32_t> > convexLower;
        for(std::vector<std::pair<int32_t,int32_t> >::const_reverse_iterator i=points.rbegin(),e=points.rend(); i!=e; ++i)
        {
            if(convexLower.size()<1)
                convexLower.push_back(*i);
            else
            {
                if(convexLower.back().first==i->first)
                {
                    convexLower.pop_back();
                    --i;
                }
                else if(convexLower.size()>1)
                {
                    if(mul(sub(convexLower.back(),convexLower[convexLower.size()-2]),sub(*i,convexLower.back()))>0)
                    {
                        convexLower.pop_back();
                        --i;
                    }
                    else
                    {
                        convexLower.push_back(*i);
                    }
                }
                else
                    convexLower.push_back(*i);
            }
        }
        convexUpper.insert(convexUpper.end(),convexLower.begin(),convexLower.end());
        convexUpper.push_back(convexUpper.front());
        int64_t result=0;
        for(std::vector<std::pair<int32_t,int32_t> >::const_iterator i1=convexUpper.begin(),i2=i1+1,e=convexUpper.end();i2!=e;++i1,++i2)
        {
            result+=mul(*i2,*i1);
        }
        out<<result<<'\n';
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
