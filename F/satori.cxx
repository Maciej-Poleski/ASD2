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

namespace
{
using namespace Wrapper;

static uint32_t n1,n2,m;

static std::vector<uint32_t> *G;
static bool *V;
static uint32_t *sk;

static bool dfs(uint32_t x)
{
    if(V[x])
        return false;
    V[x]=true;
    for(std::vector<uint32_t>::iterator i=G[x].begin(),e=G[x].end(); i!=e; ++i)
    {
        if(sk[*i]==0 || dfs(sk[*i]))
        {
            sk[x]=*i;
            sk[*i]=x;
            return true;
        }
    }
    return false;
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
        uint32_t n;
        in>>n>>m;
        n1=n2=n;
        G=new std::vector<uint32_t>[n1+n2+1];
        V=new bool[n1+n2+1];
        sk=new uint32_t[n1+n2+1];
        for(size_t i=0; i<=n1+n2; ++i)
            sk[i]=0;
        for(size_t i=0; i<m; ++i)
        {
            uint32_t x,y;
            in>>x>>y;
            G[x].push_back(y+n1);
            G[y+n1].push_back(x);
        }
        uint32_t result=0;
        for(bool found=true; found;)
        {
            found=false;
            for(size_t i=0; i<=n1+n2; ++i)
                V[i]=false;
            for(size_t i=1; i<=n1; ++i)
            {
                if(!V[i] && sk[i]==0)
                    if(dfs(i))
                    {
                        ++result;
                        found=true;
                    }
            }
        }
        out<<((result==n)?"TAK":"NIE")<<'\n';
        delete [] sk;
        delete [] V;
        delete [] G;
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
