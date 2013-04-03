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

typedef uint32_t FieldType;

std::vector<FieldType> array;

/**
 * @return true - słowa długości 2*k są parami różne
 */
static bool doKmrIteration(size_t length)
{
    std::vector<std::pair<FieldType,FieldType> > temp;
    for(std::vector<FieldType>::iterator i=array.begin(),e=array.end();i+length<e;++i)
    {
        temp.push_back(std::make_pair(*i,*(i+length)));
    }
    std::vector<std::pair<FieldType,FieldType> > sortedTemp=temp;
    std::sort(sortedTemp.begin(),sortedTemp.end());
    sortedTemp.erase(std::unique(sortedTemp.begin(),sortedTemp.end()),sortedTemp.end());

    if(sortedTemp.size()==temp.size())
        return true;

    std::map<std::pair<FieldType,FieldType>,FieldType> mapping;
    for(FieldType i=0;i<sortedTemp.size();++i)
    {
        mapping[sortedTemp[i]]=i;
    }
    std::vector<FieldType> newArray;
    for(std::vector<std::pair<FieldType,FieldType> >::iterator i=temp.begin(),e=temp.end();i!=e;++i)
    {
        newArray.push_back(mapping[*i]);
    }
    array=newArray;
    return false;
}

static size_t findK()
{
    for(size_t k=1;;k*=2)
    {
        if(doKmrIteration(k))
            return k;   // Nie ma powtórzeń
    }

}

static size_t n;
static size_t k;

static bool isPairwiseDifferent(size_t length)
{
    check(length>=k);
    check(length<=2*k);
    size_t shift=length-k;
    std::vector<std::pair<FieldType,FieldType> > temp;
    for(std::vector<FieldType>::iterator i=array.begin(),e=array.end();i+shift<e;++i)
    {
        temp.push_back(std::make_pair(*i,*(i+shift)));
    }
    std::vector<std::pair<FieldType,FieldType> > sortedTemp=temp;
    std::sort(sortedTemp.begin(),sortedTemp.end());
    sortedTemp.erase(std::unique(sortedTemp.begin(),sortedTemp.end()),sortedTemp.end());

    if(sortedTemp.size()==temp.size())
        return true;
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
        in>>n;
        array.resize(n);
        for(size_t i=0; i<n; ++i)
            in>>array[i];
        k=findK();

        size_t l=k,r=2*k;
        while(l<r)
        {
            size_t s=(l+r)/2;
            if(isPairwiseDifferent(s))
            {
                r=s;
            }
            else
            {
                l=s+1;
            }
        }
        out<<r<<'\n';
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
