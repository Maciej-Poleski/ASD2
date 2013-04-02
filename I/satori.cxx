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

template<typename String>
std::vector<uint32_t> PREF(const String & string)
{
    size_t s = 0;
    size_t length=string.length();
    std::vector<uint32_t> pref(length);
    pref[0] = 0;
    for(size_t i=1; i<length; ++i)
    {
        if(s + pref[s] > i)
            pref[i] = std::min<uint32_t>(pref[i-s], pref[s] - i + s);
        else
            pref[i] = 0;

        while((pref[i] + i<length) && (string[pref[i]] == string[pref[i] + i]))
            ++pref[i];

        if(i + pref[i] > s + pref[s])
            s = i;
    }
    return pref;
}

template<typename String>
static bool test(const String & string, const size_t left, const size_t right)
{
    const size_t length=right-left;
    const size_t s=(right+left)/2;
    if(length<2)
        return false;
    if(length==2)
        return string[left]==string[left+1];
    if(test(string,left,s) || test(string,s,right))
        return true;
    const String partLeft=string.substr(left,s-left),partRight=string.substr(s,right-s);
    const String reverseLeft(partLeft.rbegin(),partLeft.rend()),
          reverseRight(partRight.rbegin(),partRight.rend());
    std::vector<uint32_t> prefSide=PREF(partRight);
    String temp=reverseLeft+reverseRight;
    std::vector<uint32_t> prefTotal=PREF(temp);
    for(size_t k=1; k<partRight.size(); ++k)
        if(prefSide[k]+prefTotal[reverseLeft.size()+reverseRight.size()-k]>=k)
            return true;
    if(prefTotal[partLeft.size()]>=partRight.size())
        return true;
    prefSide=PREF(reverseLeft);
    temp=partRight+partLeft;
    prefTotal=PREF(temp);
    for(size_t k=1; k<reverseLeft.size(); ++k)
        if(prefSide[k]+prefTotal[partRight.size()+partLeft.size()-k]>=k)
            return true;
    if(prefTotal[partRight.size()]>=partLeft.size())
        return true;
    return false;
}

template<typename String>
static bool testStart(const String & string,const size_t length)
{
//     if(length<2)
//         return false;
//     for(std::size_t i=0; i+1<length; ++i)
//     {
//         if(string[i]==string[i+1])
//             return true;
//     }
//     for(std::size_t i=0; i+3<length; ++i)
//     {
//         if((string[i]==string[i+2]) && (string[i+1]==string[i+3]))
//             return true;
//     }
    return test(string,0,length);
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
        std::basic_string<int> string;
        size_t n;
        in>>n;
        string.resize(n);
        for(size_t i=0; i<n; ++i)
        {
            in>>string[i];
        }
        out<<((testStart(string,n))?"TAK":"NIE")<<'\n';
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
