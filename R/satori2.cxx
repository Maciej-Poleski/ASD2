#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char**argv)
{
    long z;
    cin>>z;
    while(z--)
    {
        long p,a,b,d;
        cin>>p>>a>>b>>d;

        long x=0,y=1;

        bool found=false;
        for(long i=0;i<=d;++i)
        {
            if(x==a && y==b)
            {
                cout<<i<<'\n';
                found=true;
                break;
            }
            long x2=y;
            long y2=(x+y)%p;
            x=x2;
            y=y2;
        }
        if(!found)
        {
            cout<<"-\n";
        }
    }
    return 0;
}