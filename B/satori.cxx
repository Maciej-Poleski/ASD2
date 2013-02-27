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

uint_fast16_t n,m;

struct Edge
{
    uint8_t x,y;
    uint16_t c;
    int16_t f;
    std::list<Edge>::iterator i;

    Edge(uint_fast8_t x,uint_fast8_t y,uint_fast16_t c) : x(x),y(y),c(c),f(0) {}

    uint16_t cf() const
    {
        return c==std::numeric_limits<uint16_t>::max()?std::numeric_limits<uint16_t>::max():c-f;
    }
};

struct Node
{
    char map;
    std::list<Edge> edges;
};

Node G[52][52];
bool V[52][52];
std::list<Edge>::iterator prev[52][52];

static void makeEdge(uint_fast8_t x1,uint_fast8_t y1,uint_fast8_t x2,uint_fast8_t y2,uint16_t c=1)
{
    Edge e1(x2,y2,c);
    Edge e2(x1,y1,c);
    G[x1][y1].edges.push_front(e1);
    G[x2][y2].edges.push_front(e2);
    G[x1][y1].edges.front().i=G[x2][y2].edges.begin();
    G[x2][y2].edges.front().i=G[x1][y1].edges.begin();
}

struct Pack
{
    std::pair<uint8_t,uint8_t> v;
    std::list<Edge>::iterator prev;
    uint16_t flow;
};

static uint16_t findPath()
{
    for(size_t i=0; i<=n+1; ++i)
        for(size_t j=0; j<=m+1; ++j)
            V[i][j]=false;
    V[0][0]=true;
    std::queue<Pack> queue;
    queue.push( {{0,0},
        G[0][0].edges.end(),
        std::numeric_limits<uint16_t>::max()
    });
    while(!queue.empty())
    {
        Pack p=queue.front();
        queue.pop();
        prev[p.v.first][p.v.second]=p.prev;
        if(p.v==std::make_pair(static_cast<uint8_t>(n+1),static_cast<uint8_t>(m+1)))
        {
            for(std::list<Edge>::iterator i=p.prev,e=G[0][0].edges.end(); i!=e; i=prev[i->i->x][i->i->y])
            {
                i->f+=p.flow;
                i->i->f-=p.flow;
                check(i->cf()>=0);
                check(i->i->cf()>=0);
            }
            return p.flow;
        }
        for(std::list<Edge>::iterator i=G[p.v.first][p.v.second].edges.begin(),e=G[p.v.first][p.v.second].edges.end(); i!=e; ++i)
        {
            if(V[i->x][i->y])
                continue;
            if(i->cf()>0)
            {
                V[i->x][i->y]=true;
                queue.push( {std::make_pair(i->x,i->y),i,std::min(p.flow,static_cast<uint16_t>(i->cf()))});
            }
        }
    }
    return 0;
}

static uint16_t doFlow()
{
    uint16_t flow=0;
    for(uint16_t foundFlow=findPath(); foundFlow; foundFlow=findPath())
    {
        flow+=foundFlow;
    }
    return flow;
}

inline static void solution() __attribute__((optimize(3)));
inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    while(z--)
    {
        in>>n>>m;
        for(size_t i=0;i<=n+1;++i)
            for(size_t j=0;j<=m+1;++j)
                G[i][j].edges.clear();
        for(size_t i=1; i<=n; ++i)
        {
            for(size_t j=1; j<=m; ++j)
            {
                in>>G[i][j].map;
            }
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        for(size_t j=1; j<=m; ++j)
            G[0][j].map=G[n+1][j].map='x';
        for(size_t i=1; i<=n; ++i)
            G[i][0].map=G[i][m+1].map='x';
        G[0][0].map=G[0][m+1].map=G[n+1][0].map=G[n+1][m+1].map='!';
        for(size_t i=0; i<=n; ++i)
            for(size_t j=0; j<=m; ++j)
            {
                if(G[i][j].map=='!')
                    continue;
                if(G[i][j+1].map!='!')
                    makeEdge(i,j,i,j+1);
                if(G[i+1][j].map!='!')
                    makeEdge(i,j,i+1,j);
            }
        for(size_t i=0; i<=n+1; ++i)
            for(size_t j=0; j<=m+1; ++j)
            {
                if(G[i][j].map=='#')
                    makeEdge(i,j,0,0,std::numeric_limits<uint16_t>::max());
                else if(G[i][j].map=='x')
                    makeEdge(i,j,n+1,m+1,std::numeric_limits<uint16_t>::max());
            }
        out<<doFlow()<<'\n';
        for(size_t i=1; i<=n; ++i)
        {
            for(size_t j=1; j<=m; ++j)
            {
                if(V[i][j])
                    G[i][j].map='#';
                out<<G[i][j].map;
            }
            out<<'\n';
        }
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
