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

static size_t fpow_impl(size_t base, size_t exponent, size_t mod) __attribute__((const));
static size_t fpow_impl(size_t base, size_t exponent, size_t mod)
{
    check(base != 0);
    if (exponent == 0)
        return 1;
    else if (exponent % 2 == 1) {
        uint64_t result = base;
        result *= fpow_impl(base, exponent - 1, mod);
        return result % mod;
    } else {
        uint64_t result = fpow_impl(base, exponent / 2, mod);
        result *= result;
        return result % mod;
    }
}

static size_t fpow(size_t base, size_t exponent, size_t mod) __attribute__((const));
static size_t fpow(size_t base, size_t exponent, size_t mod)
{
    return fpow_impl(base % mod, exponent, mod);
}

static uint64_t p;

class Matrix
{
public:
    Matrix(uint64_t data[2][2]) : data {{data[0][0], data[0][1]}, {data[1][0], data[1][1]}} {}
    Matrix() {}

    static Matrix makeFibonacci(uint64_t a, uint64_t b) __attribute__((pure));

    Matrix inverted() const __attribute__((pure));

public:
    uint64_t data[2][2];

};

static Matrix operator*(uint64_t s, const Matrix &m) __attribute__((pure));
static Matrix operator*(uint64_t s, const Matrix &m)
{
    Matrix result;
    result.data[0][0] = (m.data[0][0] * s) % p;
    result.data[0][1] = (m.data[0][1] * s) % p;
    result.data[1][0] = (m.data[1][0] * s) % p;
    result.data[1][1] = (m.data[1][1] * s) % p;
    return result;
}

static Matrix operator*(const Matrix &lhs, const Matrix &rhs) __attribute__((pure));
static Matrix operator*(const Matrix &lhs, const Matrix &rhs)
{
    Matrix result;
    result.data[0][0] = result.data[0][1] = result.data[1][0] = result.data[1][1] = 0;
    for (size_t i = 0; i < 2; ++i)
        for (size_t j = 0; j < 2; ++j)
            for (size_t k = 0; k < 2; ++k) {
                result.data[i][k] += (lhs.data[i][j] * rhs.data[j][k]);
                result.data[i][k] %= p;
            }
    return result;
}

Matrix Matrix::inverted() const
{
    uint64_t a = data[0][0];
    uint64_t b = data[0][1];
    uint64_t c = data[1][0];
    uint64_t d = data[1][1];

    uint64_t s = ((a * d) + (p - ((b * c) % p))) % p;
    s = fpow(s, p - 2, p);
    Matrix result;
    result.data[0][0] = d;
    result.data[0][1] = (b != 0 ? p - b : 0);
    result.data[1][0] = (c != 0 ? p - c : 0);
    result.data[1][1] = a;
    return s * result;
}

Matrix Matrix::makeFibonacci(uint64_t a, uint64_t b)
{
    // ... a b a+b
    Matrix result;
    result.data[0][0] = (a + b) % p;
    result.data[1][0] = result.data[0][1] = b;
    result.data[1][1] = a;
    return result;
}

static bool operator<(const Matrix &lhs, const Matrix &rhs) __attribute__((pure));
static bool operator<(const Matrix &lhs, const Matrix &rhs)
{
    for (size_t i = 0; i < 2; ++i)
        for (size_t j = 0; j < 2; ++j)
            if (lhs.data[i][j] != rhs.data[i][j])
                return lhs.data[i][j] < rhs.data[i][j];
    return false;
}

struct Pack {
    Matrix m;
    size_t id;
};

static bool operator<(const Pack &lhs, const Pack &rhs) __attribute__((pure));
static bool operator<(const Pack &lhs, const Pack &rhs)
{
    return lhs.m < rhs.m;
}

static std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
    return out << m.data[0][0] << ' ' << m.data[0][1] << ' ' << m.data[1][0] << ' ' << m.data[1][1];
}

inline static void solution()
{
    using std::swap;
    std::tr1::uint_fast32_t z;
    in >> z;
    //z=1;
    while (z--) {
        uint64_t a, b, d;
        in >> p >> a >> b >> d;
        if (d > 50) {
            const Matrix Z = Matrix::makeFibonacci((b - a + p) % p, a);
//         out<<"Z:  "<<Z<<'\n';
            uint64_t s = static_cast<uint64_t>(ceil(sqrt(d)) + .5);
            if (s == 0)
                s = 1;
            std::set<Pack> left;
            Matrix m;
            Matrix A = Matrix::makeFibonacci(0, 1);
            m.data[0][0] = m.data[1][1] = 1;
            m.data[0][1] = m.data[1][0] = 0;
            for (size_t i = 0; i < s; ++i) {
                left.insert(Pack {m, i});
//             out<<"m:  "<<m<<'\n';
                m = m * A;
            }
            Matrix mm;
            mm.data[0][0] = mm.data[1][1] = 1;
            mm.data[0][1] = mm.data[1][0] = 0;
            std::vector<Pack> right;
            for (size_t i = 0; i <= s; ++i) {
                right.push_back(Pack {mm, i *s});
//             out<<"mm: "<<mm<<'\n';
                mm = mm * m;
            }
            uint64_t best = std::numeric_limits< uint64_t >::max();
            for (std::vector<Pack>::const_iterator i = right.begin(), e = right.end(); i != e; ++i) {
                Matrix F = Z * (i->m.inverted());
                std::set<Pack>::iterator f = left.find(Pack {F, -1L});
                if (f != left.end()) {
//                 out<<"f:  "<<f->m<<'\n';
//                 out<<i->id<<' '<<f->id<<'\n';
                    best = std::min(best, i->id + f->id);
                    break;
                }
            }
            if (best <= d)
                out << best;
            else
                out << '-';
            out << '\n';
        } else {
            uint64_t x = 0, y = 1;

            bool found = false;
            for (size_t i = 0; i <= d; ++i) {
                if (x == a && y == b) {
                    out << i << '\n';
                    found = true;
                    break;
                }
                uint64_t x2 = y;
                uint64_t y2 = (x + y) % p;
                x = x2;
                y = y2;
            }
            if (!found) {
                out << "-\n";
            }
        }
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


