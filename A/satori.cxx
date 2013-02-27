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

struct Node
{
    std::vector<uint32_t> edges;
    // edges[0]=parent (0 - at root)
    uint32_t subtreeSize;
    uint32_t pathId;
    uint32_t internalPathPointer;
    bool accessible; // only for debug

    Node() : accessible(true) {}
};

struct Path
{
    std::vector<uint32_t> nodes;
    std::set<uint32_t> lockedNodesPointers;
};

Node *G;

// because we don't have c++11 (lambda)
bool compareNode(const uint32_t lhs, const uint32_t rhs)
{
    return G[lhs].subtreeSize<G[rhs].subtreeSize;
}

uint32_t firstPass(const uint32_t v,const uint32_t p)
{
    G[v].subtreeSize=1;
    uint32_t parentPosition;
    for(std::vector<uint32_t>::iterator i=G[v].edges.begin(),e=G[v].edges.end(); i!=e; ++i)
    {
        if(*i==p)
        {
            parentPosition=i-G[v].edges.begin();
            check(G[v].edges[parentPosition]==p);
            continue;
        }
        G[v].subtreeSize+=firstPass(*i,v);
    }
    using std::swap;
    swap(G[v].edges[0],G[v].edges[parentPosition]);
    return G[v].subtreeSize;
}

// because we don't have c++11 (move semantics)
std::vector<Path*> paths;

/**
 * Umieść węzeł v w ścieżce i przyporządkuj dzieci v do odpowiedniej ścieżki
 */
void splitTreeIntoPaths(const uint32_t v, const uint32_t parentPathPointer)
{
    check(v!=0);
    paths[parentPathPointer]->nodes.push_back(v);
    G[v].pathId=parentPathPointer;
    G[v].internalPathPointer=paths[parentPathPointer]->nodes.size()-1;
    if(G[v].edges.size()==1)
        return;
    const uint32_t selectedNode=*std::max_element(G[v].edges.begin()+1,G[v].edges.end(),&compareNode);
    splitTreeIntoPaths(selectedNode,parentPathPointer);
    for(std::vector<uint32_t>::iterator i=G[v].edges.begin()+1,e=G[v].edges.end(); i!=e; ++i)
    {
        if(*i==selectedNode)
            continue;
        paths.push_back(new Path);
        splitTreeIntoPaths(*i,paths.size()-1);
    }
}

const uint32_t getLastAccessible(uint32_t v)
{
    if(v==0)
        return -1;
    const uint32_t pathPointer=G[v].pathId;
    const uint32_t internalPathPointer=G[v].internalPathPointer;
    if(paths[pathPointer]->lockedNodesPointers.find(internalPathPointer)!=
            paths[pathPointer]->lockedNodesPointers.end())
        return -1;
    if(paths[pathPointer]->lockedNodesPointers.empty())
    {
        uint32_t p=getLastAccessible(G[paths[pathPointer]->nodes[0]].edges[0]);
        if(p==-1)
            return paths[pathPointer]->nodes[0];
        else
            return p;
    }
    std::set<uint32_t>::iterator i=paths[pathPointer]->lockedNodesPointers.lower_bound(internalPathPointer);
    if(i==paths[pathPointer]->lockedNodesPointers.begin())
    {
        uint32_t p=getLastAccessible(G[paths[pathPointer]->nodes[0]].edges[0]);
        if(p==-1)
            return paths[pathPointer]->nodes[0];
        else
            return p;
    }
    if(i==paths[pathPointer]->lockedNodesPointers.end())
        return paths[pathPointer]->nodes[(*((paths[pathPointer]->lockedNodesPointers.rbegin())))+1];
    --i;
    return paths[pathPointer]->nodes[(*i)+1];
}

inline static void solution() __attribute__((optimize(3)));
inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    srand(time(0));
    while(z--)
    {
        check(paths.size()==0);
        uint_fast32_t n;
        in>>n;
        G=new Node[n+1];
        for(size_t i=1; i<n; ++i)
        {
            uint32_t a,b;
            in>>a>>b;
            G[a].edges.push_back(b);
            G[b].edges.push_back(a);
        }
        uint32_t selectedRoot=rand()%n+1;
        G[selectedRoot].edges.push_back(0);
        G[0].accessible=false; // for debug
        firstPass(selectedRoot,0);
        paths.push_back(new Path);
        splitTreeIntoPaths(selectedRoot,0);
        uint_fast32_t q;
        in>>q;
        while(q--)
        {
            std::string cmd;
            in>>cmd;
            if(cmd=="-")
            {
                uint32_t v;
                in>>v;
                paths[G[v].pathId]->lockedNodesPointers.insert(G[v].internalPathPointer);
                G[v].accessible=false;
            }
            else if(cmd=="+")
            {
                uint32_t v;
                in>>v;
                paths[G[v].pathId]->lockedNodesPointers.erase(G[v].internalPathPointer);
                G[v].accessible=true;
            }
            else
            {
                check(cmd=="?");
                uint32_t a,b;
                in>>a>>b;
                uint32_t A,B;
                if(n>50)
                {
                    A=getLastAccessible(a);
                    B=getLastAccessible(b);
                }
                else
                {
                    uint32_t la=a;
                    if(G[la].accessible==false)
                        la=-1;
                    else
                        while(G[G[la].edges[0]].accessible)
                            la=G[la].edges[0];
                    uint32_t lb=b;
                    if(G[lb].accessible==false)
                        lb=-1;
                    else
                        while(G[G[lb].edges[0]].accessible)
                            lb=G[lb].edges[0];
                    A=la;
                    B=lb;
                }
                check(A!=0);
                check(B!=0);
#ifdef DEBUG
                uint32_t la=a;
                if(G[la].accessible==false)
                    la=-1;
                else
                    while(G[G[la].edges[0]].accessible)
                        la=G[la].edges[0];
                uint32_t lb=b;
                if(G[lb].accessible==false)
                    lb=-1;
                else
                    while(G[G[lb].edges[0]].accessible)
                        lb=G[lb].edges[0];
                check(A==la);
                check(B==lb);
#endif
                out<<(((A==B) && (A!=-1) && (B!=-1))?"TAK":"NIE")<<'\n';
            }
        }
        for(std::vector<Path*>::iterator i=paths.begin(),e=paths.end(); i!=e; ++i)
        {
            delete *i;
        }
        paths.clear();
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
