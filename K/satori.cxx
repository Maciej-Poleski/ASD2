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

namespace
{
using namespace Wrapper;

static char pattern[3000][3000];
static std::size_t a,b;

struct Node
{
    Node *next[2];
    Node *MSM;
    bool terminal;

    Node() : next({0,0}),MSM(0),terminal(false) {}

    ~Node()
    {
        delete next[0];
        delete next[1];
    }
};

static Node *root=NULL;

static std::size_t translateChar(const char c) __attribute__((const));
static std::size_t translateChar(const char c)
{
    return c=='x';
}

struct Pack
{
    Node *parent;
    char c;

    Node * getNode() const
    {
        return parent->next[c];
    }
};

Node * Pack::getNode() const __attribute__((pure));

static void doAC()
{
    root->MSM=NULL;
    std::queue<Pack> queue;
    if(root->next[0])
        queue.push({root,0});
    if(root->next[1])
        queue.push({root,1});
    while(!queue.empty())
    {
        Pack p=queue.front();
        queue.pop();
        if(p.getNode()->next[0])
            queue.push({p.getNode(),0});
        if(p.getNode()->next[1])
            queue.push({p.getNode(),1});
        if(p.parent==root)
        {
            p.getNode()->MSM=root;
        }
        else
        {
            Node *z=p.parent->MSM;
            while(z && z->next[p.c]==NULL)
                z=z->MSM;

            if(z && z->next[p.c])
                p.getNode()->MSM=z->next[p.c];
            else
                p.getNode()->MSM=root;

            if(p.getNode()->MSM->terminal)
                p.getNode()->terminal=true;
        }
    }
}

static void compilePatterns()
{
    delete root;
    root=new Node;
    for(size_t i=0;i<a;++i)
    {
        Node *it=root;
        for(size_t j=0;j<b;++j)
        {
            if(it->next[translateChar(pattern[i][j])]==NULL)
                it->next[translateChar(pattern[i][j])]=new Node;
            it=it->next[translateChar(pattern[i][j])];
        }
        it->terminal=true;
    }
    doAC();
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
        in>>a>>b;
        for(std::size_t i=0;i<a;++i)
        {
            in.ignore();
            for(std::size_t j=0;j<b;++j)
                in>>pattern[i][j];
        }
        compilePatterns();
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
