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

/**
 * Czarna skrzynka
 */
static void man(std::string const& T,int const N,int * const R)
{
    using namespace std;
    for(int j,k=0,i=0; k<=2*N; k+=j,i=max(i-j,k%2))
    {
        while((k-i)/2>0 && (k+i)/2<N && T[(k-i)/2-1]==T[(k+i)/2])
            i+=2;
        R[k]=i;
        for(j=1; j<i && j+R[k-j]<i; ++j)
            R[k+j]=R[k-j];
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
        std::string string;
        in>>string;
        size_t length=string.length()*2;
        int *R=new int[length+1];
        man(string,string.length(),R);
        
        size_t q;
        in>>q;
        while(q--)
        {
            size_t a,b;
            in>>a>>b;
            if(b==a)
            {
                out<<"TAK\n";
                continue;
            }
            if((b-a)%2)
            {
                // parzyste
                size_t s=(b+a)/2;
                if(R[2*s]>=(b-a+1))
                    out<<"TAK\n";
                else
                    out<<"NIE\n";
            }
            else
            {
                // nieparzyste
                size_t s=(b+a)/2;
                s-=1;
                if(R[s*2+1]>=(b-a+1))
                    out<<"TAK\n";
                else
                    out<<"NIE\n";
            }
        }
        delete [] R;
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
