#include <iostream>
#include <fstream>
#include <random>
#include <functional>
#include <ctime>

int main(int argc,char**argv)
{
    if(argc!=2)
    {
        std::cerr<<"Podaj nazwe pliku wyjściowego\n";
        return 1;
    }
    std::ofstream out(argv[1]);
    int z=1;
    out<<z<<'\n';
    int n,m;
    n=m=50;
    out<<n<<' '<<m<<'\n';
    std::mt19937 engine(time(0));
    std::uniform_int_distribution<int> dist(0,100000);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        auto c=dist(engine);
        sum+=c;
        out<<c<<' ';
    }
    out<<'\n';
    for(int i=1;i<m;++i)
    {
        auto c=dist(engine);
        sum-=c;
        out<<c<<' ';
    }
    if(std::abs(sum)>1000000)
        std::cerr<<"Ten test jest niepoprawny\n";
    out<<sum<<'\n';
    return 0;
}