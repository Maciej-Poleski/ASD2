//Maciej Poleski
#ifdef DEBUG
#define _GLIBCXX_CONCEPT_CHECKS
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
void init(int argc, char **argv)
{
    if (argc != 3) {
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
std::istream &in = std::cin;
std::ostream &out = std::cout;
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
#include <tr1/memory>
#include <tr1/functional>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <complex>
#include <tr1/random>

namespace
{
using namespace Wrapper;

static size_t fpow_impl(size_t base, size_t exponent, size_t mod)
{
    if (exponent == 0)
        return 1;
    else if (exponent % 2 == 1) {
        unsigned __int128 result = base;
        result *= fpow_impl(base, exponent - 1, mod);
        return result % mod;
    } else {
        unsigned __int128 result = fpow_impl(base, exponent / 2, mod);
        result *= result;
        return result % mod;
    }
}

static size_t fpow(size_t base, size_t exponent, size_t mod)
{
    return fpow_impl(base % mod, exponent, mod);
}

static bool isPrime(size_t number)
{
    static std::tr1::mt19937 engine(404);
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    else {
        std::tr1::uniform_int<size_t> dist(1,number-1);
        for (size_t i = 0; i < 40; ++i) {
            size_t a = dist(engine);
            size_t d = number - 1;
            size_t s = 0;
            while (d % 2 == 0) {
                ++s;
                d /= 2;
            }
            size_t x = fpow(a, d, number);

            if(x==1 || x==number-1)
                continue;
            for(size_t j=1;j<s && x!=number-1;++j)
            {
                unsigned __int128 t=x;
                t*=x;
                t%=number;
                x=t;
                if(x==1)
                    return false;
            }
            if(x!=number-1)
                return false;
            
//             bool oneIsRequired = false;
//             if(x==1)
//                 continue;
//             if(x==number-1)
//                 oneIsRequired=true;
//             for (size_t j = 0; j < s; ++j) {
//                 unsigned __int128 t = x;
//                 t *= x;
//                 t %= number;
//                 x = t;
//                 if (oneIsRequired)
//                     break;
//                 if(x==number-1)
//                     oneIsRequired=true;
//             }
//             if(x!=1)
//                 return false;
        }
        return true;
    }
    check(false);
}

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while (z--) {
        size_t n;
        in>>n;
        out<<(isPrime(n)?"TAK\n":"NIE\n");
    }
}

} // namespace

int main(int argc, char **argv)
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

