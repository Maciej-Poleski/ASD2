#include "header.h"


// GEOMETRIA - podstawowe struktury i operatory

// Bartosz Walczak

typedef double double_t;
const double_t EPS = 1e-9;

struct xy { // punkt w 2D
    double_t x, y;
    xy(double_t xi, double_t yi):x(xi), y(yi) {}
    xy() {}
    double_t norm() const {
        return x*x+y*y;    // kwadrat(!) normy euklidesowej
    }
};

inline xy operator+(const xy&a, const xy&b) {
    return xy(a.x+b.x, a.y+b.y);
}
inline xy operator-(const xy&a, const xy&b) {
    return xy(a.x-b.x, a.y-b.y);
}
inline xy operator*(const xy&a, double_t f) {
    return xy(a.x*f, a.y*f);
}
inline xy operator/(const xy&a, double_t f) {
    return xy(a.x/f, a.y/f);
}
inline xy cross(const xy&a) {
    return xy(-a.y, a.x);    // obrot o 90 stopni
}
inline double_t operator*(const xy&a, const xy&b) {
    return a.x*b.x+a.y*b.y;
}
inline double_t det(const xy&a, const xy&b) {
    return a.x*b.y-b.x*a.y;
}

struct xyz { // punkt w 3D
    double_t x, y, z;
    xyz(double_t xi, double_t yi, double_t zi):x(xi), y(yi), z(zi) {}
    xyz() {}
    double_t norm() const {
        return x*x+y*y+z*z;    // kwadrat(!) normy euklidesowej
    }
};

xyz normal;

inline xyz operator+(const xyz&a, const xyz&b)
{
    return xyz(a.x+b.x, a.y+b.y, a.z+b.z);
}
inline xyz operator-(const xyz&a, const xyz&b)
{
    return xyz(a.x-b.x, a.y-b.y, a.z-b.z);
}
inline xyz operator*(const xyz&a, double_t f) {
    return xyz(a.x*f, a.y*f, a.z*f);
}
inline xyz operator/(const xyz&a, double_t f) {
    return xyz(a.x/f, a.y/f, a.z/f);
}
// Iloczyn wektorowy. Uwaga: odwrotnie argumenty: cross(a,b)=bxa
inline xyz cross(const xyz&a, const xyz&b=normal)
{
    return xyz(b.y*a.z-a.y*b.z, b.z*a.x-a.z*b.x, b.x*a.y-a.x*b.y);
}
inline double_t operator*(const xyz&a, const xyz&b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
inline double_t det(const xyz&a, const xyz&b, const xyz&c=normal)
{
    return cross(a,b)*c;
}

/* GEOMETRIA 2D. Dziala rowniez na dowolnej plaszczyznie w 3D. Wtedy normal
   jest unormowanym (tzn. |normal|=1) wektorem normalnym do plaszczyzny.
   Funkcje oznaczone (*) wymagaja przystosowania do 3D.                       */

// Bartosz Walczak

typedef xy Point; // w wersji na plaszczyznie w 3D zmienic na:  typedef xyz P;

// Kat skierowany pomiedzy dwoma wektorami. Zalozenie: a,b!=0
double_t angle(const Point&a, const Point&b) {
    return atan2(det(a,b), a*b);
}
// Obrot wektora o kat skierowany
Point rot(const Point&a, double_t phi) {
    return a*cos(phi)+cross(a)*sin(phi);
}

/* Wzajemna orientacja 3 wektorow
   >0 - counterclockwise, <0 - clockwise, ==0 - 2 wektory sie pokrywaja       */
int orient(const Point&a, const Point&b, const Point&c) {
    double_t d1=det(a,b), d2=det(b,c), d3=det(c,a);
    return (d1>=EPS)-(d1<=-EPS)+(d2>=EPS)-(d2<=-EPS)+(d3>=EPS)-(d3<=-EPS);
}



struct line { // prosta {v: n*v=c} (n - wektor normalny)
    Point n;
    double_t c;
    line(const Point&ni, double_t ci):n(ni), c(ci) {}
    line() {}
};

// Czy punkt lezy na prostej?
bool on_line(const Point&a, const line &p) {
    return fabs(p.n*a-p.c)<EPS;
}
// Prosta przechodzaca przez 2 punkty ccw. Zalozenie: a!=b
line span(const Point&a, const Point&b) {
    return line(cross(b-a), det(b,a));
}
// Symetralna odcinka. Zalozenie: a!=b
line median(const Point&a, const Point&b) {
    return line(b-a, (b-a)*(b+a)*0.5);
}
// Przeciecie 2 prostych
Point intersection(const line &p, const line &q) {
    double_t d=det(p.n,q.n);
    if (fabs(d)<EPS) throw "rownolegle";
    return cross(p.n*q.c-q.n*p.c)/d;
}
// Prosta rownolegla przechodzaca przez punkt
line parallel(const Point&a, const line &p) {
    return line(p.n, p.n*a);
}
// Prosta prostopadla przechodzaca przez punkt
line perp(const Point&a, const line &p) {
    return line(cross(p.n), det(p.n,a));
}
// Odleglosc punktu od prostej
double_t dist(const Point&a, const line &p) {
    return fabs(p.n*a-p.c)/sqrt(p.n.norm());
}

// PRZECINANIE ODCINKOW

// Bartosz Walczak

struct segment {
    Point a, b;
}; // odcinek domkniety

// Punkt p lezy na prostej zawierajacej s. Czy lezy na odcinku s?
bool on_segment(const Point&p, const segment &s) // (*)
{   return min(s.a.x, s.b.x)<p.x+EPS && p.x<max(s.a.x, s.b.x)+EPS &&
           min(s.a.y, s.b.y)<p.y+EPS && p.y<max(s.a.y, s.b.y)+EPS;
}
// Czy dwa odcinki maja wspolny punkt?
bool intersect(const segment &s1, const segment &s2) {
    double_t d1 = det(s2.b-s2.a, s1.a-s2.a), d2 = det(s2.b-s2.a, s1.b-s2.a),
             d3 = det(s1.b-s1.a, s2.a-s1.a), d4 = det(s1.b-s1.a, s2.b-s1.a);
    return (d1>=EPS && d2<=-EPS || d1<=-EPS && d2>=EPS) &&
           (d3>=EPS && d4<=-EPS || d3<=-EPS && d4>=EPS) ||
           fabs(d1)<EPS && on_segment(s1.a, s2) ||
           fabs(d2)<EPS && on_segment(s1.b, s2) ||
           fabs(d3)<EPS && on_segment(s2.a, s1) ||
           fabs(d4)<EPS && on_segment(s2.b, s1);
}

/* PRECYZYJNY PORZADEK KATOWY
      IN: e - wektor rozdzielajacy (wlacznie ccw), a,b - wektory
      OUT: <0 jesli a<b; >0 jesli a>b; 0 jesli a==b
   Uwaga: Dostosowany do obliczen na typach calkowitoliczbowych.
          Przy typach zmiennopozycyjnych lepiej wyliczyc katy explicite       */

// Arkadiusz Pawlik

int anglecmp(const Point&e, const Point&a, const Point&b) {
    int ret=0;
    double_t v1 = e.x*a.y-e.y*a.x;
    if (v1<0) ret=1;
    else if (v1>0 || e.x*a.x+e.y*a.y>0) ret=-1;
    double_t v2 = b.x*e.y-b.y*e.x;
    if (v2>0) --ret;
    else if (v2<0 || b.x*e.x+b.y*e.y>0) ++ret;
    return ret + (a.x*b.y-a.y*b.x<0) - (a.x*b.y-a.y*b.x>0);
}


// WYPUKLA OTOCZKA 2D O(n log(n))

// Bartosz Walczak

const int MAXN = 100; // maksymalna liczba punktow

int n;         // IN: liczba punktow (zmienia sie przy wywolaniu remove)
Point pts[MAXN];   // IN: tablica punktow (zmienia sie!)
int hc;        // OUT: liczba punktow na wypuklej otoczce
Point *hull[MAXN]; // OUT: wskazniki na kolejne punkty na wypuklej otoczce

inline bool operator==(const xy&a, const xy&b) // (*) potrzebne do remove
{
    return a.x==b.x && a.y==b.y;
}
inline bool operator<(const xy&a, const xy&b) // (*)
{
    return a.y<b.y || a.y==b.y && a.x<b.x;
}

inline bool compare(const Point&a, const Point&b) {
    double_t d=det(a-*pts, b-a);
    return d>=EPS || fabs(d)<EPS && (a-*pts)*(b-a)>=EPS;
}

void compute_hull() {
    if (!n) {
        hc=0;    // pominac, jesli n>0
        return;
    }
    swap(*min_element(pts, pts+n), *pts);
    n = remove(pts+1, pts+n, *pts)-pts; // pominac, jesli punkty sa rozne
    sort(pts+1, pts+n, compare);
    hull[0]=pts;
    hc=1;
    FOR(i,1,n) {
        while (hc>=2 && det(*hull[hc-1]-*hull[hc-2], pts[i]-*hull[hc-1])<EPS)
            --hc;
        hull[hc++]=pts+i;
    }
}

/* NAJMNIEJSZE KOLO zawierajace wszystkie punkty O(n)
   OUT: C - srodek kola, R - kwadrat(!) promienia
   Uwaga! Przed wywolaniem warto zrobic random_shuffle                        */

// Arkadiusz Pawlik

void minidisc2(const Point *begin, const Point *end, Point &C,
               double_t &R, const Point &p1, const Point &p2) {
    R = (p1-p2).norm()*0.25;
    C = (p1+p2)*0.5;
    FOR(i,0,end-begin) if ((C-begin[i]).norm() > R) {
        line U = median(p2, begin[i]);
        line V = median(p1, begin[i]);
        C = intersection(U, V); // Uwaga na wyjatki!
        R = max((C-p1).norm(), max((C-p2).norm(), (C-begin[i]).norm()));
    }
}
void minidisc1(const Point *begin, const Point *end, Point &C, double_t &R, const Point &p1) {
    R = (p1-begin[0]).norm()*0.25;
    C = (p1+begin[0])*0.5;
    FOR(i,1,end-begin) if ((C-begin[i]).norm() > R)
        minidisc2(begin, begin+i, C, R, p1, begin[i]);
}
void minidisc(const Point *begin, const Point *end, Point &C, double_t &R) {
    if (end-begin==0) {
        C=xy(0,0);
        R=0;
    }
    else if (end-begin==1) {
        C=*begin, R=0;
    }
    else {
        R = (begin[0]-begin[1]).norm()*0.25;
        C = (begin[0]+begin[1])*0.5;
        FOR(i,2,end-begin) if ((C-begin[i]).norm() > R)
            minidisc1(begin, begin+i, C, R, begin[i]);
    }
}


// GEOMETRIA OKREGOW W 2D

// Bartosz Walczak

struct circle { // okrag w 2D
    Point c;
    double_t r; // srodek, promien
    circle(const Point&ci, double_t ri=0):c(ci), r(ri) {}
    circle() {}
    double_t length() const {
        return 2*M_PI*r;    // dlugosc
    }
    double_t area() const {
        return M_PI*r*r;    // pole kola
    }
};

// Czy punkt lezy na okregu?
bool on_circle(const Point&a, const circle &c)
{
    return fabs((a-c.c).norm()-c.r*c.r)<EPS;
}
// Czy kolo/punkt lezy wewnatrz lub na brzegu kola?
bool operator<(const circle&a, const circle&b)
{
    return b.r+EPS>a.r && (a.c-b.c).norm()<(b.r-a.r)*(b.r-a.r)+EPS;
}
// Srodek okragu opisanego na trojkacie
circle circumcircle(Point a, Point b, Point c) {
    if ((a-b).norm() > (c-b).norm()) swap(a, c);
    if ((b-c).norm() > (a-c).norm()) swap(a, b);
    if (fabs(det(b-a, c-b))<EPS) throw "zdegenerowany";
    Point v=intersection(median(a, b), median(b, c));
    return circle(v, sqrt((a-v).norm()));
}
// Przeciecie okregu i prostej. Zwraca liczbe punktow
int intersection(const circle &c, const line &p, Point I[]/*OUT*/) {
    double_t d=p.n.norm(), a=(p.n*c.c-p.c)/d;
    Point u=c.c-p.n*a;
    a*=a;
    double_t r=c.r*c.r/d;
    if (a>=r+EPS) return 0;
    if (a>r-EPS) {
        I[0]=u;
        return 1;
    }
    double_t h=sqrt(r-a);
    I[0]=u+cross(p.n)*h;
    I[1]=u-cross(p.n)*h;
    return 2;
}


// GEOMETRIA 3D

// Bartosz Walczak

// Kat pomiedzy dwoma wektorami. Zawsze >=0. Zalozenie: a,b!=0
double_t angle3(const xyz &a, const xyz &b)
{
    return atan2(sqrt(cross(b,a).norm()), a*b);
}

struct plane { // plaszczyzna {v: n*v=c} (n - wektor normalny)
    xyz n;
    double_t c;
    plane(const xyz &ni, double_t ci):n(ni), c(ci) {}
    plane() {}
};


// Czy punkt lezy na plaszczyznie?
bool on_plane(const xyz &a, const plane &p) {
    return fabs(p.n*a-p.c)<EPS;
}
// Plaszczyzna rozpieta przez 3 punkty ccw. Zalozenie: a,b,c niezalezne
plane span3(const xyz &a, const xyz &b, const xyz &c)
{
    xyz n=cross(c-a,b-a);
    return plane(n, n*a);
}
// Plaszczyzna symetralna odcinka. Zalozenie: a!=b
plane median3(const xyz &a, const xyz &b)
{
    return plane(b-a, (b-a)*(b+a)*0.5);
}
// Plaszczyzna rownolegla przechodzaca przez punkt
plane parallel3(const xyz &a, const plane &p) {
    return plane(p.n, p.n*a);
}
// Odleglosc punktu od plaszczyzny
double_t dist3(const xyz &a, const plane &p)
{
    return fabs(p.n*a-p.c)/sqrt(p.n.norm());
}

struct line3 { // prosta {v: cross(v,u)=w} (u - wektor kierunku)
    xyz u, w;
    line3(const xyz &ui, const xyz &wi):u(ui), w(wi) {}
    line3() {}
};

// Czy punkt lezy na prostej?
bool on_line3(const xyz &a, const line3 &p)
{
    return (cross(a,p.u)-p.w).norm()<EPS;
}
// Prosta rozpieta przez 2 punkty. Zalozenie: a!=b
line3 span3(const xyz &a, const xyz &b)
{
    return line3(b-a, cross(a,b-a));
}
// Plaszczyzna rozpieta przez prosta i punkt ccw. Zalozenie: cross(a,p.u)!=p.w
plane span3(const line3 &p, const xyz &a)
{
    return plane(cross(a,p.u)-p.w, p.w*a);
}
// Prosta przeciecia dwoch plaszczyzn
line3 intersection3(const plane &p, const plane &q) {
    xyz u=cross(q.n,p.n);
    if (u.norm()<EPS) throw "rownolegle";
    return line3(u, q.n*p.c-p.n*q.c);
}
// Punkt przeciecia plaszczyzny i prostej
xyz intersection3(const plane &p, const line3 &q) {
    double_t d=q.u*p.n;
    if (fabs(d)<EPS) throw "rownolegle";
    return (q.u*p.c+cross(p.n,q.w))/d;
}
// Prosta prostopadla do plaszczyzny przechodzaca przez punkt
line3 perp3(const xyz &a, const plane &p) {
    return line3(p.n, cross(a,p.n));
}
// Plaszczyzna prostopadla do prostej przechodzaca przez punkt
plane perp3(const xyz &a, const line3 &p) {
    return plane(p.u, p.u*a);
}
// Odleglosc punktu od prostej
double_t dist3(const xyz &a, const line3 &p)
{
    return sqrt((cross(a,p.u)-p.w).norm())/sqrt(p.u.norm());
}
// Odleglosc 2 prostych od siebie. Zalozenie: cross(q.u,p.u)!=0 (niestabilne
double_t dist3(const line3 &p, const line3 &q)    // przy bliskim 0)
{
    return fabs(p.u*q.w+q.u*p.w)/sqrt(cross(q.u,p.u).norm());
}

// GEOMETRIA SFER W 3D

// Bartosz Walczak

struct sphere {
    xyz c;
    double_t r; // srodek, promien
    sphere(const xyz &ci, double_t ri=0):c(ci), r(ri) {}
    sphere() {}
    double_t area() const {
        return 4*M_PI*r*r;    // pole powierzchni
    }
    double_t volume() const {
        return 4*M_PI*r*r*r/3;    // objetosc kuli
    }
};









// Czy punkt lezy na sferze?
bool on_sphere(const xyz &a, const sphere &s)
{
    return fabs((a-s.c).norm()-s.r*s.r)<EPS;
}
// Czy sfera/punkt lezy wewnatrz lub na brzegu kuli?
bool in_sphere(const sphere &a, const sphere &b)
{
    return b.r+EPS>a.r && (a.c-b.c).norm()<(b.r-a.r)*(b.r-a.r)+EPS;
}
// Przeciecie sfery i prostej. Zwraca liczbe punktow przeciecia
int intersection3(const sphere &s, const line3 &p, xyz I[]/*OUT*/) {
    double_t d=p.u.norm(), a=(cross(s.c,p.u)-p.w).norm()/(d*d), r=s.r*s.r/d;
    if (a>=r+EPS) return 0;
    xyz u=(p.u*(p.u*s.c)+cross(p.u,p.w))/d;
    if (a>r-EPS) {
        I[0]=u;
        return 1;
    }
    double_t h=sqrt(r-a);
    I[0]=u+p.u*h;
    I[1]=u-p.u*h;
    return 2;
}
/* Przeciecie sfery i plaszczyzny. Zwraca true, jesli sie przecinaja. Wtedy u,r
   sa odp. srodkiem i promieniem okregu przeciecia. Zalozenie: s1.c!=s2.c     */
bool intersection3(const sphere &s, const plane &p, xyz &u, double_t &r) {
    double_t d=p.n.norm(), a=(p.n*s.c-p.c)/d;
    u=s.c-p.n*a;
    a*=a;
    double_t r1=s.r*s.r/d;
    if (a>=r1+EPS) return false;
    r=a>r1-EPS ? 0 : sqrt(r1-a)*sqrt(d);
    return true;
}
/* Przeciecie dwoch sfer. Zwraca true, jesli sie przecinaja. Wtedy u,r sa
   odp. srodkiem i promieniem okregu przeciecia. Zalozenie: s1.c!=s2.c        */
bool intersection3(const sphere &s1, const sphere &s2, xyz &u, double_t &r) {
    double_t d=(s2.c-s1.c).norm(), r1=s1.r*s1.r/d, r2=s2.r*s2.r/d;
    u=s1.c*((r2-r1+1)*0.5)+s2.c*((r1-r2+1)*0.5);
    if (r1>r2) swap(r1,r2);
    double_t a=(r1-r2+1)*0.5;
    a*=a;
    if (a>=r1+EPS) return false;
    r=a>r1-EPS ? 0 : sqrt(r1-a)*sqrt(d);
    return true;
}

// GEOMETRIA NA SFERZE

// Bartosz Walczak

// Odleglosc dwoch punktow na sferze
double_t distS(const xyz &a, const xyz &b)
{
    return atan2(sqrt(cross(b,a).norm()), a*b);
}

struct circleS { // okrag na sferze
    xyz c;
    double_t r; // srodek, promien katowy
    circleS(const xyz &ci, double_t ri):c(ci), r(ri) {}
    circleS() {}
    double_t area() const {
        return 2*M_PI*(1-cos(r));    // pole kola
    }
};

// Okrag rozpiety przez 3 punkty. Zalozenie: punkty sa parami rozne
circleS spanS(xyz a, xyz b, xyz c) {
    int tmp=1;
    if ((a-b).norm() > (c-b).norm()) {
        swap(a, c);
        tmp=-tmp;
    }
    if ((b-c).norm() > (a-c).norm()) {
        swap(a, b);
        tmp=-tmp;
    }
    xyz v=cross(c-b,b-a);
    v=v*(tmp/sqrt(v.norm()));
    return circleS(v, distS(a,v));
}
// Przeciecie 2 okregow na sferze. Zalozenie: cross(c2.c,c1.c)!=0
int intersectionS(const circleS &c1, const circleS &c2, xyz I[]/*OUT*/) {
    xyz n=cross(c2.c,c1.c), w=c2.c*cos(c1.r)-c1.c*cos(c2.r);
    double_t d=n.norm(), a=w.norm()/d;
    if (a>=1+EPS) return 0;
    xyz u=cross(n,w)/d;
    if (a>1-EPS) {
        I[0]=u;
        return 1;
    }
    double_t h=sqrt(1-a)/sqrt(d);
    I[0]=u+n*h;
    I[1]=u-n*h;
    return 2;
}
