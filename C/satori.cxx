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

struct Edge;
struct Vertex;

static uint_fast16_t n,m;

static int32_t L[100];
static int32_t R[100];

static int32_t Lsum,Rsum;

struct Edge
{
    int32_t c,f;
    uint8_t d;
    std::list<Edge>::iterator i;
    
    const int32_t cf() const
    {
        return c-f;
    }
    
    const uint8_t from() const
    {
        return i->d;
    }
    
    const uint8_t to() const
    {
        return d;
    }
};

struct Vertex
{
    int32_t e;
    uint16_t h;
    std::list<Edge>::iterator current;
    std::list<Edge> edges;
};

Vertex G[202];

static void makeDirected(uint_fast8_t from,uint_fast8_t to, int_fast32_t c)
{
    check(from!=to);
    Edge e1,e2;
    e1.d=to;
    e2.d=from;
    e1.c=c;
    e2.c=0;
    G[from].edges.push_front(e1);
    G[to].edges.push_front(e2);
    G[from].edges.front().i=G[to].edges.begin();
    G[to].edges.front().i=G[from].edges.begin();
}

static void makeUndirected(uint_fast8_t a,uint_fast8_t b,int_fast32_t c)
{
    check(a!=b);
    Edge e1,e2;
    e1.d=b;
    e2.d=a;
    e1.c=c;
    e2.c=c;
    G[a].edges.push_front(e1);
    G[b].edges.push_front(e2);
    G[a].edges.front().i=G[b].edges.begin();
    G[b].edges.front().i=G[a].edges.begin();
}

static void buildGraph(const size_t M)
{
    for(size_t i=0;i<=n+m+1;++i)
        G[i].edges.clear();
    for(size_t i=0;i<n;++i)
    {
        if(L[i]>0)
            makeDirected(0,i+1,L[i]);
        else if(L[i]<0)
            makeDirected(i+1,n+m+1,-L[i]);
    }
    for(size_t i=0;i<m;++i)
    {
        if(R[i]>0)
            makeDirected(n+1+i,n+m+1,R[i]);
        else if(R[i]<0)
            makeDirected(0,n+1+i,-R[i]);
    }
    for(size_t i=1;i<=n;++i)
        for(size_t j=n+1;j<=n+m;++j)
            makeUndirected(i,j,M);
}

void push(std::list<Edge>::iterator e)
{
    check(e->cf()>0);
    check(G[e->from()].e>0);
    check(G[e->from()].h==G[e->to()].h+1);
    int32_t df=std::min(G[e->from()].e,e->cf());
    e->f+=df;
    e->i->f-=df;
    G[e->from()].e-=df;
    G[e->to()].e+=df;
}

void relabel(uint_fast8_t u)
{
    check(G[u].e>0);
    uint16_t min=std::numeric_limits< uint16_t >::max();
    for(std::list<Edge>::iterator i=G[u].edges.begin(),e=G[u].edges.end();i!=e;++i)
    {
        if(i->cf()==0)
            continue;
        check(G[u].h<=G[i->d].h);
        min=std::min(min,G[i->to()].h);
    }
    G[u].h=1+min;
}

static void initializePreflow()
{
    for(size_t i=0;i<=n+m+1;++i)
    {
        G[i].e=G[i].h=0;
        for(std::list<Edge>::iterator ii=G[i].edges.begin(),e=G[i].edges.end();ii!=e;++ii)
        {
            ii->f=0;
        }
    }
    G[0].h=n+m+2;
    for(std::list<Edge>::iterator i=G[0].edges.begin(),e=G[0].edges.end();i!=e;++i)
    {
        i->f=i->c;
        i->i->f=-(i->c);
        G[i->to()].e=i->c;
        G[0].e-=i->c;
    }
}

static void discharge(uint_fast8_t u)
{
    while(G[u].e>0)
    {
        std::list<Edge>::iterator v=G[u].current;
        if(v==G[u].edges.end())
        {
            relabel(u);
            G[u].current=G[u].edges.begin();
        }
        else if(v->cf()>0 && (G[u].h==G[v->to()].h+1))
        {
            push(v);
        }
        else
        {
            ++G[u].current;
        }
    }
}

static void RTF()
{
    initializePreflow();
    std::list<uint8_t> L;
    for(size_t i=1;i<=n+m;++i)
    {
        L.push_back(i);
        G[i].current=G[i].edges.begin();
    }
    for(std::list<uint8_t>::iterator u=L.begin(),e=L.end();u!=e;++u)
    {
        uint16_t oldHeight=G[*u].h;
        discharge(*u);
        if(G[*u].h>oldHeight)
        {
            uint8_t t=*u;
            L.erase(u);
            L.push_front(t);
            u=L.begin();
        }
    }
}

static int32_t T[100][100];

static void prepareR()
{
    for(size_t i=1;i<=n;++i)
    {
        for(std::list<Edge>::iterator j=G[i].edges.begin(),e=G[i].edges.end();j!=e;++j)
        {
            if(j->to()>n && j->to() <=n+m)
            {
                T[i-1][j->to()-(n+1)]=j->f;
            }
        }
    }
}

/**
 * Warning: Ugly (non-portable) code
 */
static bool tryRTF(const size_t M)
{
    buildGraph(M);
    RTF();
    prepareR();
    for(int i=0;i<n;++i)
    {
        int rSum=0;
        for(int j=0;j<m;++j)
        {
            rSum+=T[i][j];
        }
        if(rSum!=L[i])
        {
            return false;
        }
    }
    for(int i=0;i<m;++i)
    {
        int cSum=0;
        for(int j=0;j<n;++j)
        {
            cSum+=T[j][i];
        }
        if(cSum!=R[i])
        {
            return false;
        }
    }
    return true;
}


static void printResults()
{
    for(size_t i=0;i<n;++i)
    {
        for(size_t j=0;j<m;++j)
            out<<T[i][j]<<' ';
        out<<'\n';
    }
    out<<'\n';
}

static void collectResults() __attribute__((deprecated));

static void collectResults()
{
    prepareR();
    printResults();
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
        Lsum=Rsum=0;
        for(size_t i=0;i<n;++i)
        {
            in>>L[i];
            Lsum+=L[i];
        }
        for(size_t i=0;i<m;++i)
        {
            in>>R[i];
            Rsum+=R[i];
        }
        if(Rsum!=Lsum)
        {
            out<<"NIE\n";
            continue;
        }
//         else if(Lsum==0)
//         {
//             for(size_t i=0;i<n;++i)
//             {
//                 for(size_t j=0;j<m;++j)
//                     out<<"0 ";
//                 out<<'\n';
//             }
//             out<<'\n';
//             continue;
//         }
//         for(size_t i=1;i<=1000000000;++i)
//         {
//             if(tryRTF(i))
//             {
//                 printResults();
//                 break;
//             }
//         }
        uint32_t L=1,R=std::numeric_limits< int32_t >::max()/2;
        while(L<R)
        {
            uint32_t S=(L+R)/2;
            if(tryRTF(S))
            {
                R=S;
            }
            else
            {
                L=S+1;
            }
        }
        bool o=tryRTF(L);
        printResults();
        check(o);
        check(!tryRTF(L-1));
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
