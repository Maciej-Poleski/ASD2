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
#include <tr1/memory>
#include <tr1/functional>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <complex>

namespace
{
using namespace Wrapper;

typedef std::complex<long double> complex;

static const long double pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989380952572010654858632788659361533818279682303019520353018529689957736225994138912497217752834791315155748572424541506959508295331168617278558890750983817546374649393192550604009277016711390098488240128583616035637076601047101819429555961989467678374494482553797747268471040475346462080466842590694912933136770289891521047521620569660240580381501935112533824300355876402474964732639141992726042699227967823547816360093417216412199245863150302861829745557067498385054945885869269956909272107975093029553211653449872027559602364806654991198818347977535663698074265425278625518184175746728909777727938000816470600161452491921732172147723501L;

static void fft(std::vector<complex> &A, complex w)
{
    if(A.size()==1)
    {
        return;
    }
    std::vector<complex> A0;
    for(size_t i=0; i<A.size(); i+=2)
    {
        A0.push_back(A[i]);
    }
    fft(A0,w*w);
    std::vector<complex> A1;
    for(size_t i=1; i<A.size(); i+=2)
    {
        A1.push_back(A[i]);
    }
    fft(A1,w*w);
    const size_t n=A.size();
    complex cw=1;
    for(size_t i=0; i<n/2; ++i)
    {
        A[i]=A0[i]+cw*A1[i];
        A[n/2+i]=A0[i]-cw*A1[i];
        cw*=w;
    }
    return;
}

static size_t nextpow2(size_t a)
{
    check(a>0);
    if(__builtin_popcount(a)==1)
        return a;
    size_t i=0;
    while(a!=0)
        a>>=1,++i;
    return 1LL<<i;
}

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while(z--)
    {
        std::string a,b;
        in>>a>>b;
        a="00000"+a;
        b="00000"+b;
        const std::complex< long double > zero(0.L,0.L);
        std::vector<complex> A;
        for(long i=a.length()-4; i>=0; i-=4)
        {
            long double o=atoi(a.substr(i,4).c_str());
            A.push_back(o);
        }
        while(A.back()==zero)
            A.pop_back();
        std::vector<complex> B;
        for(long i=b.length()-4; i>=0; i-=4)
        {
            long double o=atoi(b.substr(i,4).c_str());
            B.push_back(o);
        }
        while(B.back()==zero)
            B.pop_back();

        if(A.size()<B.size())
            A.insert(A.end(),B.size()-A.size(),zero);
        else if(B.size()<A.size())
            B.insert(B.end(),A.size()-B.size(),zero);

        const size_t more=nextpow2(A.size()*2)-A.size();
        A.insert(A.end(),more,zero);
        B.insert(B.end(),more,zero);
        check(__builtin_popcount(A.size()));
        check(__builtin_popcount(B.size()));
        check(A.size()==B.size());

        const size_t aSize=A.size();

        complex w=std::polar(1.L,pi/(aSize/2.0L));
        fft(A,w);
        fft(B,w);
        for(size_t i=0; i<aSize; ++i)
            A[i]*=B[i];
        fft(A,std::conj(w));
        std::vector<size_t> result;
        for(std::vector<complex>::const_reverse_iterator i=A.rbegin(),e=A.rend(); i!=e; ++i)
        {
            result.push_back(static_cast<size_t>(std::abs(*i)/(aSize)+0.5L));
        }
        for(std::vector<size_t>::reverse_iterator i=result.rbegin(),e=result.rend(); i!=e; ++i)
        {
            size_t r=*i%10000,d=*i/10000;
            *i=r;
            if(d)
                *(i+1)+=d;
        }
        out.fill('0');
        bool start=false;
        for(std::vector<size_t>::const_iterator i=result.begin(),e=result.end(); i!=e; ++i)
        {
            if(!start && *i==0)
                continue;
            else if(!start)
            {
                out<<*i;
                start=true;
            }
            else
                out<<std::setw(4)<<*i;
        }
        out<<'\n';
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

