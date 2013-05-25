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

namespace
{
using namespace Wrapper;

static size_t *numberToColumnOrRow;     // numberToColumnOrRow[i] = jaka zmienna jest w kolumnie/wierszu i
static size_t n,m;

static double *optimize;
static double optimizeConstant;

struct Row
{
    double constant;
    double *numbers;
};

static Row *rows;

static const double epsi=0.0000001;

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while (z--) {
        in>>n>>m;
        numberToColumnOrRow=new size_t[n+m+1];
        for(size_t i=0; i<=n+m; ++i)
            numberToColumnOrRow[i]=i;
        optimize=new double[n+1];
        optimizeConstant=0;
        for(size_t i=1; i<=n; ++i)
            in>>optimize[i];
        rows=new Row[m];
        for(size_t i=0; i<m; ++i)
        {
            rows[i].numbers=new double[n+1];
            for(size_t j=1; j<=n; ++j)
            {
                double c;
                in>>c;
                rows[i].numbers[j]=-c;
            }
            in>>rows[i].constant;
        }
        out.precision(6);
        out.flags(out.fixed);
        for(;;)
        {
//             {
//                 // DEBUG
//                 out<<optimizeConstant;
//                 for(size_t i=1; i<=n; ++i)
//                     out<<' '<<optimize[i];
//                 out<<'\n';
//                 for(size_t i=0; i<m; ++i)
//                 {
//                     out<<rows[i].constant;
//                     for(size_t j=1; j<=n; ++j)
//                     {
//                         out<<' '<<rows[i].numbers[j];
//                     }
//                     out<<'\n';
//                 }
//             }
            size_t selectedColumn=0;
            for(size_t i=1; i<=n; ++i)
                if(optimize[i]>epsi)
                {
                    selectedColumn=i;
                    break;
                }
            if(selectedColumn==0)
            {
                out<<optimizeConstant<<'\n';
                // print result
                double *result=new double[n+1];
                for(size_t i=1;i<=n;++i)
                    result[i]=0;
                for(size_t i=n+1;i<=n+m;++i)
                {
                    if(numberToColumnOrRow[i]<=n)
                        result[numberToColumnOrRow[i]]=rows[i-n-1].constant;
                }
                for(size_t i=1;i<=n;++i)
                {
                    out<<"x_"<<i<<" = "<<result[i]<<'\n';
                }
                delete [] result;
                break;
            }
            double max=std::numeric_limits< double >::infinity();
            size_t selectedRow=0;
            for(size_t i=0; i<m; ++i)
            {
                if(rows[i].numbers[selectedColumn]<-epsi)
                {
                    if(max>rows[i].constant/(-rows[i].numbers[selectedColumn]))
                    {
                        max=rows[i].constant/(-rows[i].numbers[selectedColumn]);
                        selectedRow=i;
                    }
                }
            }
            if(max==std::numeric_limits< double >::infinity())
            {
                out<<"UNBOUNDED\n";
                break;
            }
            // pivot
//             out<<"ROW: "<<selectedRow<<" COLUMN: "<<selectedColumn<<'\n';
//             out<<"MAX: "<<max<<'\n';
            double newConstant=rows[selectedRow].constant/(-rows[selectedRow].numbers[selectedColumn]);
            double *newNumbers=new double[n+1];
            for(size_t i=1; i<=n; ++i)
            {
                newNumbers[i]=rows[selectedRow].numbers[i]/(-rows[selectedRow].numbers[selectedColumn]);
            }
            newNumbers[selectedColumn]=1/rows[selectedRow].numbers[selectedColumn];
//             out<<newConstant;
//             for(size_t i=1; i<=n; ++i)
//                 out<<' '<<newNumbers[i];
//             out<<'\n';
            swap(numberToColumnOrRow[selectedColumn],numberToColumnOrRow[n+selectedRow+1]);
            for(size_t i=0; i<m; ++i)
            {
                double multiplyBy=rows[i].numbers[selectedColumn];
                rows[i].numbers[selectedColumn]=0;      // place for new variable
                rows[i].constant+=multiplyBy*newConstant;
                for(size_t j=1; j<=n; ++j)
                {
                    rows[i].numbers[j]+=multiplyBy*newNumbers[j];
                }
            }
            {
                double multiplyBy=optimize[selectedColumn];
                optimize[selectedColumn]=0;      // place for new variable
                optimizeConstant+=multiplyBy*newConstant;
                for(size_t j=1; j<=n; ++j)
                {
                    optimize[j]+=multiplyBy*newNumbers[j];
                }
            }
            delete [] rows[selectedRow].numbers;
            rows[selectedRow].numbers=newNumbers;
            rows[selectedRow].constant=newConstant;
//             out<<"Constant: "<<optimizeConstant<<'\n';
        }


        for(size_t i=0; i<m; ++i)
            delete [] rows[i].numbers;
        delete [] rows;
        delete [] optimize;
        delete [] numberToColumnOrRow;
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





