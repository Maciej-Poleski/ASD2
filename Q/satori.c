#include <stdio.h>

unsigned int k,m;

typedef struct
{
    unsigned int width,height;
    unsigned int tab[80][80];
} matrix;

matrix base_matrix,ext;
//     void clear(matrix *o)
//     {
//         unsigned int i,j;
//         for(i=0;i<80;++i)
//             for(j=0;j<80;++j)
//                 o->tab[i][j]=0;
//     }

void assign(matrix * l,const matrix * const co)
{
    l->width=co->width;
    l->height=co->height;
    unsigned int i,j;
    for(i=0;i<co->height;++i)
        for(j=0;j<co->width;++j)
            l->tab[i][j]=co->tab[i][j];

}

void set(matrix *l)
{
    unsigned int i,j;
    for(i=0;i<80;++i)
        for(j=0;j<80;++j)
            l->tab[i][j]=(i==j?1:0);
}


matrix* iloczyn(matrix *l,matrix *p)
{
    static matrix wynik;
    wynik.width=p->width;
    wynik.height=l->height;

    unsigned int i,j,q;
    for(i=0;i<l->height;++i)
    {
        for(j=0;j<p->width;++j)
        {
            wynik.tab[i][j]=0;
            for(q=0;q<l->width;++q)
            {
                wynik.tab[i][j]+=(l->tab[i][q])*(p->tab[q][j]);
            }
            wynik.tab[i][j]%=1000;
        }
    }

    return &wynik;
}

matrix* powM(matrix *l,unsigned int p)
{
    static matrix wynik;
    set(&wynik);
    wynik.width=l->width;
    wynik.height=l->height;
    matrix tmp;
    assign(&tmp,l);
    while(p)
    {
        if(p&1)
        {
            assign(&wynik,iloczyn(&wynik,&tmp));
        }
        p>>=1;

        assign(&tmp,iloczyn(&tmp,&tmp));
    }
    return &wynik;
}

void print(unsigned int l)
{
    printf("%u%u%u\n",l/100,(l%100)/10,l%10);
}

int main()
{
    unsigned int z,ttt;
    scanf("%u",&z);
    while(z--)
    {
        matrix wsk,wynik;
        scanf("%u%u",&k,&m);;

        unsigned int i;
        for(i=0;i<k;++i)
        {
            scanf("%u",&ttt);
            base_matrix.tab[0][i]=ttt%1000;
        }

        base_matrix.width=base_matrix.height=k;

        for(i=1;i<k;++i)
        {
            unsigned int j;
            for(j=0;j<k;++j)
            {
                base_matrix.tab[i][j]=(i-1==j?1:0);
            }
        }

        for(i=0;i<k;++i)
        {
            scanf("%u",&ttt);
            ext.tab[i][0]=ttt%1000;
        }

        if(m<=k)
        {
            print(ext.tab[k-m][0]);
            continue;
        }

        ext.width=1;
        ext.height=k;

        assign(&wsk,powM(&base_matrix,m-k));
        assign(&wynik,iloczyn(&wsk,&ext));

        print(wynik.tab[0][0]);
    }
    return 0;
}