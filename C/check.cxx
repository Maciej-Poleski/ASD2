#include <iostream>
#include <fstream>
#include <random>
#include <functional>

int main(int argc,char**argv)
{
    if(argc!=3)
    {
        std::cerr<<"[in] [tout]";
        return 1;
    }
    std::ifstream in(argv[1]);
    std::ifstream tout(argv[2]);
    int z;
    in>>z;
    bool ok=true;
    while(z--)
    {
        int n,m;
        in>>n>>m;
        int L[100],R[100];
        for(int i=0;i<n;++i)
            in>>L[i];
        for(int i=0;i<m;++i)
            in>>R[i];
        int T[100][100];
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                tout>>T[i][j];
        
        for(int i=0;i<n;++i)
        {
            int rSum=0;
            for(int j=0;j<m;++j)
            {
                rSum+=T[i][j];
            }
            if(rSum!=L[i])
            {
                std::cout<<"Zła suma w wierszu "<<i+1<<" oczekiwano "<<L[i]
                <<" a otrzymano "<<rSum<<'\n';
                ok=false;
            }
        }
        for(int i=0;i<m;++i)
        {
            int cSum=0;
            for(int j=0;j<n;++j)
            {
                cSum+=T[j][i];
            }
            if(cSum!=R[i])
            {
                std::cout<<"Zła suma w kolumnie "<<i+1<<" oczekiwano "<<R[i]
                <<" a otrzymano "<<cSum<<'\n';
                ok=false;
            }
        }
    }
    if(!ok)
        return 2;
    return 0;
}
