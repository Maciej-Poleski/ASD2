#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;


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

#include <random>
#include <cassert>

static bool isPrime(size_t number)
{
    static mt19937 engine(404);
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    else {
        uniform_int_distribution<size_t> dist(1,number-1);
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
    assert(false);
}

#include <tuple>
#include <vector>

int main(int argc,char**argv)
{
    vector<tuple<long,long,long,long>> output;
    for(long p=2;p<300;++p)
    {
        if(!isPrime(p))
            continue;
        for(long a=0;a<100;++a)
        {
            for(long b=0;b<100;++b)
            {
                for(long d=0;d<100;++d)
                {
                    output.push_back(make_tuple(p,a%p,b%p,d));
                }
            }
        }
    }
    cout<<output.size()<<'\n';
    for(const auto t : output)
    {
        cout<<get<0>(t)<<' '<<get<1>(t)<<' '<<get<2>(t)<<' '<<get<3>(t)<<'\n';
    }
    return 0;
}

