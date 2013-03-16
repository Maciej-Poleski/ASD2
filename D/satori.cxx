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

// Struktura w wersji siłowej

struct Edge
{
    int32_t c,f; // sieć rezydualna
    uint32_t d; // wierzchołek docelowy
    int32_t w; // koszt
    std::list<Edge>::iterator i; // krawędź odwrotna

    const int32_t cf() const
    {
        return c-f;
    }

    const uint32_t from() const
    {
        return i->d;
    }

    const uint32_t to() const
    {
        return d;
    }
};

struct Vertex
{
    std::list<Edge> edges;
};

static size_t effectiveN;
static Vertex *G;
static int32_t *D;      // tymczasowa tablica odległości od źródła
static int32_t *Pi;     // Johnson
static std::list<Edge>::iterator *P; // P[i] = krawędź wchodząca do i na ścieżce rezydualnej
static bool *V;         // V[i]=true <-> i został odwiedzony
static uint32_t n,m;
static uint32_t u,v;
static const uint32_t source=0,target=1;
static const uint32_t magicCapacity=600;

static void makeDirected(uint32_t from,uint32_t to, int32_t c, int32_t w)
{
    check(from!=to);
    Edge e1,e2;
    e1.d=to;
    e2.d=from;
    e1.c=c;
    e1.w=w;
    e2.c=0;
    e2.w=-w;
    e1.f=0;
    e2.f=0;
    G[from].edges.push_front(e1);
    G[to].edges.push_front(e2);
    G[from].edges.front().i=G[to].edges.begin();
    G[to].edges.front().i=G[from].edges.begin();
}

static void BF()
{
    for(size_t i=0; i<effectiveN; ++i)
    {
        D[i]=std::numeric_limits<int32_t>::max();
    }
    D[source]=0;
    for(size_t i=0; i<effectiveN; ++i)
    {
        bool stop=true;
        for(size_t i=0; i<effectiveN; ++i)
            for(std::list<Edge>::iterator ii=G[i].edges.begin(),e=G[i].edges.end(); ii!=e; ++ii)
                if(D[ii->to()]>D[ii->from()]+ii->w)
                {
                    stop=false;
                    D[ii->to()]=D[ii->from()]+ii->w;
                }
        if(stop)
            break;
    }
}

static void insertDIntoPi()
{
    for(size_t i=0; i<effectiveN; ++i)
        Pi[i]+=D[i];
}

struct DijkstraPack
{
    uint32_t d; // wierzchołek
    int32_t w; // koszt
    
    bool operator<(const DijkstraPack &o) const
    {
        return w>o.w;
    }
};

static int32_t virtualDistance(const Edge &edge)
{
    return edge.w+Pi[edge.from()]-Pi[edge.to()];
}

/**
 * Może powiększyć tylko o 1 (słownie: jeden)
 */
static bool findSomePath()
{
    V=new bool[effectiveN];
    for(size_t i=0;i<effectiveN;++i)
        V[i]=false,D[i]=std::numeric_limits<int32_t>::max();
    std::priority_queue<DijkstraPack> queue;
    queue.push({source,0});
    D[source]=0;
    bool result=false;
    while(!queue.empty())
    {
        const DijkstraPack pack=queue.top();
        queue.pop();
        if(D[pack.d]<pack.w)
            continue;
        V[pack.d]=true;
        if(pack.d==target)
            result=true;
        for(std::list<Edge>::iterator i=G[pack.d].edges.begin(),e=G[pack.d].edges.end();i!=e;++i)
        {
            if(!V[i->to()] && i->cf()>0)
            {
                if(D[i->to()]>D[i->from()]+virtualDistance(*i))
                {
                    D[i->to()]=D[i->from()]+virtualDistance(*i);
                    P[i->to()]=i;
                    queue.push({i->to(),D[i->to()]});
                }
            }
        }
    }
    delete [] V;
    return result;
}

static int32_t resolve()
{
    BF();
    int32_t result=0;
    uint32_t flow=0;
    for(size_t i=0; i<effectiveN; ++i)
        Pi[i]=0;
    for(;;)
    {
        insertDIntoPi();
        bool localWeight=findSomePath();
        if(localWeight==false)
        {
            break;
        }
        for(size_t i=target;i!=source;i=P[i]->from())
        {
            ++(P[i]->f);
            --(P[i]->i->f);
            result+=P[i]->w;
        }
        ++flow;
    }
    if(flow==600+n)
        return result;
    else
        return -1;
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
        in>>n>>m;
        effectiveN=2*n+4;
        G=new Vertex[effectiveN];
        D=new int32_t[effectiveN];
        Pi=new int32_t[effectiveN];
        P=new std::list<Edge>::iterator[effectiveN];
        // left = 2*i, right= 2*i+1
        u=2*(n+1);
        v=2*(n+1)+1;
        for(size_t i=0; i<m; ++i)
        {
            uint32_t x,y;
            int32_t k;
            in>>x>>y>>k;
            makeDirected(2*x,2*y+1,1,k);
        }
        for(size_t i=1; i<=n; ++i)
        {
            makeDirected(source,2*i,1,0);  // from source
            makeDirected(2*i+1,target,1,0);// to target
            makeDirected(u,2*i,magicCapacity,0); // from auxiliary
            makeDirected(2*i+1,v,magicCapacity,0);// to auxiliary
        }
        makeDirected(u,v,magicCapacity,0); // connaction af auxiliaries
        makeDirected(source,u,magicCapacity,0); // connect source to aux
        makeDirected(v,target,magicCapacity,0); // connect aux to target

        int32_t result=resolve();
        if(result>0)
            out<<result<<'\n';
        else
            out<<"NIE\n";
        delete [] P;
        delete [] Pi;
        delete [] D;
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
