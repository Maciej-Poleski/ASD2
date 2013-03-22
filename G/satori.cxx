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

static void kmp(int32_t *KMP,const std::string &string)
{
    int32_t j,length=string.length();
    KMP[0] = j = -1;
    for(size_t i = 1; i <= length; ++i)
    {
        while((j > -1) && (string[j] != string[i - 1]))
            j = KMP[j];
        ++j;
        if((i == length) || (string[i] != string[j]))
            KMP[i] = j;
        else
            KMP[i] = KMP[j];
    }
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
        std::string a,b;
        in>>n>>a>>b;
        std::string text=a+"#"+b+b;
        int32_t *KMP=new int32_t[text.length()+1];
        kmp(KMP,text);
        if(*std::max_element(KMP,KMP+text.length()+1)==a.length())
        {
            out<<"IDENTYCZNE\n";
        }
        else
        {
            text=std::string(a.rbegin(),a.rend())+"#"+b+b;
            kmp(KMP,text);
            if(*std::max_element(KMP,KMP+text.length()+1)==a.length())
            {
                out<<"IDENTYCZNE\n";
            }
            else
            {
                out<<"ROZNE\n";
            }
        }
        delete [] KMP;
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
