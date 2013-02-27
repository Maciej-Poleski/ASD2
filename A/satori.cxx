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

uint32_t C[101][101];
uint32_t F[101][101];
bool V[101];
uint8_t prev[101];

uint_fast16_t n;
uint_fast32_t flow;
uint_fast32_t foundFlow;

static int32_t cf(uint_fast16_t a, uint_fast16_t b)
{
    return static_cast<int32_t>(C[a][b])-F[a][b];
}

struct Node
{
    uint8_t v;
    uint8_t p;
    uint32_t flow;
};

static std::vector<uint8_t> findPath()
{
    std::vector<uint8_t> result;
    std::queue<Node> queue;
    queue.push( {1,0,std::numeric_limits< uint32_t>::max()});
    memset(V+2,0,n-1);
    while(!queue.empty())
    {
        Node node=queue.front();
        queue.pop();
        prev[node.v]=node.p;
        if(node.v==n)
        {
            for(uint8_t v=n; v!=0; v=prev[v])
                result.push_back(v);
            foundFlow=node.flow;
            break;
        }
        for(size_t j=1; j<=n; ++j)
        {
            if(V[j])
                continue;
            if(cf(node.v,j)>0)
            {
                V[j]=true;
                queue.push( {j,node.v,std::min(node.flow,static_cast<uint32_t>(cf(node.v,j)))});
            }
        }
    }
    return result;
}

inline static void solution() __attribute__((optimize(3)));
inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    while(z--)
    {
        in>>n;
        for(size_t i=1; i<=n; ++i)
            for(size_t j=1; j<=n; ++j)
            {
                in>>C[i][j];
                F[i][j]=0;
            }
        flow=0;
        V[1]=true;
        for(;;)
        {
            std::vector<uint8_t> path=findPath();
            if(path.empty())
                break;
            flow+=foundFlow;
            for(size_t i=path.size()-1;i>0;--i)
            {
                uint8_t a=path[i];
                uint8_t b=path[i-1];
                F[a][b]+=foundFlow;
                F[b][a]-=foundFlow;
                check(cf(a,b)>=0);
                check(cf(b,a)>=0);
            }
        }
        out<<flow<<'\n';
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
